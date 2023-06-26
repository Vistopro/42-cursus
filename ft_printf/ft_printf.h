/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:47:40 by vicrodri          #+#    #+#             */
/*   Updated: 2023/05/02 16:19:35 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
char	*ft_itoa_c(int n);
char	*ft_itoa_uc(unsigned int n);
size_t	ft_lenint_hexa(unsigned long n);
char	*ft_itoa_hexa(unsigned long n);

#endif