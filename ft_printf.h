#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_params
{
	va_list	ap;
	int		width;
	int		precis;
	int		flag_zero;
	int		zero_perc;
	int		point;
	int		flag_dash;
	int		result;
}				t_params;

int			ft_printf(const char *str, ...);
void		ft_conver_c(int code, t_params *param);
void		ft_conver_s(char *str, t_params *param);
void		ft_conver_di(long nbr, t_params *param);
void		ft_conver_u(unsigned int nbr, t_params *param);
void		ft_conver_x(unsigned long nbr, t_params *param);
void		ft_conver_X(unsigned long nbr, t_params *param);
void		ft_conver_p(size_t pntr, t_params *param);
void		ft_conver_pct(t_params *param);
t_params	*ft_init_param(t_params *param);
void		ft_putchar_param(char c, t_params *param);
void		ft_putstr_param(char *str, int len, t_params *param);
int			ft_strlen(const char *str);
char		*ft_itoa_base(unsigned long nbr, int base);
void		ft_right_width(t_params *param);
void		ft_left_width(char *str, t_params *param);
int			ft_fill_zero (char *str, int len, t_params *param);
void		ft_parse_type(const char *str, int i, t_params *param, va_list ap);

#endif