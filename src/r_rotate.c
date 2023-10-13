/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:16 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/12 21:11:03 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_data *data)
{
	t_value	*tmp;
	t_value	*index;

	if (data->stack_a && data->stack_a->next)
	{
		tmp = data->stack_a;
		index = data->stack_a;
		while (index && index->next)
			index = index->next;
		data->stack_a = index;
		data->stack_a->next = tmp;
		index = data->stack_a;
		while (index && index->next && index->next != data->stack_a)
			index = index->next;
		index->next = NULL;
	}
}

void	r_rotate_b(t_data *data)
{
	t_value	*tmp;
	t_value	*index;

	if (data->stack_b && data->stack_b->next)
	{
		tmp = data->stack_b;
		index = data->stack_b;
		while (index && index->next)
			index = index->next;
		data->stack_b = index;
		data->stack_b->next = tmp;
		index = data->stack_b;
		while (index && index->next && index->next != data->stack_b)
			index = index->next;
		index->next = NULL;
	}
}

void	rra(void)
{
	r_rotate_a(get_data());
	write(1, "rra\n", 4);
}

void	rrb(void)
{
	r_rotate_b(get_data());
	write(1, "rrb\n", 4);
}

void	rrr(void)
{
	r_rotate_a(get_data());
	r_rotate_b(get_data());
	write(1, "rrr\n", 4);
}
