/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/18 23:08:42 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(void)
{
	t_data	*data;
	t_value	*tmp;

	data = get_data();
	if (data->stack_a && data->stack_a->next)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		tmp->next = data->stack_a->next;
		data->stack_a->next = tmp;
		tmp->pre = data->stack_a;
		data->stack_a->pre = NULL;
	}
	else
		ft_error("Trying to swap object that does not exist or is the last one.");
	printf("sa\n");
}

void	sb(void)
{
	t_data	*data;
	t_value	*tmp;

	data = get_data();
	if (data->stack_b && data->stack_b->next)
	{
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		tmp->next = data->stack_b->next;
		data->stack_b->next = tmp;
		tmp->pre = data->stack_b;
		data->stack_b->pre = NULL;
	}
	else
		ft_error("Trying to swap object that does not exist or is the last one.");
	printf("sb\n");
}

void	ss(void)
{
	sa();
	sb();
	printf("ss\n");
}
