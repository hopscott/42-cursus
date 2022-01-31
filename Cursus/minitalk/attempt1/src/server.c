/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:35:50 by swillis           #+#    #+#             */
/*   Updated: 2022/01/31 20:07:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid == 0)
	{

	}
	else
	{
		ft_printf("PID: %d\n", pid);
		while (1)
		{

		}
	}
	return (0);
}
