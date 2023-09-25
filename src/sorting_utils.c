/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/25 16:00:13 by ycyr-roy         ###   ########.fr       */
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

void	indexing(t_value *stack, t_data *data)
{
	int biggest_value;
	int index;

	index = 1;
	biggest_value = 0;
	stack_print(data);
	while (index <= data->count)
	{
		while (stack)
		{
			if (stack->nb == biggest_value)
			{
				stack->index = index;
				printf("object with value %d has index of %d\n", stack->nb, index);
				index++;
			}
			if (stack->next)
				stack = stack->next;
			else
				break ;
		}
		biggest_value++;
		stack = data->stack_a;
	}
}
