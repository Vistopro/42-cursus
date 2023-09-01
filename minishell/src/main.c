/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:17:26 by vicrodri          #+#    #+#             */
/*   Updated: 2023/08/11 14:51:50 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_minishell	minishell;

	minishell.envp = envp;
	minishell.i = 0;
	while (1)
	{
		input = readline("minishell$ ");
		add_history(input);
		if (ft_strncmp(ft_strtrim(input, " "), "exit", 4) == 0)
		{
			free(input);
			ft_printf("exit\n");
			return (0);
		}
		else
		{
			minishell.input = ft_splitpipex(input, ' ');
			while (minishell.input[minishell.i])
			{	
				if (ft_strncmp(minishell.input[minishell.i], "<", 2) == 0)
					minishell.i_fd_in = minishell.i + 1;
				if (ft_strncmp(minishell.input[minishell.i], "|", 2) == 0)
					minishell.i_pipe = minishell.i + 1;
				if (ft_strncmp(minishell.input[minishell.i], ">", 2) == 0)
					minishell.i_fd_out = minishell.i + 1;
				minishell.i++;
			}
			if (minishell.i_pipe && minishell.i_fd_in)
				ft_printf("Error: syntax error near unexpected token `|'\n");
			else
			{
				ft_paths(&minishell);
				minishell.child_pid = fork();
				if (minishell.child_pid == 0)
				{
					minishell.i_cmd = 0;
					ft_getcmd(&minishell);
					exit(0);
				}
				else
					wait(NULL);
				free_arrays(minishell.paths);
			}
			free(input);
			free_arrays(minishell.input);
		}
	}
	return (0);
}
