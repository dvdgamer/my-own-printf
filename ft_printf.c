/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/05/23 11:38:09 by dponte       #+#    #+#                  */
/*   Updated: 2025/05/25 14:58:09 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
	// fix
	putchar((num % 10) + '0');
}

void	ft_putstr(char *s)
{
	//replace
	write(1, s, strlen(s));
}

void	handle_hex(int c)
{
	putchar(c);
}

void	handle_identifiers(int c, va_list *args)
{
	if (c == 'h' || c == 'x'|| c == 'X' || c == 'p')
	{
		handle_hex(c);
	} else if (c == 'c')
	{
		int	ch;
		ch = va_arg(*args, int);
		putchar(ch);
	} else if (c == 'd' || c == 'i')
	{
		int	d;
		d = va_arg(*args, int);
		ft_putnbr(d);
	} else if (c == '%')
	{
		putchar('%');
	} else if (c == 's')
	{
	char	*str;
	str = va_arg(*args, char *);
	ft_putstr(str);
} else
	return ;//invalid identifier
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
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
    ft_printf("aa\n");
    ft_printf("aa \n%c\n%d\n%%\n%s\n%c\n%p\n%", '2', 32123, str, 49, str);
	printf("\n%c\n", 49);
    return 0;
}
