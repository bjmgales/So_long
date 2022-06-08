/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:30:43 by bgales            #+#    #+#             */
/*   Updated: 2022/06/02 14:26:41 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_y(const char *map_path)
{
	char	*test;
	int		fd;
	int		ret;

	ret = 0;
	fd = open(map_path, O_RDONLY);
	test = get_next_line(fd);
	while (test)
	{
		ret++;
		free (test);
		test = get_next_line(fd);
	}
	free (test);
	return (ret);
}

void	ft_init(t_chars *z)
{
	z->p = 0;
	z->c = 0;
	z->e = 0;
	z->i = 0;
	z->line = -1;
}

void	ber_check(const char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] != 'r' || map[i - 2] != 'e' || map[i - 3] != 'b'
		|| map[i - 4] != '.')
		print_and_exit("Missing \".ber\" in map file\n");
	return ;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_and_exit("Arguments number is different than one\n");
		return (0);
	}
	ber_check(argv[1]);
	so_long(argv[1]);
}
