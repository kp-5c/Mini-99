#include "../includes/minishell.h"

int	pwd_builtin(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_putstr_fd("minishell: pwd: error retrieving current directory: ", 2);
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}