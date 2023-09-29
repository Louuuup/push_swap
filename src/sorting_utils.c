/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/29 17:15:39 by ycyr-roy         ###   ########.fr       */
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

int	range_in_stack(t_value *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index < max && stack->index > min)
			return (1);
		else if (stack->next)
			stack = stack->next;
		else
			break ;
	}
	return (0);
}

void	indexing(t_value *stack, t_data *data)
{
	int biggest_value;
	int index;

	index = 1;
	biggest_value = 0;
	while (index <= data->count)
	{
		while (stack)
		{
			if (stack->nb == biggest_value)
			{
				stack->index = index;
				// printf("object with value %d has index of %d\n", stack->nb, index);
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

t_value *get_obj(t_value *stack, int slot)
{
	int i;

	i = 0;
	while (i < slot && stack)
	{
		if (stack->next)
			stack = stack->next;
		// else
		// 	printf("Reached end of stack\n");
		i++;
	}
	return (stack);
}


int find_biggest(t_value *stack, int range)
{
	int i;
	int biggest;
	int biggest_idx;
	int tmp;

	tmp = 0;
	biggest = 0;
	i = 0;
	biggest_idx = 0;
	while (i < range)
	{
		tmp = get_obj(stack, i)->index;
		if (tmp > biggest)
		{
			biggest = tmp;
			biggest_idx = i;
		}
		i++;
	}
	// printf("Biggest number is #%d ouf of %d numbers\n", biggest_idx + 1, range);
	return (biggest_idx);
}

int find_obj(t_value *stack, int index)
{
	int i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		i++;
		if (stack->next)
			stack = stack->next;
		else
			break ;
	}
	return (i);
}

