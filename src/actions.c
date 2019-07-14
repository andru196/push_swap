/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:40:14 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 17:40:10 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			error_commands(t_ins *arr[COMANDS])
{
	int i;

	if (arr)
		{
		i = 0;
		while (i < COMANDS)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
	}
}

static t_ins	*ft_lstinsadd(char *str, void (*f)(t_psl **a, t_psl **b))
{
	t_ins	*rez;

	rez = (t_ins *)malloc(sizeof(t_ins));
	if (!rez)
		return (NULL);
	rez->ins = f;
	rez->name = ft_strdup(str);
	return (rez);
}

int				fill_ins(t_ins *arr[COMANDS])
{
	int i;

	i = 0;
	arr[i++] = ft_lstinsadd("pa", pa);
	arr[i++] = ft_lstinsadd("pb", pb);
	arr[i++] = ft_lstinsadd("sa", sa);
	arr[i++] = ft_lstinsadd("sb", sb);
	arr[i++] = ft_lstinsadd("ss", ss);
	arr[i++] = ft_lstinsadd("ra", ra);
	arr[i++] = ft_lstinsadd("rb", rb);
	arr[i++] = ft_lstinsadd("rr", rr);
	arr[i++] = ft_lstinsadd("rra", rra);
	arr[i++] = ft_lstinsadd("rrb", rrb);
	arr[i++] = ft_lstinsadd("rrr", rrr);
	while (i--)
		if (!arr[i])
			return (0);
	return (1);
}

int				do_it(char *str, t_ins *arr[COMANDS], t_psl **a, t_psl **b)
{
	int i;

	i = 0;
	while (i < COMANDS && ft_strcmp(arr[i]->name, str))
		i++;
	if (i < COMANDS && (a || b))
		arr[i]->ins(a, b);
	return (i != COMANDS);
}
