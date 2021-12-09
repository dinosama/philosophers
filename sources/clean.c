/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 02:46:09 by aaapatou          #+#    #+#             */
/*   Updated: 2021/12/08 04:04:01 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_clean(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_destroy(data->philo[i].rfork);
		i++;
	}
	free(data->philo);
}