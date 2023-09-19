/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:59:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/19 13:45:55 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*get_data(void)
{
	static t_data	*data;

	if (!data)
		data = ft_calloc(1, sizeof(t_data));
	return (data);
}

void	ft_error(char *str)
{
	printf("ERROR: %s\n", str);
	exit (ERROR);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc < 4)
		ft_error("Need at least 3 numbers to sort!");
	data = init(argc - 1, data);
	reader(data, argv);
	ra();
	stack_print(data);
	return (NO_ERROR);
}
		tmp->next = NULL;
