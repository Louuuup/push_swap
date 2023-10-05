/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:09:17 by yakary            #+#    #+#             */
/*   Updated: 2023/10/05 16:08:01 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_count(t_value *stash)
{
	int	i;

	if (stash)
		i = 1;
	else
		return (0);
	while (stash)
	{
		if (stash->next)
		{
			stash = stash->next;
			i++;
		}
		else
			break ;
	}
	return (i);
}

void	stack_read(t_value *first)
{
	t_value	*tmp;

	tmp = first;
	while (tmp)
	{
		tmp = tmp->next;
	}
}

// void	stack_print(t_data *data)
// {
// 	t_value	*tmp1;
// 	t_value	*tmp2;

// 	tmp1 = data->stack_a;
// 	tmp2 = data->stack_b;
// 	printf("-----Printing stacks-----\n");
// 	while (tmp1 || tmp2)
// 	{
// 		if (tmp1)
// 		{
// 			printf("%7d", tmp1->nb);
// 			tmp1 = tmp1->next;
// 		}
// 		else
// 			printf("       ");
// 		printf(" | ");
// 		if (tmp2)
// 		{
// 			printf("%-7d\n", tmp2->nb);
// 			tmp2 = tmp2->next;
// 		}
// 		else
// 			printf("       \n");
// 		if (!tmp1 && !tmp2)
// 			break ;
// 	}
// }

int	find_in_stack(t_value *stack, int obj)
{
	t_value	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->nb == obj)
			return (ERROR);
		tmp = tmp->next;
	}
	return (NO_ERROR);
}
