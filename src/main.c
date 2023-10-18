/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:59:32 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/18 16:39:48 by ycyr-roy         ###   ########.fr       */
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

int	array_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	have_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_all(get_data());
	exit (ERROR);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	data->is_split = 0;
	if ((argc == 2 && (!is_int(argv[1])) || (argc > 2 && !is_int(argv[2]))))
		ft_error();
	else if (argc > 1 && have_space(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		argc = array_count(argv);
		data->is_split = 1;
	}
	if (argc > 2 && is_int(argv[2]))
	{
		data = init(argc - 1, data);
		reader(data, argv);
		indexing(data->stack_a, data);
		if (!stack_ordered(data->stack_a))
			sort_main(data);
	}
	if (data->is_split)
		ft_free(argv);
	if (data)
		free_all(data);
	return (NO_ERROR);
}
