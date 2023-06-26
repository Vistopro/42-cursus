/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:46 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/22 18:49:48 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	check_files(char **argv)
{
	if (access(argv[1], F_OK) != 0)
		ft_printf("zsh: no such file or directory: %s\n", argv[1]);
	else if (access(argv[1], R_OK) != 0)
	{
		ft_printf("zsh: permission denied: %s\n", argv[1]);
		exit(1);
	}
	if (access(argv[4], W_OK) != 0)
	{
		ft_printf("zsh: permission denied: %s\n", argv[4]);
		exit(1);
	}
}
