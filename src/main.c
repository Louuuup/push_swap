/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:59:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/29 17:17:21 by ycyr-roy         ###   ########.fr       */
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

void	ft_error(void)
{
	fprintf(stderr, "Error\n");
	exit (ERROR);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc < 4)
		ft_error();
	data = init(argc - 1, data);

	reader(data, argv);

	sort_main(data);
	// pb();
	// stack_print(data);
	return (NO_ERROR);
}
