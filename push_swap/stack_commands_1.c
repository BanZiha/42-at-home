/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:10:26 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:33:58 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	t_list	*first;
	t_list	*second;

	if (a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	a->top = second;
	if (a->size == 2)
		a->bottom = first;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b)
{
	t_list	*first;
	t_list	*second;

	if (b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	b->top = second;
	if (b->size == 2)
		b->bottom = first;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	t_list	*node;

	if (b->size == 0)
		return ;
	node = b->top;
	b->top = b->top->next;
	if (b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	b->size--;
	node->next = a->top;
	if (a->top)
		a->top->prev = node;
	else
		a->bottom = node;
	a->top = node;
	node->prev = NULL;
	a->size++;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_list	*node;

	if (a->size == 0)
		return ;
	node = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	a->size--;
	node->next = b->top;
	if (b->top)
		b->top->prev = node;
	else
		b->bottom = node;
	b->top = node;
	node->prev = NULL;
	b->size++;
	write(1, "pb\n", 3);
}
