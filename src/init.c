/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:06:52 by yakary            #+#    #+#             */
/*   Updated: 2023/10/12 22:29:07 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (i > 10)
		return (0);
	else if (i == 10 && str[0] != '-' && ft_strncmp(str, "2147483647", 10) < 0)
		return (0);
	else if (i == 10 && str[0] == '-' && ft_strncmp(str, "-2147483648", 10) > 0)
		return (0);
	return (1);
}

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
		else if (is_int(entries[i]))
			tmp->nb = ft_atoi(entries[i]);
		else
			ft_error();
		tmp->nb = ft_atoi(entries[i]);
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
