/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:48:18 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 16:36:44 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	time_since_start(struct timeval start)
{
	struct timeval	curr_time;
	unsigned long	time_stamp;

	gettimeofday(&curr_time, 0);
	time_stamp = (curr_time.tv_sec - start.tv_sec) * (unsigned long) 1000;
	time_stamp += (curr_time.tv_usec - start.tv_usec) / 1000;
	return (time_stamp);
}

int	times_up(struct timeval start, t_philo *philo, unsigned long dur)
{
	struct timeval	curr_time;
	unsigned long	lapsed;
	int				time_up;

	time_up = philo->philo_id;
	time_up = 0;
	gettimeofday(&curr_time, 0);
	lapsed = (curr_time.tv_sec - start.tv_sec) * (unsigned long) 1000;
	lapsed = lapsed + (curr_time.tv_usec - start.tv_usec) / 1000;
	if (lapsed > dur)
		time_up = 1;
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

int	check_game_over(t_data *data)
{
	int	over;

	pthread_mutex_lock(&data->m_print);
	over = data->game_over;
	pthread_mutex_unlock(&data->m_print);
	return (over);
}
