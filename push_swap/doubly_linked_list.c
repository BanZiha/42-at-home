/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:55:50 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:06 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_node(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_node_end(t_stack *stack, t_list *new_node)
{
	if (!stack->bottom)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->prev = stack->bottom;
		stack->bottom = new_node;
	}
	stack->size++;
}

void	ft_add_node_front(t_stack *stack, t_list *new_node)
{
	if (!stack->top)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->top->prev = new_node;
		new_node->next = stack->top;
		stack->top = new_node;
	}
	stack->size++;
}

void	ft_remove_node(t_stack *stack, t_list *node)
{
	if (!node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (stack->top == node)
		stack->top = node->next;
	if (stack->bottom == node)
		stack->bottom = node->prev;
	free(node);
	stack->size--;
}

void	ft_free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
