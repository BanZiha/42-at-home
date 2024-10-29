/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:27:39 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:03 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*compare;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare != current && compare->content < current->content)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}

int	ft_add_arguments_to_stack(t_stack *stack, int argc, char **argv)
{
	int			i;
	long long	number;
	t_list		*new_node;

	i = 1;
	while (i < argc)
	{
		number = ft_atoll(argv[i]);
		if (!ft_is_valid_integer(argv[i]) || !ft_check_duplicate(stack, number))
		{
			write(2, "Error\n", 6);
			ft_free_stack(stack);
			return (0);
		}
		new_node = ft_create_node(number);
		if (!new_node)
		{
			ft_free_stack(stack);
			return (0);
		}
		ft_add_node_end(stack, new_node);
		i++;
	}
	return (1);
}

t_stack	*ft_initialize_stack(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_create_stack();
	if (!stack)
		return (NULL);
	if (!ft_add_arguments_to_stack(stack, argc, argv))
		return (NULL);
	return (stack);
}

int	ft_check_stack(int argc, char **argv, t_stack **stack_a)
{
	*stack_a = ft_initialize_stack(argc, argv);
	if (!*stack_a)
		return (1);
	ft_index_stack(*stack_a);
	if (ft_is_already_sorted(*stack_a))
	{
		ft_free_stack(*stack_a);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (ft_check_stack(argc, argv, &stack_a))
		return (0);
	stack_b = ft_create_stack();
	if (!stack_b)
	{
		ft_free_stack(stack_a);
		return (1);
	}
	ft_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
