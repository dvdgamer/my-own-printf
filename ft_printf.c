/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/05/23 11:38:09 by dponte       #+#    #+#                  */
/*   Updated: 2025/05/26 18:17:04 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

// Same as:
// 	print_hex_address(num / 16);
// ft_putchar_fd(hex_chars[num % 16], 1);
void print_hex_address(unsigned long num)
{
	char *hex_chars = "0123456789abcdef";

	if (num >= 16)
		print_hex_address(num >> 4);
	ft_putchar_fd(hex_chars[num & 0xF], 1);
}

static void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	putchar((num % 10) + '0');
}

void	handle_hex(int d)
{
	ft_putnbr(d);
}

void	handle_identifiers(int c, va_list *args)
{
	int		d;
	int		ch;
	char	*str;
	void	*ptr;

	if (c == 'h' || c == 'x'|| c == 'X')
	{
		d = va_arg(*args, int);
		handle_hex(d);
	}
	else if (c == 'c')
	{
		ch = va_arg(*args, int);
		ft_putchar_fd(ch, 1);
	}
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(*args, int);
		ft_putnbr(d);
	}
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		ft_putstr_fd(str, 1);
	}
	else if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		ft_putstr_fd("0x", 1);
		if (ptr == NULL)
			ft_putstr_fd("0", 1);
		else
			print_hex_address((unsigned long)ptr);
	}
	else
		return ;//invalid identifier
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
			s++;
			if (*s)
			{
				handle_identifiers(*s, &args);
				s++;
			}
			else if (!*s)
			{
				va_end(args);
				return (-1);
			}
		}
		putchar(*s);
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

