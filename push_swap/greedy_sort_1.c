/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:40:05 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:05 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_top_three(t_stack *a, int *max1, int *max2, int *max3)
{
	t_list	*current;
	int		index;

	current = a->top;
	*max1 = -1;
	*max2 = -1;
	*max3 = -1;
	while (current)
	{
		index = current->index;
		ft_update_max_indices(index, max1, max2, max3);
		current = current->next;
	}
}

void	ft_move_except_top_three_to_b(t_stack *a, t_stack *b)
{
	int	max1;
	int	max2;
	int	max3;
	int	size;
	int	index;

	ft_find_top_three(a, &max1, &max2, &max3);
	size = a->size;
	while (size--)
	{
		index = a->top->index;
		if (index != max1 && index != max2 && index != max3)
			ft_pb(a, b);
		else
			ft_ra(a);
	}
}

void	ft_sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first < second && second > third && third > first)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (first > second && second < third && third > first)
		ft_sa(a);
	else if (first < second && second > third && third < first)
		ft_rra(a);
	else if (first > second && second < third && third < first)
		ft_ra(a);
	else if (first > second && second > third && third < first)
	{
		ft_sa(a);
		ft_rra(a);
	}
}

void	ft_sort_two(t_stack *a)
{
	ft_sa(a);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	len;

	len = a->size;
	if (len == 2)
	{
		ft_sort_two(a);
		return ;
	}
	else if (len == 3)
	{
		ft_sort_three(a);
		return ;
	}
	else
	{
		ft_move_except_top_three_to_b(a, b);
		ft_sort_three(a);
		ft_push_all_to_a(a, b);
		ft_move_index_0_to_top(a);
	}
}
