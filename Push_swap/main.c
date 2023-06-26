/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:33:39 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 15:26:02 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

long int	ft_int_sup(char *str)
{
	long int	i;
	long int	num;
	long int	signo;

	num = 0;
	i = 0;
	signo = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num) * 10 + (str[i] - '0');
		i++;
	}
	if (num * signo > INT_MAX || num * signo < INT_MIN)
		return (0);
	return (1);
}

int	ft_check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(s) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			i = 0;
			if (argv[0] == NULL)
				return (ft_print_error(), 0);
		}
		while (argv[i] != NULL)
		{
			if (ft_isnumber(argv[i]) == 0 || ft_int_sup(argv[i]) == 0
				|| ft_check_duplicate(argv) == 0)
				ft_print_error();
			i++;
		}
		push_swap(argv, argc);
	}
	else
	{
		return (0);
	}	
}
