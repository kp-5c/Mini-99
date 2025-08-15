
#include "../includes/minishell.h"

static int	ft_parsing_quote(char *input, int i)
{
	int	count;

	count = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
			count++;
		if(input[i] == '(' && input[i + 1] == ')')
			return(0);
		i++;
	}
	if ((count == 0) || (count > 0 && (count & 1) == 0))
		return (1);
	else
		return (0);
}
static int	ft_parsing_eof(char *input, int i)
{
	while (input[i])
		i++;
	while (input[i] == '\0' || (input[i] <= 9 && input[i] <= 13)
		|| input[i] == 32)
		i--;
	if ((input[i] == '|') || (input[i] == '&' && input[i - 1] == '&')
		|| input[i] == '<' || input[i] == '>')
		return(0);
	else
		return(1);
}
/*static int ft_parsing_operateur(char *input)
{
	int i;

	i = 0;
	while(input[i])
	{

	}
}*/

char	*parsing(char *input)
{
	int i;

	i = 0;
	if (!ft_parsing_quote(input, i))
		return (NULL);
	// if(!ft_parsing_operateur(input))
	// return(NULL);
	if (!ft_parsing_eof(input, i))
		return (NULL);
	return (input);
}