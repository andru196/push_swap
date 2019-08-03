/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:07:01 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/08/03 17:12:07 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define COMANDS 11
# define BDY "%q%-3s X  %2d\n"
# include "libft.h"
# include <fcntl.h>

typedef struct		s_psl
{
	int				num;
	struct s_psl	*next;
}					t_psl;
typedef struct		s_ins
{
	char			*name;
	void			(*ins)(t_psl **a, t_psl **b);
}					t_ins;

t_psl				*ps_create_stack(int argc, char **argv);
int					check_stack(t_psl *stack_a, int argc, int order);
int					do_it(char *str, t_ins *arr[COMANDS], t_psl **a, t_psl **b);
int					fill_ins(t_ins *arr[COMANDS]);
t_list				*read_answers(t_ins *arr[COMANDS], int fd);
void				sa(t_psl **a, t_psl **b);
void				sb(t_psl **a, t_psl **b);
void				ss(t_psl **a, t_psl **b);
void				pa(t_psl **a, t_psl **b);
void				pb(t_psl **a, t_psl **b);
void				ra(t_psl **a, t_psl **b);
void				rb(t_psl **a, t_psl **b);
void				rr(t_psl **a, t_psl **b);
void				rra(t_psl **a, t_psl **b);
void				rrb(t_psl **a, t_psl **b);
void				rrr(t_psl **a, t_psl **b);
void				error_commands(t_ins *arr[COMANDS]);
void				error_stack(t_psl *rez);
void				error(t_psl *a, t_psl *b, t_ins *commands[COMANDS],
					t_list *lst);
void				freesher(t_psl *a, t_psl *b, t_ins *commands[COMANDS],
					t_list *lst);
void				print_stack(t_psl *a, t_psl *b, int fd);
int					only_r(t_psl *lst);
int					lstlen(t_psl *a);
char				*execute(t_psl **a, t_psl **b, int *arr, int n);
char				*hard_mode(t_psl **a, t_psl **b, int *arr, int n);
int					track_an(t_psl *stack);
char				*immersion(t_psl **a, t_psl **b, int *arr, int n);
char				*ex_command(char *str, void (*ins)(t_psl **a,
					t_psl **b), t_psl **a, t_psl **b);
char				*swap_method(t_psl **a, t_psl **b, int *arr, int n);
char				*rotate_method(t_psl **a, t_psl **b);
char				*climb(t_psl **a, t_psl **b, int *arr, int n);
char				*ex_a_copy(char **str, char **part);
void				finish_print(t_psl *stack_a, char *str, int fl[6]);
void				print_me(int fl[6], t_list *lst, t_psl **a, t_psl **b);
char				*norm_str(t_psl **a, char *dst, char *src);
char				*short_way(t_psl **stack_a, int *arr);
int					short_climb(t_psl **a, t_psl **b, int *arr);
char				*swap_this(t_psl **a);
char				*rotate_right(t_psl **a, int s);

#endif
