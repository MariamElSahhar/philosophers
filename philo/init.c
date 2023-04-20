/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:36:10 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/20 16:48:17 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_data(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->m_print, NULL);
	// pthread_mutex_init(&data->m_sleep, NULL);
	pthread_mutex_init(&data->m_timer, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	data->m_forks = (pthread_mutex_t *)malloc
		(data->num_philos * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_init(&data->m_forks[i], NULL);
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
		philos[i].is_eating = 0;
		philos[i].args = data;
		philos[i].m_fork1 = &data->m_forks[ascending(data->num_philos, i, 0)];
		philos[i].m_fork2 = &data->m_forks[ascending(data->num_philos, i, 1)];
		philos[i].th_philo = (pthread_t *)malloc(sizeof(pthread_t));
		i++;
	}
	return (philos);
}

static int	check_input(int c, char **v)
{
/* 	int	i;
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
	} */
	if (c && v)
		return (1);
	return (1);
}

int	parse_input(int c, char **v, t_data *data)
{
	if (check_input(c, v))
	{
		data->num_philos = ft_atoi(v[1]);
		data->time_to_die = DIE;
		data->time_to_sleep = SLEEP;
		data->time_to_eat = EAT;
		data->num_eat = -1;
		if (c == 6)
			data->num_eat = ft_atoi(v[6]);
		return (1);
	}
	return (0);
}

void	free_destroy(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_join(*philos[i].th_philo, NULL);
	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_destroy(&data->m_forks[i]);
		free(philos[i].th_philo);
	}
	free(data->m_forks);
	pthread_mutex_destroy(&data->m_eat);
	pthread_mutex_destroy(&data->m_timer);
	// pthread_mutex_destroy(&data->m_sleep);
	pthread_mutex_destroy(&data->m_print);
	free(philos);
}
