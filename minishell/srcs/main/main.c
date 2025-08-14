#include "../includes/minishell.h"

int	g_signal_status = 0;

int main(int ac, char **av, char **envp)
{
    t_data  *data;

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
            break;
        }
        if (data->input)
            add_history(data-> input);
        free(data->input);
        write (1, "test\n", 5);
    }
    last_free();
    return (0);
}