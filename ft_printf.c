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
#include <stdarg.h>

// Same as:
// 	print_hex_address(num / 16);
// ft_putchar_fd(hex_chars[num % 16], 1);
void	print_hex_address(unsigned long num, int c)
{
	char	*lower_hex_chars;
	char	*upper_hex_chars;

	lower_hex_chars = "0123456789abcdef";
	upper_hex_chars = "0123456789ABCDEF";
	if (num >= 16)
		print_hex_address(num >> 4, c);
	if (c == 'x')
		ft_putchar_fd(lower_hex_chars[num & 0xF], 1);
	if (c == 'X')
		ft_putchar_fd(upper_hex_chars[num & 0xF], 1);
}

static void	handle_hex(va_list *args, int c)
{
	void	*ptr;
	int		d;

	if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		ft_putstr_fd("0x", 1);
		if (ptr == NULL)
			ft_putstr_fd("0", 1);
		else
			print_hex_address((unsigned long)ptr, 'x');
	}
	else
	{
		d = va_arg(*args, int);
		print_hex_address(d, c);
	}
}

void	handle_identifiers(int c, va_list *args)
{
	int		d;
	int		ch;
	char	*str;

	if (c == 'x' || c == 'X' || c == 'p')
		handle_hex(args, c);
	else if (c == 'c')
	{
		ch = va_arg(*args, int);
		ft_putchar_fd(ch, 1);
	}
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(*args, int);
		ft_putnbr_fd(d, 1);
	}
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		ft_putstr_fd(str, 1);
	}
	else
		return ;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*s + 1)
			{
				handle_identifiers(*s, &args);
				s = s + 2;
			}
			else if (!*s + 1)
			{
				va_end(args);
				return (-1);
			}
		}
		ft_putchar_fd(*s, 1);
		count++;
		s++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(void)
{
    char *str = "Hello";
    /* ft_printf("aa\n"); */
    /* ft_printf("ft printing ft_printf: %d\n\n", ft_printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
    /* ft_printf("ft_printf printing printf: %d\n\n", printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
    /* printf("printf printing ft_printf: %d\n\n", ft_printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
    /* printf("printf printing printf: %d\n\n", printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49)); */
	printf("\n%c\n", 49);
	ft_printf("\n%p\n", "");
    return (0);
}

