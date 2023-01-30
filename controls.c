/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:34:34 by bbolat            #+#    #+#             */
/*   Updated: 2022/12/02 01:34:35 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_ctrl_arguments(int arrc, char **arr)
{
	size_t	i;

	i = 0;
	if (arrc < 5 || arrc > 6)
	{
		ft_print_warning();
		return (1);
	}
	while (arr[++i])
	{
		if (!ft_isdigit(arr[i]) || (!ft_atoi(arr[i])))
		{
			printf("you might be enter the wrong answers");
			return (1);
		}
	}
	return (0);
}

void	ft_print_warning(void)
{
	printf("    ____________________________________\n");
	printf("    |  please enter 4 or 5 arguments   |\n");
	printf("    |__________________________________|\n");
	printf("    |    [1] number of philosopher     |\n");
	printf("    |         [2] time to die          |\n");
	printf("    |         [3] time to eat          |\n");
	printf("    |        [4] time to sleep         |\n");
	printf("    | [5] how many times they must eat |\n");
	printf("    |__________________________________|\n");
}
