/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_printf.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/05/23 11:38:09 by dponte       #+#    #+#                  */
/*   Updated: 2025/05/24 19:27:38 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	handle_identifiers(int c);

int	ft_printf(const char *s, ...)
{
	// Make an array of nr of arguments
	va_list	args;
	int		count;
	int		i;

	// Check if number of arguments == nr of %
	// return (0);
		// Based on commas
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			// fucntions
			if (s[i + 1])
				handle_identifiers(s[i + 1]);
	// When it encounters % check the next char to see which function to execute
	// 		Make it have correspondent index to arguments_array
	//		if == 'c' -> printchar
	//			if type doesn't match return error??
	//		if == 's' -> putstr
	//		if == 'p' -> printnbr in hex??
	//		if == 'd' -> print decimal
	//		if == 'i' -> putnbr
	//		if == 'u' -> print unsigned decimal
	//		if == 'x' -> puthex_lowercase?
	//		if == 'X' -> puthex_uppercase?
	//		if == '%' -> putchar '%'?
	// While string -> putstr/putchar.
		putchar(s[i]);
	i++;
	}
	return (1);
}
