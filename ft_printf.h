#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // TO REMOVE, REMOVE ME IDIOT, REMOVE ME//

# define CONV "cspdiouxX%"
# define LENGTH "0lLhjzt"

int		ft_printf(char *str, ...);
void	ft_putunsigned(unsigned int nb);
void	ft_putoctal(unsigned int nb);
void	ft_puthexa(unsigned int nb);
void	ft_putupperhexa(unsigned int nb);

#endif
