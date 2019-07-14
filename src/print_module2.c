/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_module2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:45:23 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 15:42:30 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_psl *a, t_psl *b)
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
			ft_printf("%5d", a->num);
			a = a->next;
		}
		ft_printf("%s  %s", i <= k ? "     " : "", j <= k ? "     " : "");
		if (j > k)
		{
			ft_printf("%5d", b->num);
			b = b->next;
		}
		ft_putendl("");
	}
	ft_putendl("  a    b");
	ft_putendl("_____________________");
	ft_putendl("");
}

int		same_cnt(t_list *lst)
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

void	print_me(int fl[6], t_list *lst, t_psl **a, t_psl **b)
{
	int	i;

	while (lst)
	{
		i = same_cnt(lst);
		if (fl[2])
		{
			if (i == ft_lstlen(lst) && fl[4])
				ft_printf("{green}");
			ft_printf("%-3s X  %2d\n", (((t_ins *)lst->content)->name), i);
		}
		while (i--)
		{
			if (fl[4] && ft_lstlen(lst) == 1 && !fl[2])
				ft_printf("{green}");
			((t_ins *)lst->content)->ins(a, b);
			if (!fl[2])
				ft_putendl(((t_ins *)lst->content)->name);
			if ((!fl[2] || (fl[2] && i == 0)) && (fl[0] || fl[3] >= ft_lstlen(lst)))
				print_stack(*a, *b);
			if (fl[4] && ft_lstlen(lst) == 1)
				ft_printf("{eoc}");
			lst = lst->next;	
		}
	}
}