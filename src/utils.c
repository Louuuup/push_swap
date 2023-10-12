/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:00:40 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/06 15:07:19 by ycyr-roy         ###   ########.fr       */
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

int	square_root(int nb)
{
	int	guess;
	int	loop_check;

	loop_check = 0;
	guess = nb / 2;
	while (guess * guess != nb && guess * guess + 1 != nb && guess \
		* guess - 1 != nb)
	{
		guess = (guess + nb / guess) / 2;
		if (loop_check == guess)
			break ;
		loop_check = guess;
	}
	return (guess);
}
