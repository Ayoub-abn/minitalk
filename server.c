/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:28:57 by aabdenou          #+#    #+#             */
/*   Updated: 2024/03/19 21:06:11 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static char	s;
	static int	bit;

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

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_putstr("server PID: ");
	ft_putstr(pid);
	free(pid);
	ft_putstr("\n");
	while (1)
	{
	}
	return (0);
}
