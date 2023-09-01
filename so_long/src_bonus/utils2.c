/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:48:27 by vicrodri          #+#    #+#             */
/*   Updated: 2023/09/01 14:08:59 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_delete_textures(t_map *map)
{
	mlx_delete_texture(map->player_t);
	mlx_delete_texture(map->playerizq_t);
	mlx_delete_texture(map->wall_t);
	mlx_delete_texture(map->exit_t);
	mlx_delete_texture(map->floor_t);
	mlx_delete_texture(map->collectible_t);
	mlx_delete_texture(map->enemy_t);
}

void	ft_play(t_map *map)
{
	map->mlx = mlx_init(map->width * 64, map->height * 64, "so_long", false);
	map->player_t = mlx_load_png("./images/piggy.png");
	map->player_i = mlx_texture_to_image(map->mlx, map->player_t);
	map->playerizq_t = mlx_load_png("./images/piggyizq.png");
	map->playerizq_i = mlx_texture_to_image(map->mlx, map->playerizq_t);
	map->wall_t = mlx_load_png("./images/wall.png");
	map->wall_i = mlx_texture_to_image(map->mlx, map->wall_t);
	map->exit_t = mlx_load_png("./images/bank.png");
	map->exit_i = mlx_texture_to_image(map->mlx, map->exit_t);
	map->floor_t = mlx_load_png("./images/floor.png");
	map->floor_i = mlx_texture_to_image(map->mlx, map->floor_t);
	map->collectible_t = mlx_load_png("./images/cash.png");
	map->collectible_i = mlx_texture_to_image(map->mlx, map->collectible_t);
	map->enemy_t = mlx_load_png("./images/enemy.png");
	map->enemy_i = mlx_texture_to_image(map->mlx, map->enemy_t);
	ft_delete_textures(map);
	ft_checkpath(map);
	ft_fillmap(map);
	mlx_key_hook(map->mlx, &hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}

void	ft_move2(t_map *map)
{
	if (map->map[map->newyplayer][map->newxplayer] == 'E'
		&& map->collectible == 0)
	{
		ft_putstr_fd("You win!\n", 1);
		ft_free(map);
		exit(0);
	}
	mlx_image_to_window(map->mlx, map->floor_i, map->xplayer * 64,
		map->yplayer * 64);
	ft_fillmap2(map);
}

void	ft_move(t_map *map)
{
	if (map->map[map->newyplayer][map->newxplayer] == 'C')
		map->collectible--;
	if (map->map[map->newyplayer][map->newxplayer] == 'L')
	{
		ft_putstr_fd("You lose!\n", 1);
		ft_free(map);
		exit(0);
	}
	if (map->map[map->newyplayer][map->newxplayer] == 'C'
		|| map->map[map->newyplayer][map->newxplayer] == '0')
	{
		mlx_image_to_window(map->mlx, map->wall_i, 0, 0);
		map->movements++;
		mlx_put_string(map->mlx, ft_itoa(map->movements), 20, 20);
		map->map[map->yplayer][map->xplayer] = '0';
		map->xplayer = map->newxplayer;
		map->yplayer = map->newyplayer;
		map->map[map->yplayer][map->xplayer] = 'P';
	}
	ft_move2(map);
}

void	ft_fillmap3(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		ft_img(map, map->wall_i, j, i);
	else if (map->map[i][j] == '0')
		ft_img(map, map->floor_i, j, i);
	else if (map->map[i][j] == 'C')
		ft_img(map, map->collectible_i, j, i);
	else if (map->map[i][j] == 'E')
		ft_img(map, map->exit_i, j, i);
	else if ((map->map[i][j] == 'P' && map->direction == 1)
	|| (map->map[i][j] == 'P' && map->map[i][j + 1] == '1'
		&& map->movements == 0))
		ft_img(map, map->player_i, map->xplayer, map->yplayer);
	else if (map->map[i][j] == 'P' && map->direction == 0)
		ft_img(map, map->playerizq_i, map->xplayer, map->yplayer);
	else if (map->map[i][j] == 'L')
	{
		ft_img(map, map->floor_i, j, i);
		ft_img(map, map->enemy_i, j, i);
	}
}
