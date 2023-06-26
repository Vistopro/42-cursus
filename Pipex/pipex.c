/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:39:25 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/22 18:28:24 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	free_arrays(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	ft_child1(char **argv, char **envp, int fd_infile, int pipefd[2])
{
	char	**paths;
	char	**cmd1;

	if (fd_infile >= 0)
	{
		cmd1 = ft_splitpipex(argv[2], ' ');
		paths = ft_paths(envp);
		dup2(fd_infile, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(fd_infile);
		if (ft_strnstr(cmd1[0], "awk", 3))
		{
			if (cmd1[1][0] == '\'')
				cmd1[1] = ft_strtrim(cmd1[1], "'");
			else
				cmd1[1] = ft_strtrim(cmd1[1], "\"");
		}
		ft_getcmd(argv[2], envp, paths, cmd1);
		free_arrays(cmd1);
		free_arrays(paths);
	}
	else
		exit(1);
}

void	ft_child2( char **argv, char **envp, int fd_outfile, int pipefd[2])
{
	char	**paths;
	char	**cmd2;

	cmd2 = ft_splitpipex(argv[3], ' ');
	paths = ft_paths(envp);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(pipefd[1]);
	close(fd_outfile);
	if (ft_strnstr(cmd2[0], "awk", 3))
	{
		if (cmd2[1][0] == '\'')
			cmd2[1] = ft_strtrim(cmd2[1], "'");
		else
			cmd2[1] = ft_strtrim(cmd2[1], "\"");
	}
	ft_getcmd(argv[3], envp, paths, cmd2);
	free_arrays(cmd2);
	free_arrays(paths);
}

void	ft_pipex(char **argv, char **envp)
{
	int		child_pid;
	int		fd_infile;
	int		fd_outfile;
	int		pipefd[2];

	fd_infile = open(argv[1], O_RDONLY);
	fd_outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	check_files(argv);
	if (pipe(pipefd) == -1)
	{
		perror("Error creating pipe");
		exit(1);
	}
	child_pid = fork();
	if (child_pid == 0)
		ft_child1(argv, envp, fd_infile, pipefd);
	ft_child2(argv, envp, fd_outfile, pipefd);
	exit(0);
}
