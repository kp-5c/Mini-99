#include "../../includes/minishell.h"

static void sigint_handler(int sig) 
{
    (void) sig;
    write(STDOUT_FILENO, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}