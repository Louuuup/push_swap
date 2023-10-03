/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:41:04 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/02 20:07:26 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_sort(t_data *dt, int count)
{
	t_value *tmp;
	t_value *stack;

	stack = dt->stack_a;
	tmp = stack->next;
	if (count == 2 && stack->index > tmp->index)
		ra();
	else
	{
		while (count)
		{
			if (dt->stack_a->index == count)
			{
				pb();
				count--;
			}
			else
				ra();
		}
	}
}

void	polish(t_data *data)
{
	int index_to_find;
	int slot_in_stack;

	index_to_find = data->count;
	while (stack_count(data->stack_b))
	{
		slot_in_stack = find_obj(data->stack_b, index_to_find);
		if (!find_in_stack(data->stack_b, index_to_find))
			return ;
		if (slot_in_stack > (stack_count(data->stack_b)) / 2)
		{
			while (data->stack_b->index != index_to_find)
				rrb();
			pa();
			index_to_find--;
		}
		else
		{
			while (data->stack_b->index != index_to_find)
			{
				rb();
			}
			pa();
			index_to_find--;
		}
	}
}

void	chunk_sort(t_data *data)
{
	int tmp_index;
	int median;
	int range;
	median = data->count / 2;
	range = data->chunk_size;
	data->chunk_count = 2;
	while (data->stack_a)
	{
		tmp_index = data->stack_a->index;
		if (tmp_index > (median - range) && tmp_index < (median + range))
		{
			pb();
			if (tmp_index < median)
				rb();
		}
		else if (range_in_stack(data->stack_a, median - range, median + range))
			ra();
		else if (median + range < data->count + 1)
		{
			range += data->chunk_size;
			data->chunk_count += 2;
		}
		else
			break ;
	}
}

void	sort_main(t_data *data)
{
	indexing(data->stack_a, data);
	data->chunk_size = square_root(data->count);
	if (data->count > 5)
	{
		chunk_sort(data);
		polish(data);
	}
	else
		easy_sort(data, data->count);
	free_all(data);
}
