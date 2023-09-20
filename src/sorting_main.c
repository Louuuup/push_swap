/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:41:04 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/20 18:28:18 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	split_avg(t_value *src, t_data *dt)
{
	while (src->next)
	{
		if (src->nb >= dt->avg - dt->dsplit && src->nb <= dt->avg + dt->dsplit)
		{
			if (src->nb >= dt->avg)
				pb();
			else
			{
				pb();
				rrb();
			}
		}
	}
}
void	sort_main(t_data *data)
{
	data->avg = avg_calc(data->stack_a);
	printf("avg of values is %d\n", data->avg);
	peak_calc(data->stack_a, data);
	split_avg(data->stack_a, data);
}
