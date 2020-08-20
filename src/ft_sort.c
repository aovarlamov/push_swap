/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:48:34 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/03 05:58:07 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		ft_sort(char *line, t_intstk **stack1, t_intstk **stack2, int wr)
{
	if (line[0] == 's')
		ft_sort_s(line, &*stack1, &*stack2);
	else if (line[0] == 'r' && line[2] == '\0')
		ft_sort_r(line, &*stack1, &*stack2);
	else if (line[0] == 'r' && line[2] != '\0')
		ft_sort_rr(line, &*stack1, &*stack2);
	else
		ft_sort_p(line, &*stack1, &*stack2);
	if (wr == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
}
