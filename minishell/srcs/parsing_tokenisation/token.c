#include "../includes/minishell.h"

t_tok *tok_new(t_tok type, char *lexeme, int quoted);
void     tok_push_back(t_token **head, t_token *node);
void     tok_free_all(t_token *head);

int tokenisation()
{
	ft_putchar_fd('\n', 1);
	return(0);
}