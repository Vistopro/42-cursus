/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:00:43 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 15:00:46 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strnstr() function locates the first occurrence of the null-termi-
nated string needle in the string haystack, where not more than len char-
acters are searched.  Characters that appear after a `\0' character are
not searched.  Since the strnstr() function is a FreeBSD specific API, it
should only be used when portability is not a concern.

If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the first
character of the first occurrence of needle is returned*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *str = "antonio";
// 	char *to_find = "ton";
// 	size_t n = 7;
// 	printf("strstr(s1,s2) = %s\n", strnstr(str, to_find, n));
// 	printf("%s\n", ft_strnstr(str, to_find, n));
// } 
