/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:49:29 by bibrahim          #+#    #+#             */
/*   Updated: 2022/06/18 13:45:53 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	ft_printstat(philo, "the philo is thinking", 1);
}

void	ft_usleep(int tie)
{
	long long	t;

	t = get_time();
	while (get_time() - t < (long int)tie)
		usleep(10);
}

void	*check_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->data->nbrph)
		{
			if (philo[i].data->t_die <= get_time() - philo[i].data->last_eat[i])
			{
				if (philo[i].flag != 1)
					ft_printstat(&philo[i], "died", 0);
				philo[i].data->die = 1;
				break ;
			}
			i++;
		}
		if (philo->data->die == 1)
			break ;
	}
	return (NULL);
}
