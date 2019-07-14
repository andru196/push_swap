/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:42:51 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/13 19:52:14 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_params(t_psl *lst, int n)
{
	int		*rez;
	t_psl	*l;
	int		max;
	int 	i;

	if (!(rez = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	i = n - 1;
	while (n--)
	{
		l = lst;
		max = -2147483648;
		while (l)
		{
			if (l->num > max && (n == i || l->num < rez[n + 1]))
				max = l->num;
			l = l->next;
		}
		rez[n] = max;
	}
	return (rez);
}

static int	set_flag(int flag[5], char **s)
{
	char c;

	c = **s;
	if (c >= '0' && c <= '9')
		return (2);
	else if (c == 'v')
		flag[0] = 1;
	else if (c == 'f')
		flag[1] = 1;
	else if (c == 'n')
		flag[2] = 1;
	else if (c == 'N')
	{
		flag[3] = ft_atoi((*s)++ + 1);
		while (**s >= '0' && **s <= '9')
			(*s)++;
		(*s)--;
	}
	else if (c == 'c')
		flag[4] = 1;
	else
		return (0);
	return (1);
}

static int	check_flags(int argc, char **argv, int flag[6])
{
	int		i;
	char	*str;
	int		f;
	int		j;

	i = 1;
	j = 0;
	ft_memset((void *)flag, 0, sizeof(int) * 5);
	while (i < argc)
	{
		f = 0;
		str = argv[i];
		if (*str == '-')
			while (*++str)
				if ((f = set_flag(flag, &str)) == 0)
					return (0);
		if (f == 1 || *(argv[i]) == '\0')
		{
			*(argv[i]) = '\0';
			j++;
		}
		i++;
	}
	return (j);
}

static	void free_for_ps(t_psl *a, int *arr)
{
	if (a)
		free(a);
	if (arr)
		free(arr);
}

int		main(int argc, char **argv)
{
	t_psl	*stack_a;
	t_psl	*stack_b;
	int		*arr;
	char	*rez;
	int		fl[6];

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	fl[5] = check_flags(argc--, argv, fl);
	if (check_stack(stack_a = ps_create_stack(argc, ++argv), argc - fl[5], 1))
		return (0);
	if (!(arr = sort_params(stack_a, argc - fl[5])))
		error(stack_a, NULL, NULL, NULL);
	rez = execute(&stack_a, &stack_b, arr, argc - fl[5]);
	free_for_ps(stack_a, arr);
	finish_print(ps_create_stack(argc, argv), rez, fl);
	free(rez);
	return (0);
}