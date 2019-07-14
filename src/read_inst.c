/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:28:56 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 17:39:45 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*error_read(t_list **lt, char *str, t_ins *arr[COMANDS])
{
	t_list	*ll;
	t_list	*lst;

	lst = *lt;
	while (lst)
	{
		ll = lst;
		lst = lst->next;
		if (ll->content)
			free(ll->content);
		free(ll);
		ll = lst;
	}
	if (str)
		free(str);
	*lt = NULL;
	error_commands(arr);
	return ((t_list *)-1);
}

t_list			*read_answers(t_ins *arr[COMANDS])
{
	char	*a;
	int		i;
	t_list	*lst;
	t_list	*rez;

	rez = NULL;
	lst = NULL;
	while (get_next_line(0, &a) && (i = ft_strlen(a)))
	{
		if (!lst)
		{
			if (!(lst = ft_lstnew(NULL, 0)) || !do_it(a, arr, NULL, NULL))
				return (error_read(&lst, a, arr));
		}
		else
		{
			if (!(lst->next = ft_lstnew(NULL, 0)) || !do_it(a, arr, NULL, NULL))
				return (error_read(&rez, a, arr));
			lst = lst->next;
		}
		rez = rez ? rez : lst;
		lst->content = a;
		lst->content_size = i;
	}
	return (rez);
}
