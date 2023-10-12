/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:06:52 by yakary            #+#    #+#             */
/*   Updated: 2023/10/11 16:10:59 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reader(t_data *data, char **entries)
{
	int		i;
	t_value	*tmp;

	i = 0;
	if (!data->is_split)
		i = 1;
	tmp = data->stack_a;
	while (i <= data->count)
	{
		if (find_in_stack(data->stack_a, ft_atoi(entries[i])) && i > 1)
			ft_error();
		if (i > 0 + !data->is_split)
			tmp = add_lst(tmp);
		else
			tmp->nb = ft_atoi(entries[i]);
		if (entries[i][0] == '\0')
			ft_error();
		tmp->nb = ft_atoi(entries[i]);
		if (tmp->nb < 0 || tmp->nb > 2147483647)
			ft_error();
		i++;
	}
	stack_read(data->stack_a);
}

t_data	*init(int count, t_data *data)
{
	data = get_data();
	data->count = count;
	data->stack_a = ft_calloc(1, sizeof(t_value));
	return (data);
}
