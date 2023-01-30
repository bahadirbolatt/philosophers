/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:34:55 by bbolat            #+#    #+#             */
/*   Updated: 2022/12/02 01:34:56 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

/*
** limits
*/
# define INT_MAX 2147483647

/*
** bool
*/
# define TRUE 1
# define FALSE 0

/*
** Colors
*/
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

/*
** Routines messages
*/
# define EAT "-------- is eating 🍔 -------- "
# define SLEEP "------- is sleeping 🛌 ------- "
# define THINK "------- is thinking 🙇 ------- "
# define RFORK "-- has taken the right fork 🍴--"
# define LFORK "-- has taken the left fork 🍴 --"
# define DIED "******* 💀 died 💀 ******"

/*
** Structures
*/

typedef struct s_philo
{
	int				l_fork_id;
	int				r_fork_id;
	int				id;
	int				eat_counter;
	long long		last_eat;
	pthread_t		thread;
}					t_philo;

typedef struct s_main
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
	int				n_thread;
	int				dead;
	long long		time_start;
	t_philo			*philo;
	pthread_t		orchestrator;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}					t_main;

/*
** actions.c
*/
int			philo_eat(t_main *main, int i);
int			philo_sleep(t_main *main, int i);
int			philo_think(t_main *main, int i);
int			philo_is_dead(t_main *main, int *i);

/*
** handling_errors.c
*/
int			error_handling(int argc, char **argv, t_main *main);
int			init_input_struct(int argc, char **argv, t_main *main);
void		ft_print_warning(void);
int			ft_ctrl_arguments(int arrc, char **arr);
int			ft_init_common(t_main *descartes, int argc, char **argv);
/*
** handling_forks.c
*/
int			create_forks(t_main *main);

/*
** handling_philos.c
*/
int			create_philos(t_main *main);
void		fill_philo_struct(t_main *main, int i, int j);

/*
** handling_threads.c
*/
int			create_threads(t_main *main);
int			join_threads(t_main *main);
int			destroy_threads(t_main *main);

/*
** handling_time.c
*/
long long	get_time(void);
long long	delta_time(long long time2);
void		ft_time_machine(long long time, t_main *philo);

/**
**
*/
int			main(int argc, char **argv);
int			just_one_philo(t_main *main);

/*
** philo_utils.c
*/
int			ft_atoi(char *str);
int			ft_isdigit(const char *hdr);
int			philo_strncmp(const char *s1, const char *s2, size_t n);
int			philo_strlen(const char *str);
void		philo_free(t_main *main);
int			ft_init_philos(t_main *descartes);

/*
** routine.c
*/
void		*routine(void *args);
int			routine_execute(t_main *main, int i);
void		*checker(void *args);
int			philo_print(t_main *main, int id, char *color, char *status);

#endif
