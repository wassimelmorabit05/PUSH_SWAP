#include "push_swap.h"

static int	check_final(long long r)
{
	if (r > INT_MAX || r < INT_MIN)
		return (0);
	return (1);
}

static int	check_overflow(long long r, int digit)
{
	if (r > ((LLONG_MAX - digit) / 10))
		return (0);
	return (1);
}

static void	check_is_negative(char digit, int *i, int *sign)
{
	if (digit == '-' || digit == '+')
	{
		if (digit == '-')
			*sign = -1;
		(*i)++;
	}
}

static int	calculate_res(const char *str, int i, long long *r, int *err)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(*r, str[i] - '0') != 1)
			return (*err = 1, 0);
		*r = *r * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (*err = 1, 0);
	return (1);
}

int	ft_atoi_pushswap(char *str, int *error)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	*error = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	check_is_negative(str[i], &i, &sign);
	if (str[i] < '0' || str[i] > '9')
		return (*error = 1, 0);
	if (!calculate_res(str, i, &result, error))
		return (0);
	result *= sign;
	if (check_final(result) != 1)
		return (*error = 1, 0);
	return ((int)result);
}
