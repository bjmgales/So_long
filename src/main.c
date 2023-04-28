/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:30:43 by bgales            #+#    #+#             */
/*   Updated: 2023/04/28 18:22:13 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
