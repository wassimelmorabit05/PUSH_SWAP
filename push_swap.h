#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_ps_list
{
	int					value;
	int					index;
	struct s_ps_list	*next;
}	t_ps_list;

// swap.c
void		swap(t_ps_list **head);
void		sa(t_ps_list **a);
void		sb(t_ps_list **b);
void		ss(t_ps_list **a, t_ps_list **b);

// push.c
void		push(t_ps_list **src, t_ps_list **dest);
void		pa(t_ps_list **src, t_ps_list **dest);
void		pb(t_ps_list **src, t_ps_list **dest);

// rotate.c
void		rotate(t_ps_list **head);
void		ra(t_ps_list **s_a);
void		rb(t_ps_list **s_b);
void		rr(t_ps_list **s_a, t_ps_list **s_b);

// rrotate.c
void		rrotate(t_ps_list **head);
void		rra(t_ps_list **s_a);
void		rrb(t_ps_list **s_b);
void		rrr(t_ps_list **s_a, t_ps_list **s_b);

// check_args
char		**check_args(int ac, char **av);
int			check_is_num(char **args);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi_pushswap(char *str, int *error);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);

// stack_utils.c
t_ps_list	*create_node(int va);
void		add_back(t_ps_list **head, t_ps_list *new);
int			has_duplicates(t_ps_list *node, int nb);
int			list_size(t_ps_list *node);
void		free_list(t_ps_list **head);

// utils.c
int			is_sorted(t_ps_list *node);
void		free_split(char **args);

// sort_one.c
void		getindex(t_ps_list **stack);
t_ps_list	*find_max(t_ps_list *stack);
void		sort_three(t_ps_list **stack);
void		sort_four(t_ps_list **stack_a, t_ps_list **stack_b);
void		sort_five(t_ps_list **stack_a, t_ps_list **stack_b);
void		sort_big(t_ps_list **stack_a, t_ps_list **stack_b);

#endif
