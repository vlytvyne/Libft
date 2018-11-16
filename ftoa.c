/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:51:10 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/16 15:18:09 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long double	fabs(long double num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static void			cat_free(char *str, char *itoa_ret)
{
	ft_strcat(str, itoa_ret);
	free(itoa_ret);
}

static void			fill_zeros(char *str, char *itoa_ret, int precision)
{
	int itoa_len;

	itoa_len = ft_strlen(itoa_ret);
	while (itoa_len++ < precision)
		ft_strcat(str, "0");
}

static char			*get_itoa_answer(long double fp)
{
	return ((float)fp > (int)fp ? itoa_base(fp + 1, 10) : itoa_base(fp, 10));
}

char				*ftoa(long double num, unsigned int precision)
{
	int			ip;
	long double	fp;
	char		*str;
	char		*itoa_ret;

	str = ft_strnew(30);
	if (num < 0)
	{
		ft_strcat(str, "-");
		num = fabs(num);
	}
	ip = (int)num;
	fp = num - ip;
	itoa_ret = itoa_base(ip, 10);
	cat_free(str, itoa_ret);
	if (precision != 0)
	{
		ft_strcat(str, ".");
		fp = fp * power(10, precision);
		itoa_ret = get_itoa_answer(fp);
		fill_zeros(str, itoa_ret, precision);
		cat_free(str, itoa_ret);
	}
	return (str);
}

int					main(void)
{
	printf("%s\n", ftoa(-123.7, 5));
}
