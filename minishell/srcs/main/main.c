#include "../includes/minishell.h"

int	g_signal_status = 0;

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	data = _data();
	ac = 0;
	av = NULL;
	envp = NULL;
	while (1)
	{
		data->input = readline("minishell$ ");
		if (!data->input)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		if (data->input)
		{
			add_history(data->input);
			if (!parsing(data->input))
				write(2, "unexpected EOF while looking for matching quote”\n", 52);
			tokenisation();
		}
		free(data->input);
	}
	clear_history();
	last_free();
	return (0);
}
