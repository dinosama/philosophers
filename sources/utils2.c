/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:28:11 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/13 16:37:03 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_longatoi(const char *str)
{
	long long	i;
	int			neg;
	long long	stock;

	i = 0;
	neg = 1;
	stock = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (neg == -1)
			stock = (stock * 10) - (str[i] - 48);
		else
			stock = (stock * 10) + (str[i] - 48);
		i++;
	}
	return (stock);
}

void	data_philo(int i, t_data *data, t_philo *philo)
{
	unsigned long	time;

	time = ft_get_time();
	while (i < data->philo_nbr)
	{
		philo[i].data = data;
		philo[i].number = i + 1;
		philo[i].die_time = data->die_time;
		philo[i].eat_nbr = data->eat_nbr;
		philo[i].eat_time = data->eat_time;
		philo[i].sleep_time = data->sleep_time;
		philo[i].last_meal = time;
		if (i > 0)
			philo[i].m_display = philo[i - 1].m_display;
		i++;
	}
}
