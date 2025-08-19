#include "../../includes/minishell.h"

void    error_malloc(void)
{
    last_free();
    perror("malloc error");
    exit(1);
}