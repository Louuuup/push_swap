/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:50:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/19 14:57:28 by ycyr-roy         ###   ########.fr       */
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
	if (swap(get_data(), 'a'))
		ft_error();
	else
		printf("sa\n");
}

void	sb(void)
{
	if (swap(get_data(), 'b'))
		ft_error();
	else
		printf("sb\n");
}

void	ss(void)
{
	if (swap(get_data(), 'a'))
		ft_error();
	else
		printf("s");
	if (swap(get_data(), 'b'))
		ft_error();
	else
		printf("s\n");
}
