/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:27:28 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/22 17:22:56 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

char	**ft_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	paths = ft_calloc(ft_strlen(envp[i] + 5), sizeof(char));
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
	{
		write(2, "Error: PATH not found\n", 22);
		exit(1);
	}
	return (paths);
}

char	*ft_join(char *path, char *cmd)
{
	char	*tmp;
	char	*tmp2;
	char	**tmp3;

	tmp = ft_strjoin(path, "/");
	tmp3 = ft_split(cmd, ' ');
	tmp2 = ft_strjoin(tmp, tmp3[0]);
	free_arrays(tmp3);
	free(tmp);
	return (tmp2);
}

void	ft_getcmd(char *argv, char **envp, char **paths, char **cmdargs)
{
	int		i;
	char	*cmd;

	i = -1;
	while (paths[++i])
	{
		if (argv[0] == '/' || argv[0] == '.')
			cmd = ft_strdup(argv);
		else
			cmd = ft_join(paths[i], argv);
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, cmdargs, envp);
			break ;
		}
		free(cmd);
	}
	write(2, "zsh: command not found: ", 24);
	write(2, argv, ft_strlen(argv));
	write(2, "\n", 1);
	exit(127);
}
