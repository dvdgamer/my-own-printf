/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_handle_hex.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/05/26 14:50:05 by dponte       #+#    #+#                  */
/*   Updated: 2025/05/26 17:57:06 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft/libft.h"
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
void	ft_putlowerhex(int c)
{
	ft_putstr_fd(c, 1);
}
