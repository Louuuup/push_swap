/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:51:35 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/18 23:11:16 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <string.h>
# include <stdio.h>

//================Base Values================//
//==================Structs===================//
typedef struct value
{
	int		nb;
	void	*next;
	void 	*pre;
}			t_value;

typedef struct data
{
	int		value_count;
	t_value *stack_a;
	t_value *stack_b;
	
}			t_data;
//==================[utils.c]===================//
/**
 * NOTE: Frees memory where the pointer points, and nullifies the pointer
*@param[in] ptr		Pointer to free
*@return		Nothing
*/
void	ft_free(void *ptr);
void	free_all(t_data *data);
t_value	*add_lst(t_value *value);
void	*lst_free(t_value *value);
void 	ft_swap(void *src, void *dst);
//==================[main.c]===================//
t_data	*get_data(void);
void	ft_error(char *str);
//==================[init.c]===================//
void	reader(t_data *data, char **entries);
t_data	*init(int count, t_data *data);
//==============[utils_stack.c]================//
void	stack_read(t_value *first);
void	stack_print(t_data *data);
int		find_in_stack(t_value *stack, int obj);
//==================[push.c]===================//
// Pushes the first element of B on top of A. Does nothing if B is empty.
void    pa(void);
// Pushes the first element of A on top of B. Does nothing if A is empty.
void	pb(void);
//==================[swap.c]===================//
void	sa(void);
void	sb(void);
void	ss(void);
//==================[rotate.c]===================//
void	ra(void);

#endif
