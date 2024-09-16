/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <erwann.lagouche@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:17:25 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/16 11:13:53 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (1);
	return (ft_strlen (str + sizeof(char)) + 1);
}

int	my_cmp(char *s1, char *s2, int n, int end2)
{
	int	cmp;

	cmp = 0;
	if (n == 0)
		return (0);
	if (end2)
		cmp = *s1;
	else
	{
		cmp = *s1 - *s2;
		if (*s2 == '\0')
			end2 = 1;
	}
	return (cmp + my_cmp(s1 + sizeof(char), s2 + sizeof(char), n - 1, end2));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	len1;
	int	len2;
	int	cmp;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 >= len2)
		cmp = my_cmp(s1, s2, len1, 0);
	else
		cmp = my_cmp(s2, s1, len2, 0);
	if (cmp < 0)
		return (-1);
	else if (cmp > 0)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("###\ncmp og: %d\n", strcmp("ABC", "ABC"));
// 	printf("cmp cu: %d\n", ft_strcmp("ABC", "ABC"));
// 	//
// 	printf("###\ncmp og: %d\n", strcmp("ABC", "AB"));
// 	printf("cmp cu: %d\n", ft_strcmp("ABC", "AB"));
// 	//
// 	printf("###\ncmp og: %d\n", strcmp("ABA", "ABZ"));
// 	printf("cmp cu: %d\n", ft_strcmp("ABA", "ABZ"));
// }
