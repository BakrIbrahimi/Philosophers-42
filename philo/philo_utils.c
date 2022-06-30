/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:50:59 by bibrahim          #+#    #+#             */
/*   Updated: 2022/06/18 13:46:26 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	write(2, "error\n", 7);
}

long	long	get_time(void)
{
	struct timeval	t_kch;

	if (gettimeofday(&t_kch, NULL) == -1)
		ft_error();
	return ((t_kch.tv_sec * 1000) + (t_kch.tv_usec / 1000));
}

void	ft_sleep(t_philo *philo)
{
	ft_printstat(philo, "is sleeping 😴", 1);
	ft_usleep(philo->data->t_slp);
}

void	ft_printstat(t_philo *philo, char *s, int a)
{
	pthread_mutex_lock(&philo->data->mutex);
	printf("%lld %d %s\n", get_time() - philo->data->currnt, philo->num, s);
	if (a)
		pthread_mutex_unlock(&philo->data->mutex);
}
