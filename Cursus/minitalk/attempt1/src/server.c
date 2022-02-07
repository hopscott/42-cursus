/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:35:50 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 19:50:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_str;

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_str = ft_strjoin(g_str, (unsigned char *)"0");
	if (signum == SIGUSR2)
		g_str = ft_strjoin(g_str, (unsigned char *)"1");
}

void	get_pidclient(int sig, siginfo_t *info, void *context)
{
	int	pidclient;

	(void) sig;
	(void) context;
	pidclient = info->si_pid;
	g_str = ft_strbase(pidclient, (unsigned char *)"0123456789");
}

int	init_handler(int pidclient)
{
	struct sigaction	sac;
	struct sigaction	sa;

	sigemptyset(&sac.sa_mask);
	sac.sa_flags = SA_SIGINFO;
	sac.sa_sigaction = get_pidclient;
	sigaction(SIGUSR1, &sac, NULL);
	pause();
	pidclient = ft_atoi(g_str);
	ft_printf("==== MESSAGE RECEIVED FROM CLIENT [%d] ====\n", pidclient);
	g_str = ft_strdup((unsigned char *)"");
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	return (pidclient);
}

int	main(void)
{
	int	pid;
	int	pidclient;

	pid = getpid();
	pidclient = -1;
	g_str = ft_strdup((unsigned char *)"");
	if (pid != 0)
	{
		ft_printf("PID: %d\n", pid);
		while (1)
		{
			if (pidclient <= 0)
				pidclient = init_handler(pid);
			kill(pidclient, SIGUSR1);
			if (check_eos(g_str))
			{
				ft_printf("%s\n", ft_bintostr(g_str));
				g_str = ft_strdup((unsigned char *)"");
				pidclient = 0;
			}
			usleep(50);
		}
	}
	return (0);
}
