#include "minitalk.h"
void	ft_putstr(char *s)
{
	int	i = 0;
	while (s[i])
		i++;

	if (s == NULL)
		return ;
	write(1, s, i);
}