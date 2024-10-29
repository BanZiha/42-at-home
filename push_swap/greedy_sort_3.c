/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:19:50 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:03 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_top_b(t_stack *b, int b_index)
{
	if (b_index <= b->size / 2)
	{
		while (b_index--)
			ft_rb(b);
	}
	else
	{
		b_index = b->size - b_index;
		while (b_index--)
			ft_rrb(b);
	}
}

void	ft_move_to_top_a(t_stack *a, int pos_in_a)
{
	if (pos_in_a <= a->size / 2)
	{
		while (pos_in_a--)
			ft_ra(a);
	}
	else
	{
		pos_in_a = a->size - pos_in_a;
		while (pos_in_a--)
			ft_rra(a);
	}
}

void	ft_move_index_0_to_top(t_stack *a)
{
	t_list	*current;
	int		index_0_pos;

	current = a->top;
	index_0_pos = 0;
	while (current)
	{
		if (current->index == 0)
			break ;
		current = current->next;
		index_0_pos++;
	}
	ft_move_to_top_a(a, index_0_pos);
}
