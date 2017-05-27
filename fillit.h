/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:49:21 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/26 15:38:27 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct		s_tetrimin
{
	char			*tetrimin;
	char			symbol;
	int				b;
}					t_tetrimin;

size_t				ft_validation(char *str);
t_tetrimin			**ft_generate_tetriminos(char *str, size_t count);
int					ft_putmap(char **map);
char				**ft_create_map(size_t size);
size_t				ft_min_mapsize(size_t count);
int					ft_magic(char **map, t_tetrimin **t, size_t size);
int					ft_mary(t_tetrimin **tet);

#endif
