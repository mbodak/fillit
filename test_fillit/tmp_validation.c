/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:33:18 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/26 19:17:46 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validation(char *str)
{
	size_t		i;
	size_t		diez_count;

	if (!str)
		return (0);
	diez_count = 0;
	i = 0;
	while (str[i] && i < 20)
	{
		if (((i + 1) % 5) != 0 && str[i] != '.' && str[i] != '#')
			return (0);
		if (((i + 1) % 5) == 0 && (str[i]) != '\n')
			return (0);
		if (str[i] == '#')
		{
			diez_count++;
			if (str[i + 1] != '#' 
					&& (i > 14 || str[i + 5] != '#') 
					&& (i == 0 || str[i - 1] != '#') 
					&& diez_count != 4)
				return (0);
			if (diez_count == 4
					&& (i < 4 || str[i - 5] != '#')
					&& (str[i - 1] != '#'))
				return (0);
		}
		if (i > 15 && diez_count == 0)
			return (0);
		if (diez_count > 4)
			return (0);
		i++;
	}
	if (diez_count < 4)
		return (0);
	return (1);
}
