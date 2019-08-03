/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:20:15 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/26 17:43:37 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			error_stack(t_psl *rez)
{
	t_psl	*a;

	while (rez)
	{
		a = rez;
		rez = rez->next;
		free(a);
		a = rez;
	}
}

static t_psl	*ft_ps_lstnew(int num)
{
	t_psl	*rez;

	rez = (t_psl *)malloc(sizeof(t_psl));
	if (!rez)
		return (NULL);
	rez->next = NULL;
	rez->num = num;
	return (rez);
}

static int		check_num(char *str, t_psl *lst)
{
	int		i;
	char	*cpy;

	cpy = str;
	while ((*str == '-' && str == cpy) || (*str == '0' && *(str + 1)))
		str++;
	i = ft_strlen(str);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	if (i > 10 || (i == 0 && ft_strlen(cpy) == 1))
		return (0);
	if (i == 10)
		if ((*cpy != '-' && ft_strcmp("2147483647", cpy) < 0)
			|| (*cpy == '-' && ft_strcmp("-2147483648", cpy) < 0))
			return (0);
	i = ft_atoi(cpy);
	while (lst)
	{
		if (lst->num == i)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_psl			*ps_create_stack(int argc, char **argv)
{
	t_psl	*rez;
	t_psl	*lst;
	int		i;

	if (argc == 0)
		return (NULL);
	i = -1;
	rez = NULL;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			continue ;
		if (!check_num(argv[i], rez))
			error(rez, NULL, NULL, NULL);
		if (rez == NULL)
		{
			if (!(rez = ft_ps_lstnew(ft_atoi(argv[i]))))
				error(rez, NULL, NULL, NULL);
			lst = rez;
		}
		else if (!(lst->next = ft_ps_lstnew(ft_atoi(argv[i]))))
			error(rez, NULL, NULL, NULL);
		lst = lst->next ? lst->next : lst;
	}
	return (rez);
}
