/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:14:14 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/04 18:52:33 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_psl **a, t_psl **b)
{
	t_psl	*a_lst;
	t_psl	*lst;

	if ((!a && !b) || !(a_lst = *a) || !(*a)->next)
		return ;
	*a = a_lst->next;
	lst = a_lst;
	while (lst->next)
		lst = lst->next;
	lst->next = a_lst;
	a_lst->next = NULL;
}

void	rb(t_psl **a, t_psl **b)
{
	ra(b, a);
}

void	rr(t_psl **a, t_psl **b)
{
	ra(a, b);
	rb(a, b);
}
