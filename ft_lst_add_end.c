/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:21:16 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/04 19:24:59 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_end(t_list *root, t_list *new)
{
	while (root->next)
		root = root->next;
	root->next = new;
}
