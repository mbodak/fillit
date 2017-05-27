/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:24:53 by mbodak            #+#    #+#             */
/*   Updated: 2017/01/13 16:24:58 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 		ft_mary(t_tetrimin **tet)
{
	int	i;

	i = 0;
	while (tet[i])
	{
		if (tet[i]->b == 0)
			return (0);
		i++;
	}
	return (1);
}

char		*ft_cut(char *str, int k, int n)
{
	int i;

	i = 0;
	while (i < (k * 4))
	{
		if ((str[i] != '#' && str[i + n] != '#' && str[i + (n * 2)] != '#')
			&& (str[i + (n * 3)] != '#'))
		{
			str[i] = ' ';
			str[i + n] = ' ';
			str[i + (n * 2)] = ' ';
			str[i + (n * 3)] = ' ';
			if (n < 2)
				str[i + (n * 4)] = ' ';
		}
		i += k;
	}
	return (str);
}

char		*ft_move_tetrimin(char *str)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc(sizeof(char) * 9);
	str = ft_cut(str, 1, 5);
	str = ft_cut(str, 5, 1);
	i = 0;
	j = 0;
	while (str[i] && i < 20)
	{
		if (str[i] != ' ')
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

t_tetrimin	**ft_generate_tetriminos(char *str, size_t count)
{
	char		symbol;
	t_tetrimin	**res;
	size_t		i;
	int			j;
	size_t		len;

	res = (t_tetrimin **)malloc(sizeof(t_tetrimin *) * (count + 1));
	len = ft_strlen(str);
	symbol = 'A';
	j = 0;
	i = 0;
	while (i < len)
	{
		if (i < len)
		{
			res[j] = (t_tetrimin *)malloc(sizeof(t_tetrimin));
			res[j]->tetrimin = ft_move_tetrimin(str + i);
			res[j]->symbol = symbol++;
			res[j++]->b = 0;
		}
		i += 21;
	}
	res[j] = NULL;
	return (res);
}
