/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:38:28 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 17:05:51 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		freesher(t_psl *a, t_psl *b, t_ins *commands[COMANDS], t_list *lst)
{
	int		i;
	t_list	*cpy;

	if (a)
		error_stack(a);
	if (b)
		error_stack(b);
	while (lst)
	{
		cpy = lst;
		lst = lst->next;
		if (cpy->content)
			free(cpy->content);
		free(cpy);
		cpy = lst;
	}
	i = 0;
	if (commands)
		while (i < COMANDS)
			free(commands[i++]);
}

void		error(t_psl *a, t_psl *b, t_ins *commands[COMANDS], t_list *lst)
{
	freesher(a, b, commands, lst);
	write(1, "Error\n", 6);
	exit(1);
}

int	lstlen(t_psl *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
