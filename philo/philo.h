/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:50:58 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/20 17:02:59 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../include/ft_printf.h"
# include <pthread.h>
# include <sys/time.h>

#define DIE 400
#define SLEEP 200
#define EAT 200

typedef struct s_philo t_philo;

typedef struct s_data {
	int				num_philos;
	int				num_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	struct timeval	start_time;
	pthread_mutex_t	m_eat;
	// pthread_mutex_t	m_sleep;
	pthread_mutex_t	m_timer;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*m_forks;
	t_philo			*philos;
}	t_data;

typedef struct s_philo {
	pthread_t		*th_philo;
	int				philo_id;
	int				is_eating;
	pthread_mutex_t	*m_fork1;
	pthread_mutex_t	*m_fork2;
	t_data			*args;
}	t_philo;

t_philo	*init(t_data *data);
int		parse_input(int c, char **v, t_data *data);

void	free_destroy(t_data *data, t_philo *philos);
int		ascending(int max, int i, int order);
int		times_up(struct timeval start, t_philo *philo, int dur);
int		get_time_stamp(struct timeval start);
int		get_next_philo_id(t_philo *philo);

void	*philosophize(void *philo_data);

#endif
