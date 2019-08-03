/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:15:31 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/21 16:58:37 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ex_command(char *str, void (*ins)
	(t_psl **a, t_psl **b), t_psl **a, t_psl **b)
{
	ins(a, b);
	return (ft_strdup(str));
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
			str = ex_command("sa", sa, a, NULL);
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
