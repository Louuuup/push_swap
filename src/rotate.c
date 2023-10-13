/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/12 21:09:17 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_data *data, char stack)
{
	t_value	*index;
	t_value	*tmp;

	if (stack == 'a')
	{
		if (!(data->stack_a && data->stack_a->next))
			return ;
		index = data->stack_a;
		data->stack_a = data->stack_a->next;
	}
	else
	{
		if (!(data->stack_b && data->stack_b->next))
			return ;
		index = data->stack_b;
		data->stack_b = data->stack_b->next;
	}
	if (index && index->next)
	{
		tmp = index;
		while (index->next)
			index = index->next;
		index->next = tmp;
		tmp->next = NULL;
	}
}

void	ra(void)
{
	rotate(get_data(), 'a');
	write(1, "ra\n", 3);
}

void	rb(void)
{
	rotate(get_data(), 'b');
	write(1, "rb\n", 3);
}

void	rr(void)
{
	rotate(get_data(), 'a');
	rotate(get_data(), 'b');
	write(1, "rr\n", 3);
}
