/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:13:39 by vicrodri          #+#    #+#             */
/*   Updated: 2023/09/01 14:10:46 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define ERROR_NO_ARGUMENTS "Error\nNo arguments\n"
# define ERROR_MAP "Error\nMap not valid\n"
# define ERROR_MAP_NOT_CLOSED  "Error\nMap not closed\n"
# define ERROR_MAP_NOT_RECTANGULAR "Error\nMap not rectangular\n"
# define ERROR_MAP_NOT_ACCESSIBLE "Error\nMap not accessible\n"
# define ERROR_MAP_NOT_PATH "Error\nPath not valid\n"

typedef struct map
{
	int				fd;
	int				width;
	int				height;
	int				player;
	int				exit;
	int				collectible;
	int				enemy;
	int				xplayer;
	int				yplayer;
	int				newxplayer;
	int				newyplayer;
	int				movements;
	int				direction;
	char			**map;
	char			**map_copy;
	mlx_t			*mlx;
	mlx_image_t		*player_i;
	mlx_image_t		*playerizq_i;
	mlx_image_t		*exit_i;
	mlx_image_t		*collectible_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*floor_i;
	mlx_image_t		*enemy_i;
	mlx_texture_t	*player_t;
	mlx_texture_t	*playerizq_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*collectible_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*enemy_t;
}	t_map;

void	ft_error(char *error);
void	hook(mlx_key_data_t key_data, void *param);
void	ft_play(t_map *map);
int		ft_check_map(char **argv, t_map *map);
int		ft_map(char **argv, t_map *map);
void	ft_fillmap(t_map *map);
void	ft_move(t_map *map);
void	ft_free(t_map *map);
void	ft_checkpath(t_map *map);
void	ft_fillmap2(t_map *map);
void	ft_calc_rectangle(t_map *map);
void	ft_fillmap3(t_map *map, int i, int j);
void	ft_img(t_map *map, mlx_image_t	*mlx_i, int j, int i);

#endif