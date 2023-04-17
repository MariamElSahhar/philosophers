/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:25:38 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/12 17:38:22 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nsize;
	size_t	hsize;
	char	*h;

	h = (char *) haystack;
	if (!len && !h)
		return (0);
	i = 0;
	nsize = ft_strlen((char *)needle);
	hsize = ft_strlen(haystack);
	if (!hsize && !nsize)
		return ("");
	if (!hsize)
		return (0);
	while (i + nsize <= len)
	{
		if (h[0] && ft_strncmp(h, (char *)needle, nsize) == 0)
			return (h);
		i++;
		h++;
	}
	return (0);
}
