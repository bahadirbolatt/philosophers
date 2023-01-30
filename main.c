/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:34:22 by bbolat            #+#    #+#             */
/*   Updated: 2022/12/02 02:27:22 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (ft_ctrl_arguments(argc, argv))
		return (1);
	if (!ft_init_common(&main, argc, argv))
		return (0);
	if (main.num_philo == 1)
	{
		if (just_one_philo(&main) == FALSE)
			return (1);
		return (0);
	}
	if (create_threads(&main) == FALSE)
		return (1);
	if (destroy_threads(&main) == FALSE)
		return (1);
	philo_free(&main);
	return (0);
}

int	just_one_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (FALSE);
	main->time_start = get_time();
	philo_print(main, 1, B_BLUE, RFORK);
	ft_time_machine(main->time_to_die, main);
	philo_print(main, 1, PINK, DIED);
	philo_free(main);
	return (TRUE);
}
