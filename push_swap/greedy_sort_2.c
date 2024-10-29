/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:19:55 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:04 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_max_indices(int index, int *max1, int *max2, int *max3)
{
	if (index > *max1)
	{
		*max3 = *max2;
		*max2 = *max1;
		*max1 = index;
	}
	else if (index > *max2)
	{
		*max3 = *max2;
		*max2 = index;		
	}
	else if (index > *max3)
		*max3 = index;
}

void	ft_push_all_to_a(t_stack *a, t_stack *b)
{
	int	b_index;
	int	pos_in_a;

	while (b->size > 0)
	{
		ft_find_min_moves(a, b, &b_index);
		ft_move_to_top_b(b, b_index);
		pos_in_a = ft_get_insert_position(a, b->top->content);
		ft_move_to_top_a(a, pos_in_a);
		ft_pa(a, b);
	}
}

int	ft_find_min_moves(t_stack *a, t_stack *b, int *b_index)
{
	t_list	*current;
	int		min_moves;
	int		moves;
	int		pos_in_a;
	int		index_in_b;

	current = b->top;
	min_moves = INT_MAX;
	index_in_b = 0;
	while (current)
	{
		pos_in_a = ft_get_insert_position(a, current->content);
		moves = ft_get_move_count_to_top(b, index_in_b)
			+ ft_get_move_count_to_top(a, pos_in_a);
		if (moves < min_moves)
		{
			min_moves = moves;
			*b_index = index_in_b;
		}
		current = current->next;
		index_in_b++;
	}
	return (min_moves);
}

int	ft_get_insert_position(t_stack *a, int value)
{
	t_list	*current;
	int		pos;
	int		last_value;

	current = a->top;
	pos = 0;
	last_value = a->bottom->content;
	while (current)
	{
		if (last_value < value && current->content > value)
			break ;
		if (last_value > current->content && value < current->content)
			break ;
		last_value = current->content;
		current = current->next;
		pos++;
	}
	return (pos);
}

int	ft_get_move_count_to_top(t_stack *stack, int index)
{
	if (index <= stack->size / 2)
		return (index);
	else
		return (stack->size - index);
}
