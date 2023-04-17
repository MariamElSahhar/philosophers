/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:43:36 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/12 17:36:36 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*p1;
	char			*p2;

	p1 = (char *) s1;
	p2 = (char *) s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return ((unsigned char) *p1 - (unsigned char) *p2);
		i ++;
		p1 ++;
		p2 ++;
	}
	return (0);
}
