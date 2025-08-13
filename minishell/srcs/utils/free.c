#include "../../includes/minishell.h"

void    last_free(void)
{
    if (_data()->prompt)
    {
        free(_data()->prompt);
        _data()->prompt = NULL;
    }
    rl_clear_history();
}