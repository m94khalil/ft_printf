/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:01:35 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/08 11:39:49 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_all(va_list ap, const char *format)
{
	int	num;

	num = 0;
	if (*format == '%')
		num = print_c('%');
	else if (*format == 'c')
		num = print_c(va_arg(ap, int));
	else if (*format == 's')
		num = print_s(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		num = print_i(va_arg(ap, int));
	else if (*format == 'u' || *format == 'x' || *format == 'X')
		num = print_u_x(va_arg(ap, unsigned int), *format);
	else if (*format == 'p')
		num = print_p(va_arg(ap, uintptr_t));
	return (num);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num_chars;

	num_chars = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			num_chars += print_all(ap, ++format);
		else
		{
			ft_putchar_fd(*format, 1);
			num_chars++;
		}
		format++;
	}
	va_end(ap);
	return (num_chars);
}
