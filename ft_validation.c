/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:33:18 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/29 16:16:46 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_link(char *str, size_t i)
{
	int			link;

	link = 0;
	if (i < 18 && str[i + 1] == '#')
		link++;
	if (i != 0 && str[i - 1] == '#')
		link++;
	if (i < 14 && str[i + 5] == '#')
		link++;
	if (i > 4 && str[i - 5] == '#')
		link++;
	return (link);
}

int		ft_single_validation(char *str)
{
	int			link;
	size_t		i;
	size_t		diez_count;

	if (!str)
		return (0);
	link = 0;
	diez_count = 0;
	i = 0;
	while (i < 20)
	{
		if (((i + 1) % 5) == 0 && str[i] != '\n')
			return (0);
		if ((i + 1) % 5 != 0 && (str[i] != '#' && str[i] != '.'))
			return (0);
		if (str[i++] == '#' && ++diez_count)
			link += ft_count_link(str, i - 1);
		if (diez_count > 4)
			return (0);
	}
	if (diez_count < 4)
		return (0);
	if (link == 6 || link == 8)
		return (1);
	return (0);
}

size_t	ft_validation(char *str)
{
	size_t		count;
	size_t		len;
	size_t		n;

	count = 0;
	len = ft_strlen(str);
	n = 0;
	while (n < len)
	{
		if (count > 26)
			return (0);
		if (n > 0 && str[n++] != '\n')
			return (0);
		if (ft_single_validation(str + n) == 0)
			return (0);
		else
			count++;
		n += 20;
	}
	return (count);
}
