/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:27:52 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/22 15:45:45 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	**ft_paths(char **envp);
char	*ft_join(char *path, char *cmd);
void	ft_pipex(char **argv, char **envp);
void	check_files(char **argv);
void	ft_getcmd(char *argv, char **envp, char **paths, char **cmdargs);
char	**ft_splitpipex(char const *str, char c);
void	free_arrays(char **arg);

#endif