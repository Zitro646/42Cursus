/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:01:03 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/21 07:54:59 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
static	int	*ft_createchunk(int *oldchunk, int nbr);
static	int	*ft_deletechunk(int *oldchunk);
static void	check_chunk(int *chunk);

int	*ft_manage_chunks(int *oldchunk, int nbr, int command)
{
	//printf("Management of chunks type : %i\n",command);
	if (command == 1)
	{
		oldchunk = ft_createchunk(oldchunk, nbr);
		return (oldchunk);
	}
	else if (command == 2)
	{
		oldchunk = ft_deletechunk(oldchunk);
		return (oldchunk);
	}
	return (0);
	check_chunk(oldchunk);
}

static	int	*ft_createchunk(int *oldchunk, int nbr)
{
	int	*newchunk;
	int	i;

	i = 0;
	newchunk = ft_calloc(sizeof(int), (ft_count_list(oldchunk) + 2));
	//printf("Creamos un nuevo chunk\n");
	//printf("New chunk size : %i\n",(ft_count_list(oldchunk) + 2));
	if (oldchunk == 0)
	{
		newchunk[0] = nbr;
		//printf("Chunk[0] = %i\n",newchunk[0]);
	}
	else
	{
		while (oldchunk[i] != 0)
		{
			newchunk[i] = oldchunk[i];
			//printf("Chunk[%i] = %i\n", i, newchunk[i]);
			i++;
		}
		if (*oldchunk != 0)
			free(oldchunk);
		newchunk[i] = nbr;
	}
	return (newchunk);
}

static	int	*ft_deletechunk(int *oldchunk)
{
	int	*newchunk;
	int	i;

	if (oldchunk == 0)
	{
		free(oldchunk);
		return (0);
	}
	i = 0;
	newchunk = ft_calloc(sizeof(int), (ft_count_list(oldchunk) + 2));
	while (oldchunk[i] != 0)
	{
		newchunk[i] = oldchunk[i];
		i++;
	}
	free(oldchunk);
	return (newchunk);
}

static void	check_chunk(int *chunk)
{
	int	i;

	i = 0;
	printf("- - - CHUNK - - -\n");
	while (chunk[i] != 0)
	{
		printf("Chunk[%i] == %i\n", i, chunk[i]);
		i++;
	}
	printf("- - - - - - - - -\n");
}
