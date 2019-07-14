/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:31:51 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/03 19:59:10 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_psl **a, t_psl **b)
{
	t_psl	*a_lst;
	t_psl	*lst;

	if ((!a && !b) || !(a_lst = *a) || !(*a)->next)
		return ;
	lst = a_lst;
	while (lst->next->next)
		lst = lst->next;
	*a = lst->next;
	lst->next = NULL;
	(*a)->next = a_lst;
}

void	rrb(t_psl **a, t_psl **b)
{
	rra(b, a);
}

void	rrr(t_psl **a, t_psl **b)
{
	rra(b, a);
	rra(a, b);
}
