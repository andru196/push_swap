/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:43:40 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/03 19:17:16 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_psl **a, t_psl **b)
{
	t_psl	*lst;

	if ((!a && !b) || !(*a) || !((*a)->next))
		return ;
	lst = *a;
	*a = (*a)->next;
	lst->next = (*a)->next;
	(*a)->next = lst;
}

void	sb(t_psl **a, t_psl **b)
{
	sa(b, a);
}

void	ss(t_psl **a, t_psl **b)
{
	sa(a, b);
	sa(b, a);
}
