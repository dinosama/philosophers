/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:38:30 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/01 16:08:47 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_data *data)
{
	data->die_time = 0;
	data->eat_nbr = -1;
	data->eat_time = 0;
	data->philo_nbr = 0;
	data->sleep_time = 0;
}

void	init_philo(t_philo *philo)
{
	philo->die_time = 0;
	philo->eat_nbr = -1;
	philo->eat_time = 0;
	philo->time_eat = 0;
	philo->lfork = NULL;
	philo->rfork = NULL;
	philo->m_display = NULL;
	philo->sleep_time = 0;
	philo->thread = 0;
}
