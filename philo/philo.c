/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:55 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/28 17:25:56 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_philo *philo)
{
	struct timeval	start_sleeping;

	pthread_mutex_lock(&philo->args->m_print);
	gettimeofday(&start_sleeping, 0);
	if (!philo->args->game_over)
		printf("%lu %i is sleeping\n",
			get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
	while (!check_game_over(philo->args)
		&& !times_up(start_sleeping, philo, philo->args->time_to_sleep))
		usleep(10);
}

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->m_left_fork);
	pthread_mutex_lock(&philo->args->m_print);
	if (!philo->args->game_over)
		printf("%lu %i has taken a fork\n",
			get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
	pthread_mutex_lock(philo->m_right_fork);
	pthread_mutex_lock(&philo->args->m_print);
	if (!philo->args->game_over)
		printf("%lu %i has taken a fork\n",
			get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
}

static void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	gettimeofday(&philo->last_meal_start, NULL);
	pthread_mutex_lock(&philo->args->m_print);
	if (!philo->args->game_over)
		printf("%lu %i is eating\n",
			get_time_stamp(philo->args->start_time), philo->philo_id + 1);
	pthread_mutex_unlock(&philo->args->m_print);
	while (!times_up(philo->last_meal_end, philo, philo->args->time_to_eat))
		usleep(10);
	pthread_mutex_lock(&philo->args->m_print);
	philo->meals ++;
	gettimeofday(&philo->last_meal_end, NULL);
	pthread_mutex_unlock(&philo->args->m_print);
	philo->args->forks_tracker[philo->right_fork_id] = 1;
	philo->args->forks_tracker[philo->left_fork_id] = 1;
	pthread_mutex_unlock(philo->m_right_fork);
	pthread_mutex_unlock(philo->m_left_fork);
}

static int	forks_taken(t_philo *philo)
{
	int	left_id;
	int	right_id;

	if (philo->args->num_philos == 1)
		return (0);
	left_id = philo->left_fork_id;
	right_id = philo->right_fork_id;
	pthread_mutex_lock(philo->m_left_fork);
	if (!philo->args->forks_tracker[left_id])
	{
		pthread_mutex_unlock(philo->m_left_fork);
		return (0);
	}
	pthread_mutex_lock(philo->m_right_fork);
	if (!philo->args->forks_tracker[right_id])
	{
		pthread_mutex_unlock(philo->m_right_fork);
		pthread_mutex_unlock(philo->m_left_fork);
		return (0);
	}
	philo->args->forks_tracker[philo->left_fork_id] = 0;
	philo->args->forks_tracker[philo->right_fork_id] = 0;
	pthread_mutex_unlock(philo->m_right_fork);
	pthread_mutex_unlock(philo->m_left_fork);
	return (1);
}

void	*philosophize(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	if (philo->args->num_philos == 1)
		return (0);
	while (!check_game_over(philo->args))
	{
		while (!forks_taken(philo) && !check_game_over(philo->args))
			usleep(10);
		philo_eat(philo);
		philo_sleep(philo);
		if (!check_game_over(philo->args))
		{
			pthread_mutex_lock(&philo->args->m_print);
			printf("%lu %i is thinking\n",
				get_time_stamp(philo->args->start_time), philo->philo_id + 1);
			pthread_mutex_unlock(&philo->args->m_print);
		}
	}
	return (0);
}
