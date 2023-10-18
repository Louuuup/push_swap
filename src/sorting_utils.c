/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/18 15:18:36 by ycyr-roy         ###   ########.fr       */
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
	// int	biggest_value;
	// int	index;

	// index = 1;
	// biggest_value = 0;
	// while (index <= data->count && stack->next)
	// {
	// 	while (stack)
	// 	{
	// 		if (stack->nb == biggest_value)
	// 		{
	// 			stack->index = index;
	// 			index++;
	// 		}
	// 		if (stack->next)
	// 			stack = stack->next;
	// 		else
	// 			break ;
	// 	}
	// 	biggest_value++;
	// 	stack = data->stack_a;
	// }
	t_value *tmp;
	int smallest;
	int index;

	smallest = -2147483647;
	index = 1;
	while (index <= data->count)
	{
		tmp = find_smallest_nb(stack, smallest);
		smallest = tmp->nb;
		tmp->index = index;
		// printf("smallest: %d\n index: %d\n\n", smallest, index);
		index++;
	}
	// stack_print(data);
	// stack_print_idx(data);
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

t_value	*find_smallest_nb(t_value *stack, int min)
{
	int		i;
	long	found;
	t_value	*tmp;

	tmp = stack;
	found = 2147483650;
	while (tmp)
	{
		if (tmp->nb < found && tmp->nb > min)
			found = tmp->nb;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp->nb != found)
		tmp = tmp->next;
	return (tmp);
}
