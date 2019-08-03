/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descent_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:02:43 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/08/03 18:23:37 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_bottom_hlp(t_psl *a, int num)
{
	while (a)
	{
		if ((a->next && (a->num > a->next->num || a->next->num > num))
			|| a->num > num)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	is_bottom(t_psl *a, int *arr, int n)
{
	int	i;
	int	j;
	int	num;

	if (!(a->next->next))
		return (1);
	i = 0;
	while (arr[i] != a->num)
		i++;
	j = 0;
	num = a->num;
	a = a->next->next;
	while (a && n > i + j)
	{
		if (arr[i + j++] != a->num)
			break ;
		a = a->next;
	}
	if (i != (n - j))
		return (0);
	return (is_bottom_hlp(a, num));
}

char		*swap_method(t_psl **a, t_psl **b, int *arr, int n)
{
	if (!is_bottom((*a), arr, n))
		//return (ex_command("pb", pb, a, b));
		return (rotate_method(a, b));
	else if ((*b) && (*b)->next && ((*b)->num < (*b)->next->num))
		return (ex_command("ss", ss, a, b));
	else
		return (ex_command("sa", sa, a, b));
}

static int need_num(t_psl *b, int num)
{
	int n_p_1;
	int n_m_1;
	int fl;

	n_m_1 = 0x80000000;
	n_p_1 = n_m_1 - 1;
	fl = 0;
	
	while (b)
	{
		if (b->num < num && b->num > n_m_1)
		{
			n_m_1 = b->num;
			fl = 1;
		}
		else if (b->num > num && b->num < n_p_1)
			n_p_1 = b->num;
		b = b->next;
	}
	return (fl ? n_m_1 : n_p_1);
}

static int	win(t_psl *b, int num)
{
	int		n;
	int		len;
	int		i;

	len = lstlen(b);
	if (len < 2)
		return (0);
	n = need_num(b, num);
	i = 0;
	while (b->num != n)
	{
		i++;
		b = b->next;
	}
	if (i == 0 || i == len - 1)
		return (0);
	return (i >= len / 2 ? 2 : 1);
}

char		*rotate_method(t_psl **a, t_psl **b)
{
	int		f;

	f = 0;
	if (*b && (*b)->num != need_num(*b, (*a)->num))
	{
		f = win(*b, (*a)->num);
		if ((*b)->next && (*b)->num < (*b)->next->num && !f)
		{
			if (*a && (*a)->next && (*a)->next->num < (*a)->num)
				return (ex_command("ss", ss, a, b));
			else
				return (ex_command("sb", sb, a, b));
		}
		else if (f == 1)
			return (ex_command("rb", rb, a, b));
		else if (f == 2)
			return (ex_command("rrb", rrb, a, b));
	}
	return (ex_command("pb", pb, a, b));
}

