/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:25:58 by aalzubai          #+#    #+#             */
/*   Updated: 2022/09/28 17:25:58 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*p;

	i = 0;
	p = (unsigned char *) b;
	while (i < len)
	{
		*p = (unsigned char) c;
		p++;
		i++;
	}
	return (b);
}
