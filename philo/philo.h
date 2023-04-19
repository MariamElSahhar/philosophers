/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:50:58 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/19 15:51:10 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "../include/ft_printf.h"
#include <pthread.h>

typedef struct {
	int philo_id;
	pthread_mutex_t *eat_mutex;
	pthread_mutex_t *fork1;
	pthread_mutex_t *fork2;
} t_args;

#endif
