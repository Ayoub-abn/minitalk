
int	ft_atoi(const char *str)
{
	int					i;
	int					sin;
	unsigned long long	rus;

	i = 0;
	sin = 1;
	rus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sin = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		rus = rus * 10 + (str[i] - '0');
		i++;
	}
	return (rus * sin);
}