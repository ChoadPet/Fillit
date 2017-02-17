/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:42:00 by vpoltave          #+#    #+#             */
/*   Updated: 2017/02/17 13:16:34 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		buff[546];
	int			fd;
	int			i;
	int			m_size;
	t_tetra		*tetra;

	i = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == (-1))
			return (-1);
		while (read(fd, buff + i, 1))
			i++;
		buff[i] = '\0';
		if (!chck_map_m(buff) || !chck_map(buff) || !(tetra = fill_coord(buff)))
		{
			write(1, "error\n", 6);
			return (-2);
		}
		m_size = map_size(buff);
		fill_tetra(m_size, tetra);
		return (0);
	}
	else
		write(1, "usage: ./fillit source_file\n", 28);
}
