/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/20 14:00:43 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_data *data, char stack)
{
	t_value	*index;
	t_value	*tmp;

	if (stack == 'a')
	{
		index = data->stack_a;
		data->stack_a = data->stack_a->next;
	}
	else
	{
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
	else
		return (ERROR);
	return (NO_ERROR);
}
void	ra(void)
{
	rotate(get_data(), 'a');
	printf("ra\n");
}

void	rb(void)
{
	rotate(get_data(), 'b');
	printf("rb\n");
}

void	rr(void)
{
	rotate(get_data(), 'a');
	rotate(get_data(), 'b');
	printf("rr\n");
}
