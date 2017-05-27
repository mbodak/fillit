/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:25:46 by mbodak            #+#    #+#             */
/*   Updated: 2017/01/13 16:25:59 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_map;
size_t	g_size;

int		ft_clean(const size_t i, const ssize_t j, t_tetrimin *tet, const int k)
{
	size_t	a;
	ssize_t	b;
	int		c;

	a = i;
	b = j;
	c = 0;
	while (c < k || (k == -1 && tet->tetrimin[c]))
	{
		if (tet->tetrimin[c] == '#')
			g_map[a][b] = '.';
		b++;
		if (tet->tetrimin[c] == '\n')
		{
			b = j;
			a++;
		}
		c++;
	}
	tet->b = 0;
	return (1);
}

int		ft_full_validation(t_tetrimin *tet, size_t a, ssize_t b, int k)
{
	if (b < 0)
		return (1);
	if (!g_map[a])
		return (1);
	if (g_map[a][b] == '\0' && tet->tetrimin[k] != '\n')
		return (1);
	return (0);
}

int		ft_full(const size_t i, const ssize_t j, t_tetrimin *tet, int k)
{
	size_t	a;
	ssize_t	b;

	a = i;
	b = j;
	while (tet->tetrimin[k])
	{
		if (ft_full_validation(tet, a, b, k) && (ft_clean(i, j, tet, k)))
			return (0);
		if (tet->tetrimin[k] == '#')
		{
			if (g_map[a][b] != '.' && ft_clean(i, j, tet, k))
				return (0);
			g_map[a][b] = tet->symbol;
		}
		b++;
		if (tet->tetrimin[k++] == '\n' && ++a)
			b = j;
	}
	tet->b = 1;
	return (1);
}

int		ft_recursive(t_tetrimin **t, int index)
{
	size_t i;
	size_t j;

	if (t[index] == NULL || (i = 0))
	{
		ft_putmap(g_map);
		ft_putchar('\n');
		return (1);
	}
	while (g_map[i++])
	{
		j = 0;
		while (g_map[i - 1][j])
		{
			if (!(g_map[i - 1][j++] != '.' && t[index]->tetrimin[0] == '#'))
				if (ft_full(i - 1, j - 1, t[index], 0))
				{
					if (ft_recursive(t, index + 1))
						return (1);
					ft_clean(i - 1, j - 1, t[index], -1);
				}
		}
	}
	return (0);
}

int		ft_magic(char **map, t_tetrimin **t, size_t size)
{
	g_map = map;
	g_size = size;
	return (ft_recursive(t, 0));
}
