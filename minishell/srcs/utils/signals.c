#include "../../includes/minishell.h"

static void sigint_handler(int sig) 
{
    (void) sig;
	_data()->exit_code = 130;
	g_signal_status = 130;
	write(1, "\n", 1);
    rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler(int sig)
{
	if (sig == 0)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
    signal(SIGTSTP, SIG_IGN);
}