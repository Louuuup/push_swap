/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:20 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/19 13:56:43 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(void)
{
	t_data	*data;
	t_value	*index;
	t_value	*tmp;

	data = get_data();
	if (data->stack_a && data->stack_a->next)
	{
		index = data->stack_a;
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		tmp->next = NULL;
		tmp->pre = index;
		while (index->next)
			index = index->next;
		index->next = tmp;
	}
	else
		ft_error("Less than two object in Stack A");
	printf("ra\n");
}