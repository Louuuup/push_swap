/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:00:40 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/13 12:19:33 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}

void	free_all(t_data *data)
{
	lst_free(data->stack_a);
	lst_free(data->stack_b);
	ft_free(data);
}

t_value	*add_lst(t_value *value)
{
	t_value	*new;
	
	new = ft_calloc(1, sizeof(t_value));
	new->pre = value;
	value->next = new;
	return (new);
}

void	*lst_free(t_value *value)
{
	t_value	*tmp;

	while (value)
	{
		tmp = value->next;
		ft_free(value);
		value = tmp;
	}
	return (NULL);
}

void ft_swap(void *src, void *dst)
{
	void *tmp;

	tmp = src;
	src = dst;
	dst = tmp;
}