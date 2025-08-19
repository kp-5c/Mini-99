
#include "../includes/minishell.h"

static int	ft_parsing_quote(char *input, int i)
{
	int	count;

	count = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
			count++;
		if (input[i] == '(' && (input[i + 1] == ')' || input[i + 1] == '|'
				|| input[i + 1] == '&' || input[i + 1] == ';' || input[i
				+ 1] == '\0'))
			return (0);
		if (input[i] == ')' && (input[i - 1] == '|' || input[i - 1] == '&'
				|| input[i - 1] == ';'))
			return (0);
		if ((input[i] == '<' && input[i + 1] == '>') || (input[i] == '>'
				&& input[i - 1] == '|'))
			return (0);
		if ((input[i] == '>' && input[i + 1] == '<') || ((input[i] == '<'
					|| input[i] == '>') && input[i + 1] == '|'))
			return (0);
		i++;
	}
	if ((count == 0) || (count > 0 && (count & 1) == 0))
		return (1);
	return (0);
}
int ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
static int	ft_parsing_eof(char *input, int i)
{
	if (input[i] == '|' || input[i] == '&')
		return (0);
	while (input[i])
		i++;
	if (input[i] == '\0')
		i--;
	if ((input[i] == '|') || (input[i] == '&' && input[i - 1] == '&')
		|| input[i] == '<' || input[i] == '>')
		return (0);
	else
		return (1);
}

static char	*ft_skip_space(char *str)
{
	size_t	i;
	size_t	j;
	char	*input;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	input = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!input)
		return (NULL);
	while (str[i])
	{
		while (isspace((unsigned char)str[i]))
			i++;
		if (!str[i])
			break ;
		input[j++] = str[i++];
	}
	input[j] = '\0';
	return (input);
}

static char	*ft_parsing_close(char *str, int i)
{
	int	a;
	int b;

	a = 0;
	b = 0;
	while (str[i])
	{
		if (b > a)
			return (NULL);
		if (str[i] == '(')
			a++;
		if (str[i] == ')')
			b++;
		i++;
	}
	if (a != b)
		return (NULL);
	return (str);
}

char	*parsing(char *str)
{
	int		i;
	int		r;
	char	*input;

	r = 1;
	i = 0;
	input = ft_skip_space(str);
	if (!ft_parsing_quote(input, i))
		r = 0;
	if (!ft_parsing_eof(input, i))
		r = 0;
	if (!ft_parsing_close(input, i))
		r = 0;
	free(input);
	if (r == 0)
		return (NULL);
	return (str);
}
