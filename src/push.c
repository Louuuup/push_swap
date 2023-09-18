/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:19 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/15 17:28:06 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(void)
{
	t_data *data;

	data = get_data();
	if (data->stack_b->nb)
	{
		if (data->stack_a->nb)
		{
			printf("data->stack_a->nb = %d\n", data->stack_a->nb);
			printf("data->stack_b->nb = %d\n", data->stack_b->nb);
			data->stack_a->pre = data->stack_b;
			data->stack_b = data->stack_b->next;
			data->stack_a->next = data->stack_a;
			data->stack_a = data->stack_a->pre;
			data->stack_a->pre = NULL;
		}
		else
		{
			data->stack_a = data->stack_b;
			data->stack_b = data->stack_b->next;
			data->stack_a->pre = NULL;
		}
	}
	else
		ft_error("Unable to move object from Stack B because it is empty.");
	printf("pa\n");
}

void    pb(void)
{
	t_data *data;
	int 	tmp;
	
	data = get_data();
	if (data->stack_a->nb)
	{
		if (data->stack_b->nb)
		{
			printf("data->stack_a->nb = %d\n", data->stack_a->nb);
			printf("data->stack_b->nb = %d\n", data->stack_b->nb);
			tmp = data->stack_a->nb;
			
		}
		else
		{
			data->stack_b = data->stack_a;
			data->stack_a = data->stack_a->next;
			data->stack_b->pre = NULL;
		}
	}
	else
		ft_error("Unable to move object from Stack A because it is empty.");
	printf("pb\n");
}