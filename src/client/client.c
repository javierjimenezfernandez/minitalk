/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:10:52 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/29 10:55:09 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t server_pid, int bit_value)
{
	if (bit_value == 0)
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Sending signal error.\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("Sending signal error.\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	usleep(100);
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
	usleep(200);
}

void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	send_char(server_pid, '\n');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong usage. Please try: ./client [PID] [MESSAGE]\n", 2);
		exit (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Invalid PID.\n", 2);
		exit (EXIT_FAILURE);
	}
	send_string(server_pid, argv[2]);
	return (0);
}
