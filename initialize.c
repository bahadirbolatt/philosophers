/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:34:47 by bbolat            #+#    #+#             */
/*   Updated: 2022/12/02 01:50:25 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philos(t_main *descartes)
{
	int	i;

	i = 0;
	descartes->philo = malloc(sizeof(t_philo) * descartes->num_philo);
	if (descartes->philo == NULL)
		return (0);
	while (i < descartes->num_philo)
	{
		descartes->philo[i].id = i;
		descartes->philo[i].eat_counter = 0;
		descartes->philo[i].l_fork_id = i;
		descartes->philo[i].r_fork_id = ((i + 1) % descartes->num_philo);
		i++;
	}
	return (1);
}

int	ft_init_common(t_main *des, int argc, char **argv)
{
	int	i;

	des->num_philo = ft_atoi(argv[1]);
	des->time_to_die = ft_atoi(argv[2]);
	des->time_to_eat = ft_atoi(argv[3]);
	des->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		des->num_of_times_eat = ft_atoi(argv[5]);
	else
		des->num_of_times_eat = -1;
	des->forks = malloc (sizeof(pthread_mutex_t) * des->num_philo + 1);
	if (des->forks == NULL)
		return (0);
	i = 0;
	while (i < des->num_philo)
	{
		if (pthread_mutex_init(&des->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (ft_init_philos(des))
		return (1);
	return (0);
}
