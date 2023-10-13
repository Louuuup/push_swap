/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/12 21:10:13 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_data *data, char stack)
{
	t_value	*tmp;

	if (data->stack_a && data->stack_a->next && stack == 'a')
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		tmp->next = data->stack_a->next;
		data->stack_a->next = tmp;
	}
	else if (data->stack_b && data->stack_b->next && stack == 'b')
	{
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		tmp->next = data->stack_b->next;
		data->stack_b->next = tmp;
	}
	else
		return (ERROR);
	return (NO_ERROR);
}

void	sa(void)
{
	swap(get_data(), 'a');
	write(1, "sa\n", 3);
}

void	sb(void)
{
	swap(get_data(), 'b');
	write(1, "sb\n", 3);
}

void	ss(void)
{
	swap(get_data(), 'a');
	swap(get_data(), 'b');
	write(1, "ss\n", 3);
}
