/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:39:30 by root              #+#    #+#             */
/*   Updated: 2022/01/13 17:56:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *ft_tobinary(int nbr)
{
    int nbase;
    int cont;
    char    *binary;
    
    binary = ft_calloc(sizeof(char),9);
    nbase = 128;
    cont = 0;
    while (cont < 8)
    {
        if (nbr / nbase > 0)
        {
            binary[cont] = '1';
            nbr -= nbase;
        }
        else
            binary[cont] = '0';
        nbase /= 2;
        cont++;
    }
    return (binary);
}

void send_char (int pid ,char *binary)
{
    int i;

    i = 0;
    while (binary[i] != '\0')
    {
        if (binary[i] == '1')
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(2500);
        i++;
    }
}

void send_integer (int pid ,int nbr)
{
    unsigned int nbase;
    unsigned int naux;
    int cont;
    
    nbase = 2147483648;
    naux = (unsigned int)nbr;
    cont = 0;
    while (cont < 32)
    {
        if (naux / nbase > 0)
        {
            kill(pid, SIGUSR1);
            naux = naux - nbase;
        }
        else
            kill(pid, SIGUSR2);
        nbase /= 2;
        cont++;
        usleep(2500);
    }
}