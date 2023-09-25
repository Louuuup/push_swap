/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:41:04 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/25 17:11:13 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	split_avg(t_value *src, t_data *dt)
{
	while (src && dt && dt->stack_a)
	{
		// printf("\n\n====This is one Split====\n");
		if (src->nb >= dt->avg - dt->dsplit && src->nb <= dt->avg + dt->dsplit)
		{
			if (dt->stack_a && dt->stack_a->nb >= dt->avg)
			{
				pb();
			}
			else
			{
				pb();
				rb();
			}
		}
	}
}

void	linear_sort(t_value *stack, t_data *data)
{
	int i;

	(void)stack;
	i = data->count;
	while (stack && i > 0)
	{
		if (data->stack_a->index == i)
		{
			pb();
			i--;
		}
		else
			ra();
	}
}

void	sort_main(t_data *data)
{
	// data->avg = avg_calc(data->stack_a);
	// printf("avg of values is %d\n", data->avg);
	indexing(data->stack_a, data);
	linear_sort(data->stack_a, data);
	// peak_calc(data->stack_a, data);
	// split_avg(data->stack_a, data);
}
