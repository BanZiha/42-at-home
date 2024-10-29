/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:42:16 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:33:58 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_list	*node;

	if (a->size < 2)
		return ;
	node = a->top;
	a->top = node->next;
	a->top->prev = NULL;
	node->next = NULL;
	node->prev = a->bottom;
	a->bottom->next = node;
	a->bottom = node;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b)
{
	t_list	*node;

	if (b->size < 2)
		return ;
	node = b->top;
	b->top = node->next;
	b->top->prev = NULL;
	node->next = NULL;
	node->prev = b->bottom;
	b->bottom->next = node;
	b->bottom = node;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}
