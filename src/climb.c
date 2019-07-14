/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:40:34 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 15:30:13 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_finish(t_psl **a, t_psl **b)
{
	t_psl	*lst;
	int		num;
	
	if (*b)
		return (0);
	lst = *a;
	num = lst->num;
	while (lst)
	{
		if (lst->num < num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	need_num(t_psl *a, int *arr, int n)
{
	t_psl	*lst;
	int		num;
	int		i;

	i = 0;
	lst = a;
	num = lst->num;
	while (arr[i] != num)
		i++;
	while (lst->next)
		lst = lst->next;
	if (i && lst->num == arr[i - 1])
		return (0);
	else if (!i && arr[n - 1] == lst->num)
		return (0);
	return (1);
}

int			win(t_psl *a, int *arr, int n)
{
	int	i;

	i = 0;
	while (arr[i] != a->num)
		i++;
	if (i)
		return (arr[i - 1]);
	return (arr[n - 1]);
}

int			need_up(t_psl *b, int num, int n)
{
	int i;

	i = 0;
	while (b->num != num)
	{
		b = b->next;
		i++;
	}
	return (n / 2 > i);
}

char		*climb(t_psl **a, t_psl **b, int *arr, int n)
{
	int num;

	if (is_finish(a, b))
		return (0);
	if (need_num(*a, arr, n))
	{
		num = win(*a, arr, n);
		if (num == (*b)->num)
			return (ex_command("pa", pa, a, b));
		else if ((*b) && (*b)->next && num == (*b)->next->num && (*b)->next->num >(*b)->num)
			return (ex_command("sb", sb, a, b));
		else
		{
			if (need_up(*b, num, n))
				return (ex_command("rb", rb, a, b));
			else
				return (ex_command("rrb", rrb, a, b));
		}
	}
	else
		if ((num = short_climb(a, b, arr)) == 1)
			return (ex_command("rra", rra, a, b));
		else if (num == 2)
			return (ex_command("rrr", rrr, a, b));
		return (ex_command("ra", ra, a, b));
}
