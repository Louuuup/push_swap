/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:51:35 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/10/02 20:07:33 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <string.h>
# include <stdio.h>

//==================Structs===================//
typedef struct value
{
	int		nb;
	int		index;
	void	*next;
}			t_value;

typedef struct data
{
	int		avg;
	int		count;
	int		chunk_count;
	int		chunk_size;
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
int		square_root(int nb);
//==================[main.c]===================//
t_data	*get_data(void);
void	ft_error(void);
//==================[init.c]===================//
void	reader(t_data *data, char **entries);
t_data	*init(int count, t_data *data);
//==============[utils_stack.c]================//
void	stack_read(t_value *first);
void	stack_print(t_data *data);
int		find_in_stack(t_value *stack, int obj);
int		stack_count(t_value *stash);
//==================[push.c]===================//
// (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void    pa(void);
// (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(void);
//==================[swap.c]===================//
// (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(void);
// (swap b): Swap the first 2 elements at the top of stack b.
//	Do nothing if there is only one or no elements.
void	sb(void);
// sa and sb at the same time.
void	ss(void);
//==================[rotate.c]===================//
// (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(void);
// (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(void);
// ra and rb at the same time.
void	rr(void);
//==================[r_rotate.c]===================//
// (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(void);
// (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(void);
// rra and rrb at the same time.
void	rrr(void);
//==================[sorting_main.c]===================//
void	sort_main(t_data *data);
//==================[sorting_utils.c]===================//
void	indexing(t_value *stack, t_data *data);
int		find_obj(t_value *stack, int index);
int		find_biggest(t_value *stack, int range);
//Looks if there is an object with index between min and max in stack
int		range_in_stack(t_value *stack, int min, int max);

#endif
