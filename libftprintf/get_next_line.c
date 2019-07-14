/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:31:43 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/12 19:40:11 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*check_fd(const int fd, t_list **start)
{
	t_list	*lst;

	if (*start == NULL)
	{
		if (!(*start = ft_lstnew(NULL, 0)))
			return (NULL);
		(*start)->content_size = fd;
		return (*start);
	}
	lst = *start;
	while (lst)
	{
		if (fd == (const int)lst->content_size)
			return (lst);
		else if (!(lst->next))
		{
			if (!(lst->next = ft_lstnew(NULL, 0)))
				return (NULL);
			lst->next->content_size = fd;
		}
		else
			lst = lst->next;
	}
	return (NULL);
}

static int		reader(const int fd, char **str)
{
	int		ret;
	char	*temp;
	char	*buf;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		temp = *str;
		if (ret < BUFF_SIZE)
			buf[ret] = '\0';
		if (!(*str = ft_strjoin(*str, buf)))
			return (-1);
		ft_memdel((void **)&temp);
		if (ft_strchr(buf, '\n') || ret < BUFF_SIZE)
			break ;
	}
	if (ret < 0)
		ft_memdel((void **)str);
	ft_memdel((void **)&buf);
	return (ret);
}

static int		cuter(char **str, char **line)
{
	char	*temp1;
	char	*temp;

	temp = *str;
	if (!(temp1 = ft_strchr(temp, '\n')))
		temp1 = ft_strchr(temp, '\0');
	if (!(*line = ft_strndup(temp, temp1 - temp)))
		return (-1);
	temp1 = *str;
	temp = ft_strchr(temp, '\n');
	if (temp)
	{
		if (!(*str = ft_strdup(temp + 1)))
			return (-1);
	}
	else
		*str = temp;
	ft_memdel((void **)&temp1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*result;
	t_list			*lst;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!(lst = check_fd(fd, &result)))
		return (-1);
	if ((ret = reader(fd, (char **)&(lst->content))) < 0)
		return (-1);
	if (!(lst->content))
	{
		*line = NULL;
		return (0);
	}
	if ((cuter((char **)&(lst->content), line)))
		return (-1);
	return (lst->content != NULL || ret || **line);
}
