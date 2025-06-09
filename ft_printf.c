/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*   Created: 2025/0/23 11:38:09 by dponte       #+#    #+#                  */
/*   Updated: 2025/05/26 18:17:04 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stddef.h>

// Same as:
// 	print_hex_address(num / 16);
// ft_putchar_fd(hex_chars[num % 16], 1);
void	print_hex_address(unsigned long num, int c, size_t *count)
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

static void	handle_hex(va_list *args, int c, size_t *count)
{
	void	*ptr;
	int		d;

	if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		if (ptr == NULL)
		{
			ft_putstr_fd("(nil)", 1);
			return ;
		}
		else
		{
			ft_putstr_and_count("0x", count);
			print_hex_address((unsigned long)ptr, 'x', count);
		}
	}
	else
	{
		d = va_arg(*args, int);
		print_hex_address(d, c, count);
	}
}

void	handle_identifiers(int c, va_list *args, size_t *count)
{
	char	*str;

	if (c == 'x' || c == 'X' || c == 'p')
		handle_hex(args, c, count);
	else if (c == 'c')
		ft_putchar_and_count(va_arg(*args, int), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_and_count(va_arg(*args, int), count);
	else if (c == '%')
		ft_putchar_and_count('%', count);
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		if (str == NULL)
			ft_putstr_and_count("(null)", count);
		else
			ft_putstr_and_count(str, count);
	}
	else
		return ;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s)
				handle_identifiers(*s, &args, &count);
			else
			{
				va_end(args);
				return (-1);
			}
			s++;
		}
		ft_putchar_fd(*s, 1);
		count++;
		s++;
	}
	va_end(args);
	return (count);
}

//#include <stdio.h>
//
//int main(void)
//{
//    char *str = "Hello";
//    /* ft_printf("aa\n"); */
//    /* ft_printf("ft printing ft_printf: %d\n\n", ft_printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
//    /* ft_printf("ft_printf printing printf: %d\n\n", printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
//    /* printf("printf printing ft_printf: %d\n\n", ft_printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
//    /* printf("printf printing printf: %d\n\n", printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
//	printf("\n%c\n", 49);
//	ft_printf("\n%p\n", "");
//    return (0);
//}
//
