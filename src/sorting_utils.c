/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/20 18:28:50 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	avg_calc(t_value *stack)
{
	int total_value;

	total_value = 0;
	while (stack->next)
	{
		total_value += stack->nb;
		stack = stack->next;
	}
	total_value += stack->nb;
	return (total_value / get_data()->count);
}

void	peak_calc(t_value *stack, t_data *data)
{
	int max;
	int min;

	(void)data;
	max = 0;
	min = stack->nb;
	while (stack->next)
	{
		if (stack->nb > max)
			max = stack->nb;
		else if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	data->v_max = max;
	data->v_min = min;
}
