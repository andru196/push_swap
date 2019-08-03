/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:02:03 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/26 18:31:07 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_what_read(t_psl **a, t_psl **b,
	t_list *lst, t_ins *commands[COMANDS])
{
	while (lst)
	{
		do_it(lst->content, commands, a, b);
		lst = lst->next;
	}
}

static int	check(int c, char **v, int *f)
{
	int j;
	int i;

	i = 0;
	j = 0;
	*f = 0;
	while (i < c)
	{
		if (!*v[i])
			j++;
		else if (!ft_strcmp(v[i], "-f"))
		{
			*v[i] = '\0';
			*f = *f ? *f : (open("log.txt", O_RDONLY));
			if (*f == -1)
				*f = 0;
			j++;
		}
		i++;
	}
	return (j);
}

int			main(int argc, char **argv)
{
	t_psl	*stack_a;
	t_psl	*stack_b;
	t_list	*lst;
	t_ins	*commands[COMANDS];
	int		f;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	lst = NULL;
	check(--argc, ++argv, &f);
	stack_a = ps_create_stack(argc, argv);
	if (!(fill_ins(commands)))
		error(stack_a, stack_b, commands, lst);
	if ((lst = read_answers(commands, f)) == (t_list *)-1)
		error(stack_a, stack_b, NULL, NULL);
	do_what_read(&stack_a, &stack_b, lst, commands);
	ft_putendl(check_stack(stack_a, argc -
		check(argc, argv, &f), 1) && !stack_b ? "OK" : "KO!");
	freesher(stack_a, stack_b, commands, lst);
	return (0);
}
