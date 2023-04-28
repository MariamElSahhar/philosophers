/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:36:10 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/28 12:26:55 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_data(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_timer, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	data->game_over = 0;
	data->m_forks = (pthread_mutex_t *)malloc
		(data->num_philos * sizeof(pthread_mutex_t));
	data->forks_tracker = (int *) malloc
		(data->num_philos * sizeof(int));
	i = -1;
	while (++i < data->num_philos)
	{
		data->forks_tracker[i] = 1;
		pthread_mutex_init(&data->m_forks[i], NULL);
	}
}

t_philo	*init(t_data *data)
{
	int		i;
	t_philo	*philos;

	init_data(data);
	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
	data->philos = philos;
	while (i < data->num_philos)
	{
		philos[i].philo_id = i;
		philos[i].meals = 0;
		gettimeofday(&philos[i].last_meal_end, NULL);
		philos[i].args = data;
		philos[i].left_fork_id = next_fork(data->num_philos, i, 0);
		philos[i].right_fork_id = next_fork(data->num_philos, i, 1);
		philos[i].m_left_fork = &data->m_forks[next_fork(data->num_philos, i, 0)];
		philos[i].m_right_fork = &data->m_forks[next_fork(data->num_philos, i, 1)];
		philos[i].th_philo = (pthread_t *)malloc(sizeof(pthread_t));
		philos[i].th_monitor = (pthread_t *)malloc(sizeof(pthread_t));
		i++;
	}
	return (philos);
}

static int	check_input(int c, char **v)
{
	int	i;
	int	j;

	if (c < 5 || c > 6)
		return (0);
	i = 1;
	while (i < c)
	{
		j = 0;
		if (v[i][j] == '+')
			j++;
		while (v[i][j])
		{
			if (!ft_isdigit(v[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_input(int c, char **v, t_data *data)
{
	if (check_input(c, v))
	{
		data->num_philos = ft_atoi(v[1]);
		data->time_to_die = ft_atoi(v[2]);
		data->time_to_sleep = ft_atoi(v[3]);
		data->time_to_eat = ft_atoi(v[4]);
		if (c == 6)
			data->num_eat = ft_atoi(v[5]);
		else
			data->num_eat = -1;
		return (1);
	}
	return (0);
}

void	free_destroy(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		pthread_join(*philos[i].th_philo, NULL);
		pthread_join(*philos[i].th_monitor, NULL);
	}
	pthread_join(data->meal_monitor, NULL);
	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_destroy(&data->m_forks[i]);
		free(philos[i].th_philo);
		free(philos[i].th_monitor);
	}
	free(data->m_forks);
	free(data->forks_tracker);
	pthread_mutex_destroy(&data->m_eat);
	pthread_mutex_destroy(&data->m_timer);
	pthread_mutex_destroy(&data->m_print);
	free(philos);
}
