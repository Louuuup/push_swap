/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:51:35 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/09/07 17:06:53 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "string.h"

//================Base Values================//
//==================Structs===================//
typedef struct value
{
	int		num;
	void	*next;
}			t_value;
/**
 * NOTE: Fills data.distance with distance of player + 1
*@param[in] data		t_data
*@param[in] x 			X position
*@param[in] y 			Y position
*@param[in] distance 	for recursive purposes. 1 by default
*@return		your mom
*/
void f();

#endif
