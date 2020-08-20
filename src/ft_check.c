/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:24:46 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 20:56:15 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int				ft_checkargv(t_intstk **stack1, int argc, char **argv)
{
	int			i;
	int			j;
	char		**split;
	long int	num;

	i = 0;
	while (i++ < argc - 1)
	{
		if (argv[i][0] != '\0')
		{
			j = 0;
			split = ft_strsplit(argv[i], ' ');
			while (split[j])
			{
				if (!(ft_check_dg(split[j])))
					return (ft_delsplit(&split, j));
				if (!(ft_check_maxint(&num, split[j])))
					return (ft_delsplit(&split, j));
				ft_fillintstack(&*stack1, (int)num);
				ft_strdel(&split[j++]);
			}
			free(split);
		}
	}
	return (1);
}

int				ft_check_dg(char *argv)
{
	int		i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] != '\0')
		i++;
	while (argv[i] != '\0')
	{
		if (!(ft_isdigit(argv[i])) || i > 11)
			return (0);
		i++;
	}
	return (1);
}

int				ft_check_same(t_intstk *stack1)
{
	t_intstk	*tmp1;
	t_intstk	*tmp2;
	int			ck;

	if (stack1)
	{
		tmp1 = stack1->next;
		tmp2 = tmp1;
		while (tmp1->index != 1)
		{
			ck = tmp1->previous->num;
			while (tmp2->index != 1)
			{
				if (ck == tmp2->num)
					return (0);
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp1;
		}
		return (1);
	}
	return (1);
}

int				ft_check_wr(char *line)
{
	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 ||
	ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "ra") == 0 ||
	ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0 ||
	ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0 ||
	ft_strcmp(line, "rrr") == 0 || ft_strcmp(line, "pa") == 0 ||
	ft_strcmp(line, "pb") == 0)
		return (1);
	else
		return (0);
}

int				ft_check_sort(t_intstk *stack1)
{
	int			i;
	int			last_i;
	t_intstk	*tmp;

	i = 1;
	if (stack1)
	{
		last_i = stack1->previous->index;
		tmp = stack1;
		while (i < last_i)
		{
			if (tmp->num > tmp->next->num)
				return (0);
			i++;
			tmp = tmp->next;
		}
	}
	return (1);
}
