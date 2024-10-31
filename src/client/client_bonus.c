/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:10:52 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/31 11:01:20 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_ack_received_flag = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received_flag = 1;
}

void	send_bit(pid_t server_pid, int bit_value)
{
	int	signal;

	if (bit_value == 0)
		signal = SIGUSR1;
	if (bit_value == 1)
		signal = SIGUSR2;
	if (kill(server_pid, signal) == -1)
		error_handler(sending_signal_error);
	while (!g_ack_received_flag)
		usleep(400);
	g_ack_received_flag = 0;
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit_position;
	int	bit_value;

	bit_position = 8;
	while (bit_position--)
	{
		bit_value = (c >> bit_position) & 0x01;
		send_bit(server_pid, bit_value);
	}
}

void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		error_handler(wrong_usage_client);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 1)
		error_handler(invalid_pid);
	if (sigemptyset(&sa.sa_mask) == -1 \
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler(signal_mask_error);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler(sigaction_error);
	send_string(server_pid, argv[2]);
	return (0);
}
