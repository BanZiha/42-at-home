/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:13:08 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:01 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_already_sorted(t_stack *stack)
{
	t_list	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

int	ft_check_duplicate(t_stack *stack, long long number)
{
	t_list	*current;

	if (number > INT_MAX || number < INT_MIN)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->content == (int)number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_is_valid_integer(char *str)
{
	long long	num;
	int			sign;

	sign = 1;
	num = 0;
	if (!*str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

long long	ft_atoll(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
