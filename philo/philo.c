/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:55 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/20 17:10:02 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	struct timeval	start_sleeping;

	gettimeofday(&start_sleeping, 0);
	pthread_mutex_lock(&philo->args->m_print);
	printf("%i %i is sleeping\n",
		get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
	while (!times_up(start_sleeping, philo, philo->args->time_to_sleep))
		usleep (10);
	pthread_mutex_lock(&philo->args->m_print);
	printf("%i %i is thinking\n",
		get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
}

void	philo_eat(t_philo *philo)
{
	struct timeval	start_eating;

	pthread_mutex_lock(philo->m_fork1);
	pthread_mutex_lock(&philo->args->m_print);
	printf("%i %i has taken a fork\n",
		get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
	pthread_mutex_lock(philo->m_fork2);
	pthread_mutex_lock(&philo->args->m_print);
	printf("%i %i has taken a fork\n",
		get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
	gettimeofday(&start_eating, NULL);
	philo->is_eating = 1;
	pthread_mutex_lock(&philo->args->m_print);
	printf("%i %i is eating\n",
		get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
	while (!times_up(start_eating, philo, philo->args->time_to_eat))
		usleep (10);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->m_fork2);
	pthread_mutex_unlock(philo->m_fork1);
}

void	*philosophize(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	pthread_mutex_lock(&philo->args->m_print);
	pthread_mutex_unlock(&philo->args->m_print);
	philo_eat(philo);
	philo_sleep(philo);
	return (0);
}
