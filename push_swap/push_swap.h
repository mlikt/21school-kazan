#ifndef PUSH_SWAP_H
# define	PUSH_SWAP_H
# include	"./libft/libft.h"

typedef struct s_list
{
	unsigned int	order;
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;
void			swap(t_list **list);
void			rotate_revers(t_list **list);
void			rotate(t_list **list);
void			push(t_list **rec, t_list **src);
t_list			*new_list(int *arr, int amount);
t_list			*last_elem(t_list *list);
void			sa(t_list **A);
void			sb(t_list **B);
void			ra(t_list **A);
void			rb(t_list **B);
void			rr(t_list **A, t_list **B);
void			rra(t_list **A);
void			rrb(t_list **B);
void			rrr(t_list **A, t_list **B);
void			pa(t_list **A, t_list **B);
void			pb(t_list **A, t_list **B);
t_list			*new_elem(int i, t_list *prev);
t_list			*new_list(int *arr, int amount);
t_list			*duplicate(t_list *list);
unsigned int	count_elem(t_list *list);
void			remove_elem(t_list **list, unsigned int i);
void			find_min_assign_order(t_list *list, unsigned int i);
void			copy_order(t_list *dst, t_list *src, unsigned int i);
void			get_order(t_list *list);
t_list			*get_list_from_argv(char *argv);
unsigned int	find_max(t_list *list);
unsigned int	find_min(t_list *list);
int				*get_arr_argv(char **argv, int argc);
t_list			*last_elem(t_list *list);
int				validation_argv(int argc, char **argv);
int				validation_list(t_list *checker);
void			sort_small_list(t_list **A, unsigned int count);
int				dist_from_start(t_list *list, unsigned int order);
int				check_sort(t_list *list, int direction);
void			sort(t_list **A);
#endif