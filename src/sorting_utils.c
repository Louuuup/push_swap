/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/12 23:44:08 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	biggest_value;
	int	index;

	index = 1;
	biggest_value = 0;
	while (index <= data->count && stack->next)
	{
		while (stack)
		{
			if (stack->nb == biggest_value)
			{
				stack->index = index;
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

t_value	*get_obj(t_value *stack, int slot)
{
	int	i;

	i = 0;
	while (i < slot && stack)
	{
		if (stack->next)
			stack = stack->next;
		i++;
	}
	return (stack);
}

int	find_biggest_idx(t_value *stack, int range)
{
	int	i;
	int	biggest;
	int	biggest_idx;
	int	tmp;

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
	return (biggest_idx);
}

int	find_biggest_nb(t_value *stack, int range, int skip)
{
	// int		i;
	// t_value	tmp;

	// while (tmp)
	// {

	// }
}
