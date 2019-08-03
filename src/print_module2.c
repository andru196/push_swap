/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_module2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:45:23 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/26 17:44:38 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_psl *a, t_psl *b, int fd)
{
	int	i;
	int	j;
	int k;

	i = lstlen(a);
	j = lstlen(b);
	k = i > j ? i : j;
	while (k--)
	{
		if (i > k)
		{
			ft_printf("%q%5d", fd, a->num);
			a = a->next;
		}
		ft_printf("%q%s  %s", fd, i <= k ? "     " : "", j <= k ? "     " : "");
		if (j > k)
		{
			ft_printf("%q%5d", fd, b->num);
			b = b->next;
		}
		ft_putendl_fd("", fd);
	}
	ft_putendl_fd("    a      b", fd);
	ft_putendl_fd("_____________________", fd);
	ft_putendl_fd("", fd);
}

int			same_cnt(t_list *lst)
{
	void	*pnt;
	int		i;

	i = 1;
	pnt = lst->content;
	lst = lst->next;
	while (lst && lst->content == pnt)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void		print_me(int fl[6], t_list *lst, t_psl **a, t_psl **b)
{
	int	i;

	while (lst)
	{
		i = same_cnt(lst);
		if (fl[2])
		{
			if (i == ft_lstlen(lst) && fl[4])
				ft_printf("%q{green}", fl[1]);
			ft_printf(BDY, fl[1], (((t_ins *)lst->content)->name), i);
		}
		while (i--)
		{
			if (fl[4] && ft_lstlen(lst) == 1 && !fl[2])
				ft_printf("%q{green}", fl[1]);
			((t_ins *)lst->content)->ins(a, b);
			if (!fl[2])
				ft_putendl_fd(((t_ins *)lst->content)->name, fl[1]);
			if ((!fl[2] || (fl[2] && !i)) && (fl[0] || fl[3] >= ft_lstlen(lst)))
				print_stack(*a, *b, fl[1]);
			if (fl[4] && ft_lstlen(lst) == 1)
				ft_printf("%q{eoc}", fl[1]);
			lst = lst->next;
		}
	}
}
