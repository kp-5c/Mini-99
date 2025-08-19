#include "../includes/minishell.h"

int	g_signal_status = 0;

static void  main_init(char **envp)
{
    _data()->env_list = env_to_list(envp);
    _data()->env_tab = env_to_array(_data()->env_list);
    if (env_builtin())
        return ;
    write (1,"\n",1);
    int i = 0;
    while (_data()->env_tab[i])
    {
        printf("%s\n", _data()->env_tab[i]);
        i++;
    }
    signal_handler(0);
}

static void    free_loop(void)
{
    t_data  *data;

    data = _data();
    //update_env();
    free(data->input);
    data->input = NULL;
    ft_free(data->env_tab);
    data->env_tab = env_to_array(data->env_list);

}

static int  main_loop(void)
{
    _data()->input = readline("minishell$ ");
    if (!_data()->input)
    {
        write(STDOUT_FILENO, "exit\n", 5);
        return (0);
    }
    if (_data()->input)
        add_history(_data()-> input);
     
    free_loop();
    write (1, "test\n", 5);
    return (1);
}

int main(int ac, char **av, char **envp)
{
    (void)(ac);
	(void)(av);
    
    if (pwd_builtin())
        return (1);
    main_init(envp);
    while (1)
    {
        if (!main_loop())
            break;
    }
    last_free();
    return (0);
}