/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:44:26 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/13 19:04:37 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		only_r(t_psl *lst)
{
	int i;
	int	j;

	i = 0;
	j = lst->num;
	while (lst->next)
	{
		if (i && (lst->next->num > j || lst->num > j))
			i++;
		if (lst->num > lst->next->num)
		{
			i++;
			if (lst->next->num > j)
				i++;
		}	
		lst = lst->next;
	}
	return (i);
}

int		only_s(t_psl *lst, int *arr)
{
	int i;

	i = 0;
	while (lst->next)
	{
		if (lst->num > lst->next->num)
			if (lst->num != arr[i + 1] || lst->next->num != arr[i])
				return (0);
		i++;
		lst = lst->next;
	}
	return (1);
}

int		where_break(t_psl *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		if (a->num > a->next->num)
			return (i);
		a = a->next;
	}
	return (i);
}

 static char	*rotate_right(t_psl **a, int s)
{
	int		i;
	int		len;
	char	*str;
	char	*rez;

	rez = NULL;
	i = where_break(*a);
	len = lstlen(*a);
	if (i > len / 2)
	{
		i = len - i;
		while (i-- + s)
		{
			str = ex_command("rra", rra, a, NULL);
			if (!(rez = ex_a_copy(&rez, &str)))
				return (NULL);
		}
	}
	else
	{
		while (i-- - s)
		{
			str = ex_command("ra", ra, a, NULL);
			if (!(rez = ex_a_copy(&rez, &str)))
				return (NULL);
		}
	}
	return (rez);
}

char	*swap_this(t_psl **a)
{
	int		f;
	char	*rez;
	char	*str;

	rez = NULL;
	while ((f = only_r(*a)) > 1)
	{
		if (!(str = rotate_right(a, 1)))
			str = ex_command("sa", sa, a , NULL);
		if (!(rez = ex_a_copy(&rez, &str)))
			return (NULL);
	}
	while (only_r(*a) == 1)
	{
		str = rotate_right(a, 0);
		if (!(rez = ex_a_copy(&rez, &str)))
			return (NULL);
	}
	return (rez);
}

char	*execute(t_psl **a, t_psl **b, int *arr, int n)
{
	char	*str;
	char	*rez;
	int		f;

	f = only_s(*a, arr);
	rez = NULL;
	while (!f && only_r(*a) == 1)
	{
		f = 2;
		str = rotate_right(a, 0);
		if (!(rez = ex_a_copy(&rez, &str)))
			return (NULL);
	}
	if (f == 1)
	{
		rez = swap_this(a);
	}
	if (f == 0)
		rez = hard_mode(a, b, arr, n);
	return (rez);
}