/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:54:41 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/08 04:16:30 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	display_fork(philo);
	pthread_mutex_lock(philo->lfork);
	display_fork(philo);
}

void	ft_eat(t_philo *philo)
{
	display_eating(philo);
	philo->time_eat = ft_get_time();
	philo->meals++;
	if (philo->meals == philo->eat_nbr)
		philo->data->satiate_nbr = philo->data->satiate_nbr + 1;
	ft_usleep(philo->eat_time);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

void	ft_sleep(t_philo *philo)
{
	display_sleeping(philo);
	ft_usleep(philo->sleep_time);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" is thinking\n");
	pthread_mutex_unlock(philo->m_display);
}

void	*routine(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *) philo;
	while (1)
	{
		if (tmp->data->dead == 0 && tmp->data->satiate == 0 && (tmp->meals < tmp->eat_nbr || tmp->eat_nbr == -1))
			ft_take_forks(tmp);
		if (tmp->data->dead == 0 && tmp->data->satiate == 0 && (tmp->meals < tmp->eat_nbr || tmp->eat_nbr == -1))
			ft_eat(tmp);
		if (tmp->data->dead == 0 && tmp->data->satiate == 0 && (tmp->meals < tmp->eat_nbr || tmp->eat_nbr == -1))
			ft_sleep(tmp);
		if (tmp->data->dead == 0 && tmp->data->satiate == 0 && (tmp->meals < tmp->eat_nbr || tmp->eat_nbr == -1))
			ft_think(tmp);
	}
	return (NULL);
}
