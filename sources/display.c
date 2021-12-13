/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:57 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/13 16:23:53 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(philo->m_display);
}

void	display_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	philo->last_meal = ft_get_time();
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" is eating\n");
	pthread_mutex_unlock(philo->m_display);
}

void	display_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" is sleeping\n");
	pthread_mutex_unlock(philo->m_display);
}

void	display_death(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" died\n");
	pthread_mutex_unlock(philo->m_display);
}

void	display_satiate(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putstr(" all philos are satiated\n");
	pthread_mutex_unlock(philo->m_display);
}
