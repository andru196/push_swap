/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:07:49 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 18:05:40 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_module(t_list *lst, t_ins *com[COMANDS], t_psl *a)
{
	t_list	*ll;
	int		i;

	i = -1;
	while (++i < COMANDS)
		if (com[i])
			free(com[i]);
	ll = lst;
	while (lst)
	{
		lst = lst->next;
		free(ll);
		ll = lst;
	}
	ll = (t_list *)a;
	while (a)
	{
		a = a->next;
		free(ll);
		ll = (t_list *)a;
	}
	
}

t_ins		*command(char **str, t_ins *com[COMANDS])
{
	char	ins[4];
	int		i;
	char	*ss;
	int		j;

	i = 0;
	ss = *str;
	while (*ss)
	{
		if (*ss == '\n')
		{
			ss++;
			*str += 1 + i;
			if (i)
			{
				j = 0;
				while (ft_strcmp(ins, com[j]->name))
					j++;
				return (com[j]);
			}
		}
		else
			ins[i++] = *ss++;		
	}
	return (NULL);
}

t_list	*newcom(t_ins *new)
{
	t_list *rez;

	if ((rez = ft_lstnew(NULL, 0)))
		rez->content = new;
	return (rez);
}

t_list	*comman_list(char **str, t_ins *com[COMANDS])
{
	t_list	*lst;
	t_list	*rez;

	rez = NULL;
	while (**str)
	{
		if (**str == '\n')
			*str += 1;
		else
		{
			if (!rez)
			{
				rez = newcom(command(str, com));
				lst = rez;
			}
			else
			{
				lst->next = newcom(command(str, com));
				lst = lst->next;
			}
		}
	}
	return (rez);
}

void	finish_print(t_psl *stack_a, char *str, int fl[6])
{
	t_psl	*stack_b;
	t_ins	*com[COMANDS];
	t_list	*lst;

	stack_b = NULL;
	if (!(fill_ins(com)))
		error(stack_a, NULL, com, NULL);
	lst = comman_list(&str, com);
	print_me(fl, lst, &stack_a, &stack_b);
	del_module(lst, com, NULL);
}