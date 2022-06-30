/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:49:52 by bibrahim          #+#    #+#             */
/*   Updated: 2022/06/18 13:46:09 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->num - 1]);
	ft_printstat(philo, "has taken a fork 🍴", 1);
	pthread_mutex_lock(&philo->data->forks[philo->num % philo->data->nbrph]);
	ft_printstat(philo, "has taken a fork 🍴", 1);
	ft_printstat(philo, "is eating 🍔 ", 1);
	philo->data->last_eat[philo->num - 1] = get_time();
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->num - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->num % philo->data->nbrph]);
}

void	*ft_fonction(void *arg)
{
	t_philo	*philo;
	int		eat;	

	philo = (t_philo *)arg;
	eat = 0;
	if (!(philo->num % 2))
		usleep(100);
	while (1)
	{
		ft_eat(philo);
		eat++;
		if (philo->data->nb_eat != -1)
		{
			if (eat >= philo->data->nb_eat)
			{
				philo->flag = 1;
				break ;
			}
		}
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	*ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->currnt = get_time();
	data->die = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->nbrph)
	{
		data->last_eat[i] = get_time();
		pthread_create(&data->philos[i].ph, NULL, &ft_fonction,
			&data->philos[i]);
		i++;
	}
	check_death(data->philos);
	i = 0;
	while (i < data->nbrph && (!data->die))
	{
		pthread_join(data->philos[i].ph, NULL);
		i++;
	}
	return (NULL);
}
