/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/09 15:46:24 by dponte       #+#    #+#                  */
/*   Updated: 2025/06/09 17:10:04 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		// replace
		putchar('-');
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	putchar((num % 10) + '0');
}

void	ft_putstr(char *s)
{
	//replace
	write(1, s, strlen(s));
}

void	handle_hex(int c);

void	handle_identifiers(int c, va_list *args)
{
	if (c == 'h' || c == 'x'|| c == 'X')
		handle_hex(c);
	else if (c == 'c')
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
	else if (c == '%')
		ft_putchar_and_count('%', count);
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

	count = 0;
	if (s == NULL)
		return (-1);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s)
				handle_identifiers(*s, &args, &count);
			else
				return (va_end(args), -1);
		}
		else
			ft_putchar_and_count(*s, &count);
		s++;
	}
	return (va_end(args), count);
}
