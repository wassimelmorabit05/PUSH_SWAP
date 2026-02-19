#include "push_swap.h"

int	is_empty(char *s)
{
	int	i = 0;

	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	check_is_num(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (!args[i][j])
			return (0);
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	*process(char *str, char *arg)
{
	char	**split_args;
	char	*tmp;
	int		j;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (NULL);
	j = 0;
	while (split_args[j])
	{
		tmp = ft_strjoin(str, split_args[j]);
		free(str);
		if (!tmp)
			return (free_split(split_args), NULL);
		str = tmp;

		tmp = ft_strjoin(str, " ");
		free(str);
		if (!tmp)
			return (free_split(split_args), NULL);
		str = tmp;
		j++;
	}
	free_split(split_args);
	return (str);
}

char	**check_args(int ac, char **av)
{
	char	**split_args;
	char	*str;
	int		i;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (is_empty(av[i]))
			return (free(str), NULL);
		str = process(str, av[i]);
		if (!str)
			return (NULL);
		i++;
	}
	split_args = ft_split(str, ' ');
	free(str);
	return (split_args);
}
