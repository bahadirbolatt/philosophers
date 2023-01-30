/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:34:32 by bbolat            #+#    #+#             */
/*   Updated: 2022/12/02 18:22:19 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].l_fork_id]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, B_BLUE, RFORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&main->forks[main->philo[i].r_fork_id]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, B_BLUE, LFORK) == FALSE)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, G_CYAN, EAT) == FALSE)
		return (FALSE);
	main->philo[i].last_eat = get_time();
	ft_time_machine(main->time_to_eat, main);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].l_fork_id]) != 0)
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].r_fork_id]) != 0)
		return (FALSE);
	main->philo[i].eat_counter++;
	return (TRUE);
}

int	philo_sleep(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	ft_time_machine(main->time_to_sleep, main);
	return (TRUE);
}

int	philo_think(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, G_BLUE, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	philo_is_dead(t_main *main, int *i)
{
	int	time;

	time = delta_time(main->philo[*i].last_eat);
	if (time > main->time_to_die)
	{
		philo_print(main, main->philo[*i].id, PINK, DIED);
		main->dead = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}
