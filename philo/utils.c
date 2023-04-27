/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:48:18 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/27 13:14:53 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_stamp(struct timeval start)
{
	struct timeval	curr_time;
	int				time_stamp;

	gettimeofday(&curr_time, 0);
	time_stamp = (curr_time.tv_sec - start.tv_sec) * 1000;
	time_stamp += (curr_time.tv_usec - start.tv_usec) / 1000;
	return (time_stamp);
}

int	times_up(struct timeval start, t_philo *philo, int dur)
{
	struct timeval	curr_time;
	int				lapsed;
	int				time_up;

	pthread_mutex_lock(&philo->args->m_timer);
	time_up = 0;
	gettimeofday(&curr_time, 0);
	lapsed = (curr_time.tv_sec - start.tv_sec) * 1000;
	lapsed = lapsed + (curr_time.tv_usec - start.tv_usec) / 1000;
	if (lapsed >= dur)
		time_up = 1;
	pthread_mutex_unlock(&philo->args->m_timer);
	return (time_up);
}

int	next_fork(int total, int i, int order)
{
	if (order == 0)
	{
		if (i == total - 1)
			return (0);
		else
			return (i);
	}
	else
	{
		if (i == total - 1)
			return (i);
		else
			return (i + 1);
	}
}

int	get_next_philo_id(t_philo *philo)
{
	if (philo->philo_id == philo->args->num_philos - 1)
		return (0);
	return (philo->philo_id + 1);
}
