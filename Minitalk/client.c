/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:36:21 by root              #+#    #+#             */
/*   Updated: 2022/01/13 17:46:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./Libft/libft.h"

void my_handler()
{
    printf("El servidor ha recibido la frase completa.\n");
}

int main(int argc, char **argv)
{
    int pid;
    int i;
    char *msg;
    char *c;
    
    signal(SIGUSR1, my_handler);
   if (argc != 3)
   {
       printf("Los datos no se han introducido correctamente\n");
       return (0);
   }
    pid = ft_atoi(argv[1]);
    msg = argv[2];
    i = 0;
    send_integer(pid, ft_strlen(msg));
    send_integer(pid,getpid());
    while (msg[i] != '\0')
    {
        c = ft_tobinary((int)msg[i]);
        send_char(pid, c);
        free(c);
        i++;
    }
    return (0);
}
