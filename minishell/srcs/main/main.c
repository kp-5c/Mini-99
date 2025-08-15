#include "../includes/minishell.h"

int	g_signal_status = 0;

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	//int fd = open("text.txt", O_RDONLY);
	//char buffer[120];

	data = _data();
	ac = 0;
	av = NULL;
	envp = NULL;
	while (1)
	{
		read_history("text.txt");
		data->input = readline("minishell$ ");
		write_history("text.txt");
		if (!data->input)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		if (data->input)
		{
			add_history(data->input);
			if (!parsing(data->input))
				write(2, "bad command line\n", 18);
		}
		write_history("text.txt");
		clear_history();
		free(data->input);
	}
	last_free();
	return (0);
}
