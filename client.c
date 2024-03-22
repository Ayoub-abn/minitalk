/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:29:07 by aabdenou          #+#    #+#             */
/*   Updated: 2024/03/22 16:45:29 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char c, pid_t server_pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		usleep(150);
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	long int	server_pid;
	char		*str;
	int			i;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		str = argv[2];
		if (server_pid <= 0 || server_pid > 2147483647
			|| ft_strlen(argv[1]) > 12)
		{
			ft_putstr("PID Invalid");
			exit(1);
		}
		i = 0;
		while (str[i])
		{
			send_bit(str[i], server_pid);
			i++;
		}
		send_bit(str[i], server_pid);
	}
	else
		ft_putstr("problem with the number of arg (PID or message)");
	exit(1);
	return (0);
}
