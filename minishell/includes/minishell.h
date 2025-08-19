/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:01:57 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/08/19 14:36:04 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern int			g_signal_status;

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_data
{
	char			*input;
	char			*prompt;
	int				exit_status;
}					t_data;

typedef enum e_token_type
{
	t_word,
	t_pipe,      /* | */
	t_redir_in,  /* < */
	t_redir_out, /* > */
	t_append,    /* >> */
	t_heredoc,   /* << */
	t_and_if,    /* && */
	t_or,     /* || */
	t_lparen,    /* (*/
	t_rparen,    /* )*/
} t_tokentype;

typedef struct s_tok
{
	t_tokentype		type;
	char *raw; /* pour t_word . Sinon NULL */
	int quoted;    // 1 si le WORD provenait de quotes simples (utile pour heredoc)
	struct s_tok	*next;
} t_tok;

t_tok *tok_new(t_tok type, char *lexeme, int quoted);
void     tok_push_back(t_token **head, t_token *node);
void     tok_free_all(t_token *head);

// UTILS
t_data				*_data(void);
void				last_free(void);
char				*parsing(char *input);
int					tokenisation(void);

#endif
