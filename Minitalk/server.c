/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:19:24 by root              #+#    #+#             */
/*   Updated: 2022/01/13 23:59:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./Libft/libft.h"

t_server *server_data;

void server_reset(void)
{
    int i;

    i = 0;
    free(server_data->binary);
    server_data->binary = ft_calloc(sizeof(char),33);
    while (i < server_data->msg_len)
    {
        free(server_data->msg[i]);
        i++;
    }
    free(server_data->msg);
    server_data->client_pid = -1;
    server_data->msg_len = -1;
    server_data->counter = 0;
}

void intercept_number(int signum , int binary_len)
{
    if (signum == SIGUSR1)
        server_data->binary[binary_len] = '1';
    else if (signum == SIGUSR2)
        server_data->binary[binary_len] = '0';
    binary_len += 1;
    if (binary_len == 32)
    {
        if( server_data->msg_len == -1)
        {
            server_data->msg_len = turn_into_integer(server_data->binary);
             free(server_data->binary);
             server_data->binary = ft_calloc(sizeof(char),33);
       }
        else
        {
            server_data->client_pid = turn_into_integer(server_data->binary);
            free(server_data->binary);
            server_data->binary = ft_calloc(sizeof(char),9);
            server_data->msg = ft_calloc(sizeof(char *),server_data->msg_len + 1);
        }
    }
}

void intercept_char(int signum , int binary_len)
{
    if (signum == SIGUSR1)
    {
        server_data->binary[binary_len] = '1';
    }
    else if (signum == SIGUSR2)
    {
        server_data->binary[binary_len] = '0';
    }
    binary_len++;
    if (binary_len == 8)
    {
        server_data->msg[server_data->counter] = server_data->binary;
        server_data->counter++;
        server_data->binary = ft_calloc(sizeof(char),9);
    }
}

void my_handler(int signum)
{
    int binary_len;
    int i;

    i = 0;
    binary_len = ft_strlen(server_data->binary);
    if(server_data->msg_len == -1 || server_data->client_pid == -1)
    {
        intercept_number(signum, binary_len);
    }
    else if (server_data->counter != server_data->msg_len)
    {
        intercept_char(signum, binary_len);
    }
    if(server_data->counter == server_data->msg_len)
    {   
        while (i < server_data->msg_len)
        {
            turn_into_char(server_data->msg[i]);
            i++;
        }
        write(1, "\n", 1);
        kill(server_data->client_pid,SIGUSR1);
        server_reset();
    }
}

int main(void)
{
    server_data = ft_calloc(sizeof(t_server),1);
    server_data->pid = getpid();
    server_data->msg_len = -1;
    server_data->client_pid = -1;
    server_data->counter = 0;
    server_data->binary = ft_calloc(sizeof(char),33);
    printf("Server PID  : %i\n", server_data->pid);
    signal(SIGUSR1, my_handler);
    signal(SIGUSR2, my_handler);
    while (1);
    return (0);
}