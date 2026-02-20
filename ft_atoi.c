int	ft_atoi(char *str, int *er)
{
	int i;
	int result;
	int sing;

	i = 0;
	result = 0;
	sing = -1;
	if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sing *= -1;
			i++;
		}
	if (str[i] < '0' || str[i] > '9')
		return (*er = 1, 0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sing);
}