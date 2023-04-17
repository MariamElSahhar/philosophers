/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:05:29 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/12 17:37:08 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*ret;

	i = 0;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = (char *)malloc(size1 + size2 + 1);
	if (!ret)
		return (0);
	while (i < size1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		ret[i] = s2[i - size1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
