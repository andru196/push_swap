/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:57:34 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/03 19:17:57 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_psl **a, t_psl **b)
{
	t_psl	*lst;

	if (!(*b))
		return ;
	lst = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = lst;
}

void	pb(t_psl **a, t_psl **b)
{
	pa(b, a);
}
