/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:10:55 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/29 16:53:31 by javjimen         ###   ########.fr       */
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

#endif
