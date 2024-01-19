/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startfinish_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:21:07 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/27 15:43:13 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*short_way(t_psl **stack_a, int *arr)
{
	int		i;
	int		j;
	t_psl	*lst;
	char	*rez;

	lst = *stack_a;
	i = 0;
	while (lst)
	{
		if (lst->num != arr[i])
			break ;
		i++;
		lst = lst->next;
	}
	rez = NULL;
	if (i > ((j = lstlen(*stack_a)) / 2))
	{
		i = j - i;
		while (i--)
			rez = norm_str(stack_a, rez, "rra");
	}
	return (rez);
}

int		short_climb(t_psl **a, t_psl **b, int *arr)
{
	int		i;
	t_psl	*lst;

	i = 0;
	if (!*b)
	{
		lst = *a;
		while (lst->num != arr[0])
		{
			i++;
			lst = lst->next;
		}
		return ((i <= ((lstlen(*a) / 2)) && only_r(*a) == 1) ? 3 : 1);
	}
	else
	{
		lst = *b;
		while (lst->next)
			lst = lst->next;
		return (lst->num <= (*b)->num ? 1 : 2);
	}
}
