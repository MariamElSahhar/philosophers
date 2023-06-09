/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:58:17 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/02 19:48:21 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *philo_data)
{
	t_philo			*philo;
	struct timeval	last_meal;

	philo = (t_philo *)philo_data;
	while (!check_game_over(philo->args))
	{
		pthread_mutex_lock(&philo->args->m_info);
		last_meal = philo->last_meal_end;
		pthread_mutex_unlock(&philo->args->m_info);
		if (times_up(last_meal, philo, philo->args->time_to_die)
			&& !check_game_over(philo->args))
		{
			pthread_mutex_lock(&philo->args->m_print);
			if (!philo->args->game_over)
				printf("%lu %i died\n",
					time_since_start(philo->args->start_time),
					philo->philo_id + 1);
			philo->args->game_over = 1;
			pthread_mutex_unlock(&philo->args->m_print);
			return (0);
		}
		usleep(10);
	}
	return (0);
}

void	*meal_monitor(void *args)
{
	t_data	*data;
	int		i;
	int		done;

	data = (t_data *)args;
	done = 0;
	while (!check_game_over(data) && !done && data->num_eat != -1)
	{
		i = -1;
		done = 1;
		pthread_mutex_lock(&data->m_info);
		while (++i < data->num_philos)
		{
			if (data->philos[i].meals < data->num_eat)
				done = 0;
		}
		if (done)
		{
			data->game_over = 1;
			pthread_mutex_unlock(&data->m_info);
			return (0);
		}
		pthread_mutex_unlock(&data->m_info);
	}
	return (0);
}

int	main(int c, char **v)
{
	t_data	data;
	t_philo	*philos;
	int		i;

	gettimeofday(&data.start_time, 0);
	if (parse_input(c, v, &data))
	{
		philos = init(&data);
		i = -1;
		while (++i < data.num_philos)
		{
			pthread_create(philos[i].th_philo,
				NULL, &philosophize, (void *) &philos[i]);
			pthread_create(philos[i].th_monitor,
				NULL, &monitor, (void *) &philos[i]);
		}
		pthread_create(&data.meal_monitor, NULL, &meal_monitor, (void *) &data);
		free_destroy(&data, philos);
	}
	else
		error_message();
	return (0);
}

// valgrind --tool=helgrind ./philo
