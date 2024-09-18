/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:43:14 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/18 10:43:16 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (1);
	return (ft_strlen (str + sizeof(char)) + 1);
}

char	*ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_len;
	int	src_len;
	int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while ((unsigned int) i < (size + 2) && i < (dest_len + src_len))
	{
		if (i > dest_len)
		{
			dest[i - 2] = src[i - dest_len - 1];
		}
		i++;
	}
	dest[i - 2] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	*src = "world!";
// 	char	*src2 = "world!";
// 	char	dest[500] = "Hello, ";
// 	char	dest2[500] = "Hello, ";
// 	char	*rest;
//
// 	printf ("### B4\nsrc: %s\ndest: %s\n", src, dest);
// 	rest = ft_strlcat(dest, src, 100);
// 	printf ("### @R\nsrc: %s\ndest: %s\nrest: %s\n", src, dest, rest);
// 	printf ("### B4\nsrc: %s\ndest: %s\n", src2, dest2);
// 	rest = ft_strlcat(dest2, src2, 12);
// 	printf ("### @R\nsrc: %s\ndest: %s\nrest: %s\n", src2, dest2, rest);
// }
