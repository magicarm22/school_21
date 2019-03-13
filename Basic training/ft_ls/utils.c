/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:52:06 by djast             #+#    #+#             */
/*   Updated: 2019/03/13 19:57:00 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_size_array(char **str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void		take_info2(t_dir *cur, struct stat buff)
{
	char		**parsed_time;
	int			i;

	parsed_time = ft_strsplit(ctime(&buff.st_mtime), ' ');
	cur->month = ft_strdup(parsed_time[1]);
	cur->day = ft_strdup(parsed_time[2]);
	cur->time = ft_strsub(parsed_time[3], 0, 5);
	cur->block = buff.st_blocks;
	cur->extended_attributes = listxattr(cur->path_file, NULL, 300, 0);
	i = 0;
	//while (parsed_time[i])
	//{
	//	free(parsed_time[i]);
	//	i++;
	//}
	//free(parsed_time);
}

void		take_info(t_dir *file_list)
{
	t_dir		*cur;
	struct stat	buff;

	cur = file_list;
	while (cur)
	{
		lstat(cur->path_file, &buff);
		cur->rules = buff.st_mode;
		cur->links = buff.st_nlink;
		cur->user = buff.st_uid;
		cur->group = buff.st_gid;
		cur->size = buff.st_size;
		take_info2(cur, buff);
		cur = cur->next_file;
	}
}

void		delete_branch(t_dir **file_list)
{
	t_dir *current;
	t_dir *next;

	current = *file_list;
	next = NULL;
	if (current)
		next = (*file_list)->next_file;
	while (next)
	{
		free(current->month);
		free(current->day);
		free(current->time);
		free(current->path_file);
		free(current);
		current = next;
		next = current->next_file;
	}
	free(current->path_file);
	free(current->month);
	free(current->day);
	free(current->time);
	free(current);
	current = NULL;
}

void		list_reverse(t_dir **begin_list)
{
	t_dir *list_prev;
	t_dir *list_cur;
	t_dir *list_next;

	list_next = NULL;
	list_prev = NULL;
	list_cur = *begin_list;
	while (list_cur)
	{
		list_next = list_cur->next_file;
		list_cur->next_file = list_prev;
		list_prev = list_cur;
		list_cur = list_next;
	}
	*begin_list = list_prev;
}
