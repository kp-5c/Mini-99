#include "../includes/minishell.h"

int env_builtin(void)
{
    t_env   *env;

    env = _data()->env_list;
    while (env)
    {
        printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
    return (0);
}