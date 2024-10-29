/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:00:44 by hyunwook          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:00 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	int		size;
	t_list	*top;
	t_list	*bottom;
}			t_stack;

// main.c
t_stack		*ft_initialize_stack(int argc, char **argv);
void		ft_index_stack(t_stack *stack);
int			ft_add_arguments_to_stack(t_stack *stack, int argc, char **argv);
int			ft_check_stack(int argc, char **argv, t_stack **stack_a);

// doubly_linked_list.c
t_list		*ft_create_node(int content);
void		ft_add_node_front(t_stack *stack, t_list *new_node);
void		ft_add_node_end(t_stack *stack, t_list *new_node);
void		ft_remove_node(t_stack *stack, t_list *node);
void		ft_free_stack(t_stack *stack);

// push_swap_utils.c
long long	ft_atoll(const char *str);
t_stack		*ft_create_stack(void);
int			ft_check_duplicate(t_stack *stack, long long number);
int			ft_is_already_sorted(t_stack *stack);
int			ft_is_valid_integer(char *str);

// stack_commands.c
void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);
void		ft_sa(t_stack *a);
void		ft_sb(t_stack *b);
void		ft_ss(t_stack *a, t_stack *b);
void		ft_ra(t_stack *a);
void		ft_rb(t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rra(t_stack *a);
void		ft_rrb(t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);

// greedy_sort.c
void		ft_sort(t_stack *a, t_stack *b);
void		ft_sort_two(t_stack *a);
void		ft_sort_three(t_stack *a);
void		ft_move_except_top_three_to_b(t_stack *a, t_stack *b);
void		ft_find_top_three(t_stack *a, int *max1, int *max2, int *max3);
void		ft_update_max_indices(int index, int *max1, int *max2, int *max3);
int			ft_get_move_count_to_top(t_stack *stack, int index);
int			ft_get_insert_position(t_stack *a, int value);
int			ft_find_min_moves(t_stack *a, t_stack *b, int *b_index);
void		ft_move_to_top_b(t_stack *b, int b_index);
void		ft_move_to_top_a(t_stack *a, int pos_in_a);
void		ft_push_all_to_a(t_stack *a, t_stack *b);
void		ft_move_index_0_to_top(t_stack *a);

#endif