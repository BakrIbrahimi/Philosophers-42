/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bibrahim <bibrahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:51:17 by bibrahim          #+#    #+#             */
/*   Updated: 2022/06/18 13:46:32 by bibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct philo
{
	struct s_data	*data;
	int				num;
	pthread_t		ph;
	int				flag;
}t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	int				nbrph;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				nb_eat;
	long long		*last_eat;
	long long		currnt;
	int				die;
}t_data;

int				ft_atoi(const char *str);
int				check_arg(char **av);
void			get_struct(int ac, char **av, t_data *ph);
void			ft_printstat(t_philo *philo, char *s, int a);
long	long		get_time(void);
void			ft_usleep(int tie);
void			ft_sleep(t_philo *philo);
void			ft_think(t_philo *philo);
void			ft_error(void);
void			*ft_init_philo(t_data *data);
int				init_str(t_data *data);
void			*check_death(t_philo *philo);
#endif
