/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:50:13 by bibrahim          #+#    #+#             */
/*   Updated: 2022/06/18 13:46:17 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	long int		res;

	i = 0;
	res = 0;
	n = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		||str[i] == '\f' || str[i] == '\v' || str[i] == ' ' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (res * n);
}

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->mutex);
	while (++i < data->nbrph)
	{
		pthread_mutex_destroy(&data->forks[i]);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		ft_error();
		return (1);
	}
	if (check_arg(argv))
		return (1);
	get_struct(argc, argv, &data);
	init_str(&data);
	ft_init_philo(&data);
	ft_free(&data);
	return (0);
}
