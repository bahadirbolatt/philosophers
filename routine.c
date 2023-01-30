/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by bbolat            #+#    #+#             */
/*   Updated: 2022/12/02 18:33:30 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = main->n_thread;
	if (main->num_of_times_eat > 0)
	{
		while (main->num_of_times_eat > main->philo[i].eat_counter
			&& main->dead == FALSE)
			routine_execute(main, i);
	}
	else
	{
		while (main->dead == FALSE)
		{
			if (routine_execute(main, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_eat(main, i) == FALSE)
		return (FALSE);
	if (main->num_of_times_eat != main->philo[i].eat_counter)
	{
		if (philo_sleep(main, i) == FALSE)
			return (FALSE);
		if (philo_think(main, i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

void	*checker(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = 0;
	if (main->num_of_times_eat > 0)
	{
		while (main->num_of_times_eat > main->philo[i].eat_counter
			&& main->dead == FALSE)
		{
			if (philo_is_dead(main, &i) == TRUE)
				break ;
		}
	}
	else
	{
		while (main->dead == FALSE)
		{
			if (philo_is_dead(main, &i) == TRUE)
				break ;
		}
	}
	return (NULL);
}

int	philo_print(t_main *main, int id, char *color, char *status)
{
	long long	now;

	now = delta_time(main->time_start);
	if (main->dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&main->write);
	if (main->dead == TRUE)
	{
		pthread_mutex_unlock(&main->write);
		return (FALSE);
	}
	else
		printf("%s%-10lld-> timestamp_in_ms ~ %-3d %-30s%s\n", \
		color, now, id, status, RESET);
	pthread_mutex_unlock(&main->write);
	return (TRUE);
}
