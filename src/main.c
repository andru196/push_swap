/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:02:03 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 17:40:23 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_psl	*stack_a;
	t_psl	*stack_b;
	t_list	*lst;
	t_list	*start;
	t_ins	*commands[COMANDS];

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	lst = NULL;
	stack_a = ps_create_stack(--argc, ++argv);
	if (!(fill_ins(commands)))
		error(stack_a, stack_b, commands, lst);
	if ((lst = read_answers(commands)) == (t_list *)-1)
		error(stack_a, stack_b, NULL, NULL);
	start = lst;
	while (lst)
	{
		do_it(lst->content, commands, &stack_a, &stack_b);
		lst = lst->next;
	}
	ft_putendl(check_stack(stack_a, argc, 1) ? "OK" : "KO!");
	freesher(stack_a, stack_b, commands, start);
	return (0);
}
