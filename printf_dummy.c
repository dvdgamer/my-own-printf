/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   printf_dummy.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/05/24 18:13:07 by dponte       #+#    #+#                  */
/*   Updated: 2025/05/24 18:13:10 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
int	ft_printf(const char *, ...)
{
	// Make an array of nr of arguments
		// Based on commas
	// While string -> putstr/putchar.
	// When it encounters % check the next char to see which function to execute
	// 		Make it have correspondent index to arguments_array
	//		if == 'c' -> printchar
	//		if == 's' -> putstr
	//		if == 'p' -> printnbr in hex??
	//		if == 'd' -> print decimal
	//		if == 'i' -> putnbr
	//		if == 'u' -> print unsigned decimal
	//		if == 'x' -> puthex_lowercase?
	//		if == 'X' -> puthex_uppercase?
	//		if == '%' -> putchar '%'?
	return (1);
}

