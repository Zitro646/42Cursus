/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:50:26 by root              #+#    #+#             */
/*   Updated: 2022/01/13 17:51:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void turn_into_char(char *str)
{
    int c;
    int i;
    int cont;
    
    i = 128;
    c = 0;
    cont = 0;
    while (cont < 8)
    {
        if (str[cont] == '1')
        {
            c += i;
        }
        cont++;
        i /= 2;
    }
    write (1 , &c , 1);
}

int turn_into_integer (char* str)
{
    int nbase;
    int naux;
    int cont;
    
    naux = 0;
    nbase = 1;
    cont = 31;
    while (cont > 0)
    {
        if (str[cont] == '1')
        {
            naux = naux + nbase;
        }
        nbase *= 2;
        cont--;
    }
    return(naux);
}