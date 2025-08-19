/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <dbhujoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:01:57 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/08/19 14:01:58 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern int	g_signal_status;

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <termcap.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	char	*input;
	char	*prompt;
	char	**env_tab;
	int		exit_code;
	t_env	*env_list;
}	t_data;

//ENV
t_env   *env_to_list(char **envp);
t_env	*env_to_node(char *env);
char    **env_to_array(t_env *env_list);
//UTILS
void    error_malloc(void);
t_data	*_data(void);
void    last_free(void);
void	signal_handler(int sig);
//BUILDINS
int	pwd_builtin(void);
int env_builtin(void);
#endif
