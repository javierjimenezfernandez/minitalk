/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:09:40 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/29 17:29:17 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;
	static pid_t			client_pid = 0;

	(void)ucontext;
	if (client_pid != info->si_pid)
	{
		bit_count = 0;
		character = 0;
	}
	client_pid = info->si_pid;
	character = character << 1;
	if (signum == SIGUSR2)
		character = character | 0x01;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		error_handler(wrong_usage_server);
	if (sigemptyset(&sa.sa_mask) == -1 \
		|| sigaddset(&sa.sa_mask, SIGUSR1) == -1 \
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler(signal_mask_error);
	sa.sa_sigaction = &receive_bit;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 \
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler(sigaction_error);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
