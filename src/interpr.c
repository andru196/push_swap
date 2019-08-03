/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:35:09 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/27 14:42:23 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*sort_params(t_psl *lst, int n)
{
	int		*rez;
	t_psl	*l;
	int		max;
	int		i;

	if (!(rez = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	i = n - 1;
	while (n--)
	{
		l = lst;
		max = -2147483648;
		while (l)
		{
			if (l->num > max && (n == i || l->num < rez[n + 1]))
				max = l->num;
			l = l->next;
		}
		rez[n] = max;
	}
	return (rez);
}

void		print_win(t_psl *lst, int n)
{
	int *arr;
	int i;

	arr = sort_params(lst, n);
	i = 0;
	ft_printf("{green}how bad: %d\n", only_r(lst));
	while (i < n)
		ft_printf("%d ", arr[i++]);
	ft_printf("\n{red}");
	while (lst)
	{
		ft_printf("%d ", lst->num);
		lst = lst->next;
	}
	ft_printf("{eoc}\n");
}

static void	read_and_ex(t_psl **a, t_psl **b, t_ins *commands[COMANDS],
	t_list **lst)
{
	char	*str;

	str = NULL;
	while (get_next_line(0, &str) && ft_strlen(str))
	{
		if (do_it(str, commands, a, b))
			ft_lstladd(lst, ft_lstnew(str, ft_strlen(str)));
		print_stack(*a, *b, 1);
		ft_memdel((void **)&str);
	}
}

int			main(int argc, char **argv)
{
	t_psl	*stack_a;
	t_psl	*stack_b;
	t_list	*lst;
	t_ins	*commands[COMANDS];

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ps_create_stack(--argc, ++argv);
	lst = NULL;
	print_win(stack_a, argc);
	if (!(fill_ins(commands)))
		error(stack_a, stack_b, commands, lst);
	read_and_ex(&stack_a, &stack_b, commands, &lst);
	ft_putendl("\nLog:");
	while (lst)
	{
		ft_putstr((char *)lst->content);
		lst = lst->next;
	}
	ft_putendl(check_stack(stack_a, argc, 1) ? "OK" : "KO!");
	freesher(stack_a, stack_b, commands, lst);
	return (0);
}
