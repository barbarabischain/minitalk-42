/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babischa <babischa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:42 by babischa          #+#    #+#             */
/*   Updated: 2024/06/26 12:36:52 by babischa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_handshake = FALSE;

void	signal_receive(int sign)
{
	if (sign == SIGUSR1)
		g_handshake = TRUE;
}

void	send_bit(int pid, char *str, size_t len)
{
	int		bit;
	size_t	i;

	i = 0;
	while (i < len)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit++;
			usleep(10000);
			while (!g_handshake)
				;
			g_handshake = FALSE;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sighandshake;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sighandshake.sa_handler = signal_receive;
		sighandshake.sa_flags = 0;
		sigemptyset(&sighandshake.sa_mask);
		sigaction(SIGUSR1, &sighandshake, NULL);
		send_bit(pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_printf("Wrong Format\n: server <PID> <Message>\n");
	return (0);
}
