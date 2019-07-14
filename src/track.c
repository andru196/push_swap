/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:58:07 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/07 18:01:11 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ищем самую длинную последовательность

int 	track_re(t_psl *stack, int count)
{
	t_psl	*lst;
	int		num;
	int		max;
	int		tmp;

	num = stack->num;
	lst = stack;
	max = count;
	while (lst->next)
	{
		if (lst->next->num > num)
		{
			tmp = track_re(lst->next, count + 1);
			max = tmp > max ? tmp : max;
		}
		lst = lst->next;
		
	}
	return (max);
}

int 	track_an(t_psl *stack)
{
	int		num;
	int		max;
	t_psl	*ll;
	int		max_n;

	max = 0;
	max_n = stack->num;
	ll = stack;
	while (ll)
	{
		if (ll->num <= max_n)
		{
				num = track_re(ll, 0);
			if (num > max)
			{
				max = num;
				max_n = ll->num;
			}
		}
		ll = ll->next;
	}
	return (max + 1);
}