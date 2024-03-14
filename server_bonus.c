/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:28:50 by aabdenou          #+#    #+#             */
/*   Updated: 2024/03/14 21:51:23 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void* str)
{

	static char	s = 0;
	static int	bit = 0;

    (void) str;
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
		if (s == '\0') {
            kill(info->si_pid,SIGUSR1 );
        }
		else
    	{
			write(1, &s, 1);
    		s = 0;
    		bit = 0;
		}
	}
	

}
int	main()
{
    struct sigaction sa;
    
    sa.sa_flags = SA_SIGINFO; 
    sa.sa_sigaction = handle_signal;
	
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL))
    {
        ft_putstr("error sigaction");
        exit(1);
    }
    
	ft_putstr("server PID: ");
	ft_putstr(ft_itoa(getpid()));
	ft_putstr("\n");
	while (1)
	{
	}
	return (0);
}