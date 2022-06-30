/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:48:47 by bibrahim          #+#    #+#             */
/*   Updated: 2022/06/18 13:45:41 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
		{
			ft_error();
			return (1);
		}
		i++;
	}
	return (0);
}

void	get_struct(int ac, char **av, t_data *ph)
{
	ph->nbrph = ft_atoi(av[1]);
	ph->t_die = ft_atoi(av[2]);
	ph->t_eat = ft_atoi(av[3]);
	ph->t_slp = ft_atoi(av[4]);
	if (ac - 1 == 5)
		ph->nb_eat = ft_atoi(av[5]);
	else
		ph->nb_eat = -1;
}

int	init_str(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nbrph);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbrph);
	data->last_eat = malloc (sizeof(long long) * data->nbrph);
	if (!data->philos || !data->forks || !data->last_eat)
	{
		ft_error();
		return (1);
	}
	while (i < data->nbrph)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philos[i].data = data;
		data->philos[i].num = i + 1;
		data->die = 0;
		data->philos[i].flag = 0;
		i++;
	}
	return (0);
}
