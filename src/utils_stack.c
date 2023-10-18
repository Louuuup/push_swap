/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:09:17 by yakary            #+#    #+#             */
/*   Updated: 2023/10/18 16:40:30 by ycyr-roy         ###   ########.fr       */
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

// void	stack_print_idx(t_data *data)
// {
// 	t_value	*tmp1;
// 	t_value	*tmp2;

// 	tmp1 = data->stack_a;
// 	tmp2 = data->stack_b;
// 	printf("-----Printing stack IDX-----\n");
// 	while (tmp1 || tmp2)
// 	{
// 		if (tmp1)
// 		{
// 			printf("%7d", tmp1->index);
// 			tmp1 = tmp1->next;
// 		}
// 		else
// 			printf("       ");
// 		printf(" | ");
// 		if (tmp2)
// 		{
// 			printf("%-7d\n", tmp2->index);
// 			tmp2 = tmp2->next;
// 		}
// 		else
// 			printf("       \n");
// 		if (!tmp1 && !tmp2)
// 			break ;
// 	}
// }

// void	stack_print(t_data *data)
// {
// 	t_value	*tmp1;
// 	t_value	*tmp2;

// 	tmp1 = data->stack_a;
// 	tmp2 = data->stack_b;
// 	printf("-----Printing stack NB-----\n");
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
		if ((int)tmp->nb == obj)
			return (ERROR);
		tmp = tmp->next;
	}
	return (NO_ERROR);
}

int	find_obj(t_value *stack, int index)
{
	int		i;
	t_value	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		i++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (i);
}
