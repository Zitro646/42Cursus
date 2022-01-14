/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:19:47 by root              #+#    #+#             */
/*   Updated: 2022/01/13 17:57:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./Libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

typedef struct server
{
    int pid;
    int client_pid;
    int msg_len;
    int counter;
    char **msg;
    char *binary;
    
}t_server;

char *ft_tobinary(int nbr);
void send_char (int pid ,char *binary);
void send_integer (int pid ,int nbr);

void turn_into_char(char *str);
int turn_into_integer (char* str);

#endif