/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:19 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/19 14:30:02 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(void)
{
	t_data	*data;
	t_value	*tmp;

	data = get_data();
	tmp = data->stack_b;
	if (data->stack_b)
	{
		if (data->stack_a)
		{
			data->stack_b = data->stack_b->next;
			tmp->next = data->stack_a;
			// data->stack_a->pre = tmp;
			data->stack_a = tmp;
		}
		else
		{
			data->stack_a = data->stack_b;
			data->stack_b = data->stack_b->next;
			// data->stack_b->pre = NULL;
			data->stack_a->next = NULL;
		}
	}
	else
		ft_error();
	printf("pa\n");
}

void	pb(void)
{
	t_data	*data;
	t_value	*tmp;

	data = get_data();
	tmp = data->stack_a;
	if (data->stack_a)
	{
		if (data->stack_b)
		{
			data->stack_a = data->stack_a->next;
			tmp->next = data->stack_b;
			// data->stack_b->pre = tmp;
			data->stack_b = tmp;
		}
		else
		{
			data->stack_b = data->stack_a;
			data->stack_a = data->stack_a->next;
			// data->stack_a->pre = NULL;
			data->stack_b->next = NULL;
		}
	}
	else
		ft_error();
	printf("pb\n");
}
