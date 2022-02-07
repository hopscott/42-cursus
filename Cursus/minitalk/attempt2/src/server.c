/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:35:50 by swillis           #+#    #+#             */
/*   Updated: 2022/02/07 20:32:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_str;

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_str = ft_strjoin(g_str, (unsigned char *)"0");
		if (!g_str)
			return ;
	}
	if (signum == SIGUSR2)
	{
		g_str = ft_strjoin(g_str, (unsigned char *)"1");
		if (!g_str)
			return ;
	}
}

void	get_pidclient(int sig, siginfo_t *info, void *context)
{
	int	pidclient;

	(void) sig;
	(void) context;
	pidclient = info->si_pid;
	g_str = ft_strbase(pidclient, (unsigned char *)"0123456789");
	if (!g_str)
		return ;
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
	if (!g_str)
		return (-1);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	return (pidclient);
}

int	reset_newmsg(void)
{
	unsigned char	*s;

	s = ft_bintostr(g_str);
	if (!s)
		return (-1);
	ft_printf("%s\n", s);
	g_str = ft_strdup((unsigned char *)"");
	if (!g_str)
		return (-1);
	return (0);
}

int	main(void)
{
	int	pid;
	int	pidclient;

	pid = getpid();
	pidclient = 0;
	g_str = ft_strdup((unsigned char *)"");
	if (!g_str)
		return (-1);
	if (pid != 0)
	{
		ft_printf("PID: %d\n", pid);
		while (pidclient != -1)
		{
			if (pidclient == 0)
				pidclient = init_handler(pid);
			kill(pidclient, SIGUSR1);
			if (check_eos(g_str))
				pidclient = reset_newmsg();
			usleep(50);
		}
	}
	free(g_str);
	return (0);
}
