/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:53:20 by vurrigon          #+#    #+#             */
/*   Updated: 2019/03/01 17:53:08 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void find_subdirs(t_ls *ls, t_dir **begin_list);

void	print_dir(t_dir *file_list)
{
	t_dir *current;

	current = file_list;
	while (current)
	{
		ft_printf("%s\n", ft_strrchr(current->path_file, '/') + 1);
		current = current->next_file;
	}
	current = file_list;
	while (current)
	{
		if (current->type == FT_DIR)
		{
			ft_printf("\n%s:\n", current->subdir->path_file);
			print_dir(current->subdir->next_file);
		}
		current = current->next_file;
	}

}

void	list_sort_by_name(t_dir **begin_list)
{
	t_dir	*list;
	char	*tmp;
	int		flag;

	list = *begin_list;
	if (list == 0)
		return ;
	while (1)
	{
		list = *begin_list;
		flag = 0;
		while (list->next_file != 0)
		{
			if (ft_strcmp(list->path_file, (list->next_file)->path_file) > 0)
			{
				flag = 1;
				tmp = list->path_file;
				list->path_file = list->next_file->path_file;
				list->next_file->path_file = tmp;
			}
			list = list->next_file;
		}
		if (flag == 0)
			break ;
	}
}

void	list_sort_by_name_rev(t_dir **begin_list)
{
	t_dir	*list;
	char	*tmp;
	int		flag;

	list = *begin_list;
	if (list == 0)
		return ;
	while (1)
	{
		list = *begin_list;
		flag = 0;
		while (list->next_file != 0)
		{
			if (ft_strcmp(list->path_file, (list->next_file)->path_file) < 0)
			{
				flag = 1;
				tmp = list->path_file;
				list->path_file = list->next_file->path_file;
				list->next_file->path_file = tmp;
			}
			list = list->next_file;
		}
		if (flag == 0)
			break ;
	}
}

t_dir	*ft_create_file(char *fname, t_dir *subdir, int type)
{
	t_dir	*list;

	list = malloc(sizeof(t_dir));
	if (list)
	{
		list->path_file = fname;
		list->next_file = NULL;
		list->subdir = subdir;
		list->type = type;
	}
	return (list);
}

void	list_push_back(t_dir **begin_list, char *fname, unsigned char type)
{
	t_dir	*current;

	if (*begin_list)
	{
		current = *begin_list;
		while (current->next_file)
			current = current->next_file;
		if (type == DT_DIR)
			current->next_file = ft_create_file(fname, NULL, FT_DIR);
		else if (type == DT_REG)
			current->next_file = ft_create_file(fname, NULL, FT_FILE);
	}
}

static int add_in_list(const char *bpath, t_ls *ls, t_dir **file_list)
{
	DIR *dir;
	char *path;
	struct dirent *d_entry;

	path = ft_strnew(0);
	if (!(dir = opendir(bpath)))
        return (-1);
	while ((d_entry = readdir(dir)))
	{
        if (d_entry->d_type == DT_REG)
        {
        	if (ft_strncmp(d_entry->d_name, ".", 1) == 0 && !ls->is_with_dot)
        		continue ;
        	path = ft_strjoin((*file_list)->path_file, "/");
        	path = ft_strjoin(path, d_entry->d_name);
        	list_push_back(file_list, path, d_entry->d_type);
        }
        else if (d_entry->d_type == DT_DIR)
		{
			if (ft_strncmp(d_entry->d_name, ".", 1) == 0 && !ls->is_with_dot)
				continue;
            path = ft_strjoin((*file_list)->path_file, "/");
        	path = ft_strjoin(path, d_entry->d_name);
            list_push_back(file_list, path, d_entry->d_type);
        }
	}
    closedir(dir);
    find_subdirs(ls, &(*file_list)->next_file);
    return (1); 
}

void find_subdirs(t_ls *ls, t_dir **begin_list)
{
	t_dir *current;

	current = *begin_list;
	while (current != NULL)
	{
		if (current->type == FT_DIR)
		{
			//ft_printf("%s\n", current->path_file);
			current->subdir = ft_create_file(current->path_file, NULL, FT_DIR);
			add_in_list(current->path_file, ls, &(current->subdir));
		}
		current = current->next_file;
	}
}

int	prepare_output(t_ls *ls)
{
	int i;
	t_dir	*file_list;

	file_list = ft_create_file(ls->path, NULL, FT_ROOT);
	i = 0;
	add_in_list(ls->path, ls, &file_list);
	ls->is_reversed ? list_sort_by_name_rev(&(file_list->next_file)) : list_sort_by_name(&(file_list->next_file));
	print_dir(file_list->next_file);
	file_list = NULL;
	return (1);
}
