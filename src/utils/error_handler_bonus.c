/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:12:40 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/31 11:05:37 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	error_handler(t_error_type error_type)
{
	if (error_type == wrong_usage_server)
		ft_putstr_fd("Wrong usage. Please try: ./server\n", 2);
	else if (error_type == wrong_usage_client)
		ft_putstr_fd("Wrong usage. Please try: ./client [PID] [MESSAGE]\n", 2);
	else if (error_type == invalid_pid)
		ft_putstr_fd("Invalid PID. Only PID > 1 allowed.\n", 2);
	else if (error_type == signal_mask_error)
		ft_putstr_fd("Signal mask error.\n", 2);
	else if (error_type == sigaction_error)
		ft_putstr_fd("Sigaction error.\n", 2);
	else if (error_type == sending_signal_error)
		ft_putstr_fd("Sending signal error. Verify PID.\n", 2);
	exit (EXIT_FAILURE);
}
