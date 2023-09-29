/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:41:04 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/29 17:20:57 by ycyr-roy         ###   ########.fr       */
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

void	linear_sort(t_value *stack, t_data *data) // old and slow
{
	int i;

	(void)stack;
	i = data->count;
	while (stack && i > 0)
	{
		if (data->stack_a->index  == i)
		{
			pb();
			i--;
		}
		else
			ra();
	}
}

void	split_sort(t_data *data)
{
	int median;
	int range;
	int tmp_index;
	int start_index;
	int i;

	i = data->count;
	start_index = data->stack_a->index;
	median = data->count / 2;
	range = median / 2;
	// printf("Median: %d\n Range: %d\n", median, range);

	while (data->stack_a && i > 0)
	{
		tmp_index = data->stack_a->index;
		if (tmp_index > (median - range) && tmp_index < (median + range))
		{
			// printf ("Number with index %d passed\n", data->stack_a->index);
			pb();
			if (tmp_index < median)
				rb();
		}
		else
			ra();
			i--;
		if (data->stack_a->index == start_index)
			break ;
	}
}
void	polish_one(t_data *data)
{
	int	i;
	int j;
	int biggest;
	int range;

	i = 0;
	j = 0;
	range = (stack_count(data->stack_b) / 2);
	if (range > CHUNK_SIZE)
		range = CHUNK_SIZE;
	while (i < range)
	{
		biggest = find_biggest(data->stack_b, range);
		while (j < biggest)
		{
			if (data->stack_b->next)
				rb();
			j++;
		}
		pa();
		while (j > 0)
		{
			j--;
			rrb();
		}
		i++;
	}

}
void	polish(t_data *data)
{
	int index_to_find;
	int slot_in_stack;

	index_to_find = data->count - 1;
	printf("Looking for index %d\n", index_to_find);
	while (stack_count(data->stack_b))
	{
		slot_in_stack = find_obj(data->stack_b, index_to_find);
		printf("Looking for index %d\n", slot_in_stack);
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
	int i;

	i = 0;
	median = data->count / 2;
	range = data->chunk_size;
	data->chunk_count = 2;
	while (data->stack_a && i < 10000)
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
		else if (median + range < data->count)
		{
			range += data->chunk_size;
			data->chunk_count += 2;
		}
		else
			break ;
		i++;
	}
}

void	sort_main(t_data *data)
{
	indexing(data->stack_a, data);
	printf("ey\n");
	data->chunk_size = square_root(data->count);
	printf("ey\n");
	chunk_sort(data);
	// while (data->chunk_count > 0)
	// {
	// 	polish_one(data);
	// 	data->chunk_count--;
	// }
	polish(data);
	// peak_calc(data->stack_a, data);
	// split_avg(data->stack_a, data);
}
