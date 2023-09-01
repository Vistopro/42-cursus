/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:27:52 by vicrodri          #+#    #+#             */
/*   Updated: 2023/08/11 15:07:02 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct minishell
{
	char	**paths;
	char	**input;
	char	*cmd;
	int		child_pid;
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	int		i;
	int		i_fd_in;
	int		i_fd_out;
	int 	i_pipe;
	int		i_cmd;
}	t_minishell;


typedef struct command_list
{
	char	*cmd;
	char	**arg;
	char	*path;

	struct command_list	*next;
	struct command_list	*prev;

}	t_command_list;

typedef struct env_list
{
	char	*env;
	char	*value;
	struct env_list	*next;
	struct env_list	*prev;

}	t_env_list;



char	**ft_splitpipex(char const *str, char c);
void	ft_paths(t_minishell *minishell);
void	ft_getcmd(t_minishell *minishell);
void	free_arrays(char **arg);
void	ft_pipe(t_minishell *minishell);

#endif