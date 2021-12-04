/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:54:41 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/01 20:44:16 by aaapatou         ###   ########.fr       */
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
	ft_usleep(philo->eat_time);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

void	ft_sleep(t_philo *philo)
{
	
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" is thinking");
	pthread_mutex_unlock(philo->m_display);
}