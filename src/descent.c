/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:54:42 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 16:21:23 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_bottom(t_psl *a, int *arr, int n)
{
	int		num;
	int		i;
	int		f;

	if (!a || (a && a->next && (lstlen(a) == 2 && (a->num < a->next->num 
		&& a->next->num) ^ (a->num == arr[n - 1]))))
		return (1);
	i = 0;
	while (arr[i] != a->num)
		i++;
	f = 1;
	while (a && i < n)
	{
		num = a->num;
		if (arr[i++] != num && (f = 0))
			break ;
		a = a->next;
	}
	while (i == n && a)
	{
		if (a->next && a->next->num < a->num && (f = 1))
			return (0);
		a = a->next;
	}
	return (f);
}

static int	right_place(t_psl *a) //int *arr, int n)
{
	int	num;
	int	f;

	num = a->num;
	a = a->next;
	f = 0;
	while (a)
	{
		if (num > a->num)
			{
				f = 1;
				break ;
			}
		a = a->next;
	}
	while (f && a->next)
	{
		if (num < a->num)
			return (0);
		a = a->next;
	}
	return (!a);
	
}

static int	p_or_r(t_psl *a, t_psl *b, int *arr, int n)
{
	int	i;
	int	num;

	num = a->num;
	if (b && num < b->num) // не учитывается, что можно свапнуть
		return (0);
	i = 0;
	while (arr[i] != num && i < n)
		i++;
	/*
		какой-то код, подвергающий сомнению, что ретурн 1, а не 0
	*/
	return (1);
}

static char	*rr_ra(t_psl **a, t_psl **b)
{
	t_psl	*lst;

	lst = *b;
	while (lst->next)
		lst = lst->next;
	if (lst->num > (*b)->num && (*b)->num < (*b)->next->num)
		return (ex_command("rr", rr, a, b));
	else
		return (ex_command("ra", ra, a, b));
}

char			*immersion(t_psl **a, t_psl **b, int *arr, int n)
{
	if (is_bottom(*a, arr, n))
		return (NULL);
	else if ((*a)->next && (*a)->next->num < (*a)->num)
		return (swap_method(a, b, arr, n));
	else if (!right_place(*a))
		return (rotate_method(a, b, arr, n));
	else 
	{
		if (p_or_r(*a, *b, arr, n))
			return (ex_command("pb", pb, a, b));
		else 
			return (rr_ra(a, b));
	}
}