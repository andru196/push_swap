/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:43:30 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/07/14 15:39:32 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_psl	*n_thpsl(t_psl *a, int n)
// {
// 	if (!a)
// 		return (NULL);
// 	while (n-- && a)
// 		a = a->next;
// 	return (a);
// }

// int		get_num(t_psl *a, int n)
// {
// 	int i;

// 	i = 0;
// 	while (n != a->num)
// 	{
// 		i++;
// 		a = a->next;
// 	}
// 	return (i);
// }

char	*ex_a_copy(char **str, char **part)
{
	char	*str2;

	str2 = *part;
	if (!(*part = ft_strjoin(*part, "\n")))
	{
		ft_memdel((void **)&str);
		ft_memdel((void **)&str2);
		return (NULL);
	}
	free(str2);
	str2 = *str;
	if (!(*str = ft_strjoin(*str, *part)) || !*part)
	{
		ft_memdel((void **)&part);
		ft_memdel((void **)&str2);
		return (NULL);
	}
	ft_memdel((void **)&str2);
	ft_memdel((void **)part);
	return (*str);
}

char	*norm_str(t_psl **a, char *dst, char *src)
{
	char	*rez;
	
	if (!ft_strcmp(src, "ra"))
	{
		rez = ft_strjoin(dst, "ra\n");
		ra(a, NULL);
	}
	else
	{
		rez = ft_strjoin(dst, "rra\n");
		rra(a, NULL);
	}
	if (dst)
			free(dst);
	return (rez);
	
}
static char	*normalize(t_psl **a, t_psl **b)
{
	int		num;
	int		start;
	char	*rez;

	start = track_an(*a);
	rra(a, b);
	rez = NULL;
	while (start < (num = track_an(*a)))
	{
		start = num;
		rez = norm_str(a, rez, "rra");
	}
	ra(a, b);
	start = track_an(*a);
	ra(a, b);
	while ((!rez || ft_strncmp("ra", rez, 2))
		&& start < (num = track_an(*a)))
	{
		rez = norm_str(a, rez, "ra");
		start = num;
	}
	rra(a, b);
	return (rez);
}

char		*hard_mode(t_psl **a, t_psl **b, int *arr, int n)
{
	char	*str;
	char	*str1;

	str = normalize(a, b);
	if (!str || !ft_strncmp("rra", str, 3))
	{
		str1 = str;
		str = ft_strjoin(str, short_way(a, arr));
		if (str1)
			free(str1);
	}
	while ((str1 = immersion(a, b, arr, n)))
	{
		if (!(str = ex_a_copy(&str, &str1)))
			return (NULL);
	}
	while ((str1 = climb(a, b, arr, n)))
	{
		if (!(str = ex_a_copy(&str, &str1)))
			return (NULL);
	}
	return (str);
}