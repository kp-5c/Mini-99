#include "../../includes/minishell.h"

static int  ft_lstsize_env(t_env *env_list)
{
	int	i;

	i = 0;
	while (env_list)
	{
        if (env_list->key && env_list->value)
            i++;
        env_list = env_list->next;
	}
	return (i);
}

static char *array_line(t_env *env)
{
    char    *line;

    line = malloc(sizeof(char)* (ft_strlen(env->key) + ft_strlen(env->value)) + 2);
    if (!line)
        error_malloc();
    ft_strcpy(line, env->key);
    ft_strcat(line, "=");
    ft_strcat(line, env->value);
    return (line);
}

char    **env_to_array(t_env *env_list)
{
    char	**array;
	char	*line;
	int		size;
	int		i;

    i = 0;
	size = ft_lstsize_env(env_list);
	array = malloc(sizeof(char *) * (size + 1));
    if (!array)
		error_malloc();
    while(env_list)
    {
        if (env_list->key && env_list->value)
		{
			line = array_line(env_list);
			if (!line)
            {
                ft_free(array);
                error_malloc();
            }
			array[i++] = line;
		}
		env_list = env_list->next;
    }
    array[i] = NULL;
	return (array);
}