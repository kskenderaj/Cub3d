/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:35:36 by mimacdou          #+#    #+#             */
/*   Updated: 2025/03/20 16:15:28 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_parse(char spec, va_list argp)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_iputchar(va_arg(argp, int));
	else if (spec == '%')
		count += ft_iputchar('%');
	else if (spec == 's')
		count += ft_iputstr(va_arg(argp, char *));
	else if (spec == 'd' || spec == 'i')
		count += ft_iputnums((long)(va_arg(argp, int)), 10, 0);
	else if (spec == 'u')
		count += ft_iputnums((long long)(va_arg(argp, unsigned int)), 10, 0);
	else if (spec == 'x')
		count += ft_iputnums((long long)(va_arg(argp, unsigned int)), 16, 0);
	else if (spec == 'X')
		count += ft_iputnums((long long)(va_arg(argp, unsigned int)), 16, 1);
	else if (spec == 'p' )
		count += ft_iputptr(va_arg(argp, size_t));
	else
	{
		count += ft_iputchar('%');
		count += ft_iputchar(spec);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		count;

	va_start(argp, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_printf_parse(*(++format), argp);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(argp);
	return (count);
}
