#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*str;
	int		bit;
	int		i;

	if (argc == 3)
	{
		server_pid = atoi(argv[1]);
		str = argv[2];
		bit = 7;
		i = 0;
		while (str[i])
		{
			while (bit >= 0)
			{
				
				if ((str[i] >> bit) & 1)
					kill(server_pid, SIGUSR1);
				else
					kill(server_pid, SIGUSR2);
				usleep(400);
				bit--;
			}
			i++;
			bit = 7;
		}
	}
	else
		ft_putstr("problem with the number of arg (PID or message)");
	exit(1);
	return (0);
}
