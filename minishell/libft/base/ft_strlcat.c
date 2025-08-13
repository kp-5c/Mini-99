/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhujoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:47:11 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/05/06 11:06:22 by dbhujoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	i;

	i = 0;
	ldst = ft_strlen(dst);
	if (size <= ldst)
		return (ft_strlen(src) + size);
	while (ldst + i < size - 1 && src[i])
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (ft_strlen(src) + ldst);
}
/*
int	main(void)
{
	const char *src = "world";
	char dest[50] = "hello";
	int c = ft_strlcat(dest, src, 50);
	printf("%d\n", c);
	printf("%s", dest);
}*/
