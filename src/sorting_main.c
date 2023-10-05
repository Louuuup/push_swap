/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:41:04 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/05 16:14:00 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_ordered(t_value *stack)
{
	int	before;

	before = 0;
	while (stack)
	{
		if (stack->index < before)
			return (0);
		before = stack->index;
		if (stack->next)
			stack = stack->next;
		else
			return (1);
	}
	return (1);
}

void	easy_sort(t_data *dt, int count)
{
	t_value	*tmp;
	int		i;

	i = 1;
	tmp = dt->stack_a->next;
	if (count == 2 && dt->stack_a->index > tmp->index)
		ra();
	while (stack_count(dt->stack_a) > 3)
	{
		if (dt->stack_a->index == count || dt->stack_a->index == 1)
			pb();
		else
			ra();
	}
	while (stack_ordered(dt->stack_a) == 0 && i < 1000)
	{
		tmp = get_obj(dt->stack_a, 2);
		if (tmp->index > get_obj(dt->stack_a, 1)->index && tmp->index \
			> dt->stack_a->index)
			sa();
		else
			ra();
		i++;
	}
}

void	polish(t_data *data, int index_to_find)
{
	int	slot_in_stack;

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

void	chunk_sort(int median, int range, t_data *data)
{
	int	tmp_index;

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
		chunk_sort((data->count / 2), data->chunk_size, data);
		polish(data, data->count);
	}
	else
	{
		easy_sort(data, data->count);
		while (data->stack_b)
		{
			if (data->stack_b->index < data->stack_a->index)
				pa();
			else
			{
				pa();
				ra();
			}
		}
	}
}
