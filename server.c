
#include "minitalk.h"

void	handle_signal(int sig)
{

	static char	s = 0;
	static int	bit = 0;
	if (sig == SIGUSR1)
	{
		s = (s << 1) | 1;
		bit++;
	}
	else if (sig == SIGUSR2)
	{
		s = (s << 1);
		bit++;
	}
	if (bit == 8)
	{
		write(1, &s, 1);
		s = 0;
		bit = 0;
	}
}
int	main(int argc, char *argv[])
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_putstr("server PID: ");
	ft_putstr(ft_itoa(getpid()));
	ft_putstr("\n");
	while (1)
	{
	}
	return (0);
}
