/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/09 15:46:24 by dponte       #+#    #+#                  */
/*   Updated: 2025/06/09 16:43:20 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>

// Same as:
// 	print_hex_address(num / 16);
// ft_putchar_fd(hex_chars[num % 16], 1);
static void	print_hex_address(unsigned long num, int c, int *count)
{
	char	*lower_hex_chars;
	char	*upper_hex_chars;

	lower_hex_chars = "0123456789abcdef";
	upper_hex_chars = "0123456789ABCDEF";
	if (num >= 16)
		print_hex_address(num >> 4, c, count);
	if (c == 'x')
		ft_putchar_and_count(lower_hex_chars[num & 0xF], count);
	if (c == 'X')
		ft_putchar_and_count(upper_hex_chars[num & 0xF], count);
}

static void	handle_hex(va_list *args, int c, int *count)
{
	void			*ptr;
	unsigned long	d;

	if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		if (ptr == NULL)
			ft_putstr_and_count("(nil)", count);
		else
		{
			ft_putstr_and_count("0x", count);
			print_hex_address((unsigned long)ptr, 'x', count);
		}
	}
	else
	{
		d = va_arg(*args, int);
		print_hex_address((unsigned int)d, c, count);
	}
}

void	handle_identifiers(int c, va_list *args, int *count)
{
	char	*str;

	if (c == 'x' || c == 'X' || c == 'p')
		handle_hex(args, c, count);
	else if (c == 'c')
		ft_putchar_and_count(va_arg(*args, int), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_and_count(va_arg(*args, int), count);
	else if (c == 'u')
		ft_putunsigned_and_count(va_arg(*args, unsigned int), count);
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		if (str == NULL)
			ft_putstr_and_count("(null)", count);
		else
			ft_putstr_and_count(str, count);
	}
	else
	{
		ft_putchar_and_count('%', count);
		ft_putchar_and_count(c, count);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	if (s == NULL)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				ft_putchar_and_count('%', &count);
			else if (*s)
				handle_identifiers(*s, &args, &count);
			else
			{
				va_end(args);
				return (-1);
			}
		}
		else 
			ft_putchar_and_count(*s, &count);
		s++;
	}
	va_end(args);
	return (count);
}
