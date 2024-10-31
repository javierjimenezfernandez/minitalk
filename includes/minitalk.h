/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:10:55 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/29 17:23:33 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum e_error_type
{
	wrong_usage_server,
	wrong_usage_client,
	invalid_pid,
	signal_mask_error,
	sigaction_error,
	sending_signal_error
}		t_error_type;

/* ****************** */
/*       SERVER       */
/* ****************** */
void	receive_bit(int signum, siginfo_t *info, void *ucontext);

/* ****************** */
/*       CLIENT       */
/* ****************** */
void	send_bit(pid_t server_pid, int bit_value);
void	send_char(pid_t server_pid, unsigned char c);
void	send_string(pid_t server_pid, char *str);

/* ****************** */
/*       UTILS        */
/* ****************** */
void	error_handler(t_error_type error_type);

#endif
