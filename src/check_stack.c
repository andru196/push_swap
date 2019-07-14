/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:34:05 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/07 15:54:23 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack(t_psl *stack_a, int argc, int order)
{
	if (order != 1)
		order = -1;
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if ((long)order * (long)stack_a->num >=
			(long)order * (long)stack_a->next->num)
			return (0);
		stack_a = stack_a->next;
		argc--;
	}
	return (argc == 1);
}
