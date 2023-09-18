/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:32:08 by vicrodri          #+#    #+#             */
/*   Updated: 2023/09/18 13:25:01 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"



void ft_token_add_back(t_token **token, t_token *new)
{
	t_token *aux;


	if (!new)
		return ;
	if (!*token)
	{
		*token = new;
		return ;
	}
	aux = *token;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
	printf("aux->next->str = %s\n", aux->next->str);
}

t_token	*new_token(t_token *token, char	*input)
{
	t_token	*new;
	
	new = ft_calloc(1, sizeof(t_token));
	new->str = ft_strdup(input);
	new->next = NULL;

	return (token);
}


t_lexer	*ft_tokenizer(char *input, t_minishell *minishell)
{
    t_lexer	*lexer;
	int i;

	i = 0;
	if (input == NULL || ft_strlen(input) == 0)
		return (0);
	lexer = ft_calloc(1, sizeof(t_lexer));
	lexer->error = 0;
	minishell->input = ft_splitpipex(input, ' ');
	while (minishell->input[i])
	{
		ft_token_add_back(&lexer->token_list, new_token(lexer->token_list, minishell->input[i]));
		printf("lexer->token_list->str = %s\n", lexer->token_list->str);
		i++;
	}
    return (lexer);
}