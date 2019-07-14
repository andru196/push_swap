/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descent_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:02:43 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/13 13:47:45 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			is_bottom(t_psl *a, int *arr, int n)
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
	while (a)
	{
		if ((a->next && (a->num > a->next->num || a->next->num > num))
			|| a->num > num)
			return (0);
		a = a->next;
	}
	return (1);
}

char	*swap_method(t_psl **a, t_psl **b, int *arr, int n)
{
	if (!is_bottom((*a), arr, n))
		return (ex_command("pb", pb, a, b));
	else if ((*b) && (*b)->next && ((*b)->num < (*b)->next->num))
		return (ex_command("ss", ss, a, b));
	else
		return (ex_command("sa", sa, a, b));
}

char	*rotate_method(t_psl **a, t_psl **b, int *arr, int n)
{
	t_psl	*lst;
	int		f;
	int		*stumb;

	f = 0;
	lst = *b;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		f += lst->num > (*b)->num && (*b)->num < (*b)->next->num;
		f += 2 * (lst->num > (*b)->num && (*b)->num > (*b)->next->num);	
		if ((*b)->next && (*b)->num < (*b)->next->num && !f)
			return (ex_command("sb", sb, a, b));
		else if (f == 1)
			return (ex_command("rb", rb, a, b));
		else if(f == 2)
			return (ex_command("rrb", rrb, a, b));
		else
			return (ex_command("pb", pb, a, b));
		stumb = arr;
		stumb[n - 1] = arr[n - 1];
	}
	else
		return (ex_command("pb", pb, a, b));
}