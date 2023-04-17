/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:33:44 by melsahha          #+#    #+#             */
/*   Updated: 2023/04/12 17:35:56 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	int		i;
	int		j;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	j = count * size;
	while (i < j)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
