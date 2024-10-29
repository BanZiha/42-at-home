/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:42:20 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:33:57 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_list	*node;

	if (a->size < 2)
		return ;
	node = a->bottom;
	a->bottom = node->prev;
	a->bottom->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	t_list	*node;

	if (b->size < 2)
		return ;
	node = b->bottom;
	b->bottom = node->prev;
	b->bottom->next = NULL;
	node->prev = NULL;
	node->next = b->top;
	b->top->prev = node;
	b->top = node;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
}
