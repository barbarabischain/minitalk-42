/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:26:37 by babischa          #+#    #+#             */
/*   Updated: 2024/06/26 12:16:43 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_message	g_msg = {0, 0};

void	signal_handler(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
		g_msg.c &= ~(1 << g_msg.i);
	else if (signal == SIGUSR2)
		g_msg.c |= (1 << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 8)
	{
		write(1, &g_msg.c, 1);
		g_msg.c = 0;
		g_msg.i = 0;
	}
	if (kill(siginfo->si_pid, SIGUSR1))
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	sign;

	sign.sa_sigaction = signal_handler;
	sign.sa_flags = SA_SIGINFO;
	ft_printf("*** BABISCHA'S SERVER ***\n");
	ft_printf("My server PID is: %d\n", getpid());
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
	while (TRUE)
		;
}
