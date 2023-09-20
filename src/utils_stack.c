/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:09:17 by yakary            #+#    #+#             */
/*   Updated: 2023/09/20 18:31:11 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_read(t_value *first)
{
	t_value *tmp;

	tmp = first;
	printf("stack_read\n");
	while (tmp)
	{
		printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}

void	stack_print(t_data *data)
{
	t_value	*tmp1;
	t_value	*tmp2;

	tmp1 = data->stack_a;
	tmp2 = data->stack_b;
	printf("-----Printing stacks-----\n");
	while (tmp1 || tmp2)
	{
		if (tmp1)
		{
			printf("%7d", tmp1->nb);
			tmp1 = tmp1->next;
		}
		else
			printf("       ");
		printf(" | ");
		if (tmp2)
		{
			printf("%-7d\n", tmp2->nb);
			if (tmp2->next)
				tmp2 = tmp2->next;
		}
		else
			printf("       \n");
		if (!tmp1 && !tmp2)
			break ;
	}
}

int	find_in_stack(t_value *stack, int obj)
{
	t_value *tmp;

	tmp = stack;
	while (tmp)
	{
		printf("tmp = %d\n", tmp->nb);
		printf("comparing (tmp)%d to (obj)%d\n", tmp->nb, obj);
		if (tmp->nb == obj)
			return (ERROR);
		tmp = tmp->next;
	}
	printf("find_in_stack: no match found\n");
	return (NO_ERROR);
}
