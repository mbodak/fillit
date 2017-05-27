/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:24:02 by mbodak            #+#    #+#             */
/*   Updated: 2017/01/13 16:24:12 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(size_t size)
{
	char	**map;
	size_t	i;
	size_t	j;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		ft_putmap(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
	return (1);
}

size_t	ft_min_mapsize(size_t count)
{
	size_t	t_space;
	size_t	map_size;

	t_space = count * 4;
	map_size = 2;
	while ((map_size * map_size) < t_space)
	{
		map_size++;
	}
	return (map_size);
}
