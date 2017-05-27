/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:58:04 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/29 15:15:42 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fillit.h"

void	usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	size_t		count;
	int			fd;
	char		*fd_str;
	size_t		map_size;
	t_tetrimin	**tet;

	if (argc != 2)
		usage();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		usage();
	fd_str = ft_readfd(fd);
	close(fd);
	count = ft_validation(fd_str);
	if (!count)
	{
		ft_putstr("error\n");
		return (0);
	}
	tet = ft_generate_tetriminos(fd_str, count);
	map_size = ft_min_mapsize(count);
	while ((ft_magic(ft_create_map(map_size), tet, map_size)) == 0)
		map_size++;

	return (0);
}