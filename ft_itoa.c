/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:09:58 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 13:32:32 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_length(int n)
{
	size_t	len;
	int		divider;

	len = 0;
	divider = 1000000000;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n / divider == 0 && divider > 0)
		divider /= 10;
	while (divider > 0)
	{
		divider /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		minus;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)malloc(sizeof(char) * (count_length(n) + 1))))
		return (0);
	if (n == 0)
		return (ft_strdup("0"));
	minus = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (minus)
		str[i++] = '-';
	str[i] = '\0';
	str = strrev(str);
	return (str);
}
