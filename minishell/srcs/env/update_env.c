#include "../../includes/minishell.h"

void    update_env(void)
{
    char    *pwd;

    pwd = getcwd(NULL, 0);
    if (!pwd)
    {
        write(2, "minishell: pwd: No such file or directory\n", 43);
		pwd = ft_strdup("/");
        error_malloc();
	}
    
}