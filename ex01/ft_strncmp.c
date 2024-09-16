/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <erwann.lagouche@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:52 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/16 15:20:31 by elagouch         ###   ########.fr       */
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

int	my_cmp2(char *s1, char *s2, int n, int end2)
{
	int	cmp;

	if (n == 0)
		return (0);
	if (end2)
		cmp = 1;
	else
	{
		if (*s1 == *s2)
			cmp = 0;
		else if (((unsigned char) *s1 > 127) && ((unsigned char) *s2 > 127))
			cmp = 0;
		else if (((unsigned char) *s1 <= 127) && ((unsigned char) *s2 > 127))
			cmp = -1;
		else if (((unsigned char) *s1 > 127) && ((unsigned char) *s2 <= 127))
			cmp = 1;
		else if (*s1 > *s2)
			cmp = 1;
		else if (*s1 < *s2)
			cmp = -1;
		if (*s2 == '\0')
			end2 = 1;
	}
	return (cmp + my_cmp2(s1 + sizeof(char),
			s2 + sizeof(char), n - 1, end2));
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	len1;
	int	len2;
	int	cmp;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n < (unsigned int) len1)
		len1 = n;
	if (n < (unsigned int) len2)
		len2 = n;
	if (len1 >= len2)
		cmp = my_cmp2(s1, s2, len1, 0);
	else
		cmp = my_cmp2(s2, s1, len2, 0);
	return (cmp);
}

// int	main(void)
// {
// 	printf("###\ncmp og: %d\n", strncmp("ABC", "ABC", 100));
// 	printf("cmp cu: %d\n", ft_strncmp("ABC", "ABC", 100));
// 	//
// 	printf("###\ncmp og: %d\n", strncmp("ABC", "ABC", 2));
// 	printf("cmp cu: %d\n", ft_strncmp("ABC", "ABC", 2));
// 	//
// 	printf("###\ncmp og: %d\n", strncmp("ABC", "AB", 100));
// 	printf("cmp cu: %d\n", ft_strncmp("ABC", "AB", 100));
// 	//
// 	printf("###\ncmp og: %d\n", strncmp("ABA", "ABZ", 100));
// 	printf("cmp cu: %d\n", ft_strncmp("ABA", "ABZ", 100));
// 	//
// 	printf("###\ncmp og: %d\n", strncmp("\201", "", 100));
// 	printf("cmp cu: %d\n", ft_strncmp("\201", "", 100));
// 	//
// 	printf("###\ncmp og: %d\n", strncmp("\201\201", "", 100));
// 	printf("cmp cu: %d\n", ft_strncmp("\201\201", "", 100));
// 	//
// 	printf("###\ncmp og: %d\n", strncmp("\201", "A\201", 100));
// 	printf("cmp cu: %d\n", ft_strncmp("\201", "A\201", 100));
// 	//
// 	printf("###\ncmp og: %d\n", strncmp("ABCDEFGHIJK", "ONMLKJIHGFE", 8));
// 	printf("cmp cu: %d\n", ft_strncmp("ABCDEFGHIJK", "ONMLKJIHGFE", 8));
// }
