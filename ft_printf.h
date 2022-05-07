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

#endif
