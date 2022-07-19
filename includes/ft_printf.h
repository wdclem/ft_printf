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
		va_list	list;
		char	*copy;
		char	*mod;
		char	*minus_mod;
		int		copylen;
		int		modlen;
		char	flag[4];
		char	type;
		int		width;
		int		precision;
		char	size[3];
}		t_info;

typedef	int	conv(t_info *info);

/* Check for all possible modifiers %[flags][width][.precision][size]type */
int	check_flag(char **ptr, t_info *info);
int	check_width(char **ptr, t_info *info);
int	check_precision(char **ptr, t_info *info);
int	check_size(char **ptr, t_info *info);
int	check_conv(char **ptr, t_info *info);

/* converter modifiable base*/
char	*convert(t_info *info, long long num, int base);
void	mod_init(t_info *info);

/* printers for each type , separated to take in considerations modifiers cspdiouxXf%*/ 
int	type_c(t_info *info);
int	print_char(t_info *info);
int	print_str(t_info *info);
//int	print_adress(va_list *list);
int	print_int(t_info *info);
int	print_octal(t_info *info);
int	print_unsigned(t_info *info);
int	print_x(t_info *info);
int	print_X(t_info *info);
//int	print_float(va_list *list);
int	print_percentage(t_info *info);

int		ft_printf(char *str, ...);

/* helpers to put different types (might be able to remove with convert function) */
void	ft_putunsigned(unsigned int nb);
void	ft_putoctal(unsigned int nb);
void	ft_puthexa(unsigned int nb);
void	ft_putupperhexa(unsigned int nb);

#endif
