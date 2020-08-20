/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:03:13 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 04:29:48 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct			s_intstk
{
	int					num;
	int					index;
	struct s_intstk		*next;
	struct s_intstk		*previous;
}						t_intstk;

int						ft_msgs(int n);
int						ft_checkargv(t_intstk **stack1, int argc, char **argv);
int						ft_check_dg(char *argv);
int						ft_delsplit(char ***split, int j);
int						ft_check_same(t_intstk *stack1);
int						ft_check_wr(char *line);
int						ft_check_maxint(long int *num, char *split);
int						ft_check_sort(t_intstk *stack1);
int						ft_check_argv(int argc, char **argv, t_intstk **stack1);
int						chcker_writer(char **line, t_intstk **stack1,
						t_intstk **stack2);
void					ft_createintstack(t_intstk **stack1, int num);
void					ft_fillintstack(t_intstk **stack1, int num);
void					ft_delintstack(t_intstk **stack);
int						ft_fulldelintstack(t_intstk **stack);
void					ft_sort(char *line, t_intstk **stack1,
						t_intstk **stack2, int wr);
void					ft_sort_s(char *line, t_intstk **stack1,
						t_intstk **stack2);
t_intstk				*ft_sort_s_work(t_intstk *stack);
void					ft_sort_r(char *line, t_intstk **stack1,
						t_intstk **stack2);
t_intstk				*ft_sort_r_work(t_intstk *stack);
void					ft_sort_rr(char *line, t_intstk **stack1,
						t_intstk **stack2);
t_intstk				*ft_sort_rr_work(t_intstk *stack);
void					ft_sort_p(char *line, t_intstk **stack1,
						t_intstk **stack2);
t_intstk				*ft_sort_p_work_stk1(t_intstk *stack1);
t_intstk				*ft_sort_p_work_stk2(t_intstk *stack1, int tmp_num);
void					ft_noobsort(t_intstk **stack1, t_intstk **stack2);
void					ft_noobsortplus(int count, t_intstk **stack1,
						t_intstk **stack2);
void					ft_sortthree(t_intstk **stack1);
void					ft_mintoup(t_intstk **stack1);
int						*ft_sort_mas(t_intstk *stack);
int						*ft_avrg_mas(int *sort_mas, int count);
void					ft_ins_sort(int *arr, int n);
void					ft_prosort(t_intstk	**stack1, t_intstk **stack2,
						int *sort_mas, int *avrg_mas);
void					ft_halfpb(t_intstk **stack1, t_intstk **stack2,
						int *mid, int i);
void					ft_halfpb_toup(t_intstk **stack1, int num);
void					ft_halfpa(t_intstk **stack1, t_intstk **stack2,
						int *sort_mas, int *j);
void					ft_halfpa_cksh(t_intstk **stack1, t_intstk **stack2,
						int *sort_hmas, int *mid_i);
void					ft_prosortend(t_intstk **stack1, t_intstk **stack2,
						int notsort);
void					ft_prosortnext(t_intstk **stack1, t_intstk **stack2,
						int *j, int *sort_mas);
int						ft_endprog(int **avrg_mas, int **sort_mas,
						t_intstk **stack1);
t_intstk				*ft_delintstackelem(t_intstk *lst);

#endif
