#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // TO REMOVE, REMOVE ME IDIOT, REMOVE ME//
# include "../libft/includes/libft.h"

# define CONV "cspdiouxX%"
# define LENGTH "0lLhjzt"

/* struct to hold all modifiers %[flags][width][.precision][size]type */ 
typedef struct s_info {
		char	flag[4];
		char	type;
		int		width;
		int		precision;
		int		size;
}		t_info;

typedef	int	conv(va_list *list);

/* Check for all possible modifiers %[flags][width][.precision][size]type */
int	check_flag(char **ptr, t_info *info);
int	check_width(char **ptr, t_info *info, va_list *list);
int	check_precision(char **ptr, t_info *info);
int	check_size(char **ptr, t_info *info);
int	check_conv(char **ptr, t_info *info);

/* converter modifiable base*/
char	*convert(int num, int base);

/* printers for each type , separated to take in considerations modifiers cspdiouxXf%*/ 
int	print_char(va_list *list);
int	print_str(va_list *list);
//int	print_adress(va_list *list);
int	print_int(va_list *list);
int	print_octal(va_list *list);
int	print_unsigned(va_list *list);
int	print_x(va_list *list);
int	print_X(va_list *list);
//int	print_float(va_list *list);
int	print_percentage(va_list *list);

int		ft_printf(char *str, ...);

/* helpers to put different types (might be able to remove with convert function) */
void	ft_putunsigned(unsigned int nb);
void	ft_putoctal(unsigned int nb);
void	ft_puthexa(unsigned int nb);
void	ft_putupperhexa(unsigned int nb);

#endif
