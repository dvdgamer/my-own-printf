/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/05/23 11:38:09 by dponte       #+#    #+#                  */
/*   Updated: 2025/05/25 14:44:10 by dponte       ########   odam.nl          */
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
	int		d;
	int		ch;
	char	*str;
	void	*ptr;

	if (c == 'h' || c == 'x'|| c == 'X')
		handle_hex(c);
	else if (c == 'c')
	{
		ch = va_arg(*args, int);
		putchar(ch);
	}
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(*args, int);
		ft_putnbr(d);
	}
	else if (c == '%')
		putchar('%');
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		ft_putstr(str);
	}
	else if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		ft_putstr(ptr);
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
    ft_printf("aa\n");
    ft_printf("ft printing ft_printf: %d\n\n", ft_printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49));
    ft_printf("ft_printf printing printf: %d\n\n", printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49));
    printf("printf printing ft_printf: %d\n\n", ft_printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49));
    printf("printf printing printf: %d\n\n", printf("aa \n%c\n%d\n%%\n%s\n%c\n", '2', 32123, str, 49));
	printf("\n%c\n", 49);
    return (0);
}

