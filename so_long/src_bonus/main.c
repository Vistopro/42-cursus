/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:48:24 by vicrodri          #+#    #+#             */
/*   Updated: 2023/07/26 11:21:35 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_calc_rectangle(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{	
			if (map->map[i][j] == 'P')
				map->player++;
			if (map->map[i][j] == 'E')
				map->exit++;
			if (map->map[i][j] == 'C')
				map->collectible++;
			if (map->map[i][j] == 'P')
			{
				map->yplayer = i;
				map->xplayer = j;
			}
		}
	}
	map->height = i;
	map->width = j;
}

void	ft_init_map(t_map *map, char **argv)
{
	map->width = 0;
	map->height = 1;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->movements = 0;
	map->direction = 0;
}

int32_t	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error(ERROR_NO_ARGUMENTS);
	else
	{	
		ft_init_map(&map, argv);
		if (ft_map(argv, &map) && ft_check_map(argv, &map) == 1)
			ft_play(&map);
		ft_free(&map);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
