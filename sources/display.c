/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:57 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/01 17:25:27 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" has taken a fork");
	pthread_mutex_unlock(philo->m_display);
}

void	display_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->m_display);
	ft_putlongnbr(ft_get_time());
	ft_putchar(' ');
	ft_putlongnbr((unsigned long)philo->number);
	ft_putstr(" is eating");
	pthread_mutex_unlock(philo->m_display);
}