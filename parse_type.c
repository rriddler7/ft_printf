#include "ft_printf.h"

void	ft_parse_type(const char *str, int i, t_params *param, va_list ap)
{
	if (str[i] == 'c')
		ft_conver_c(va_arg(ap, int), param);
	else if (str[i] == 's')
		ft_conver_s(va_arg(ap, char *), param);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_conver_di(va_arg(ap, int), param);
	else if (str[i] == 'u')
		ft_conver_u(va_arg(ap, unsigned int), param);
	else if (str[i] == 'x')
		ft_conver_x(va_arg(ap, unsigned int), param);
	else if (str[i] == 'X')
		ft_conver_X(va_arg(ap, unsigned int), param);
	else if (str[i] == 'p')
		ft_conver_p(va_arg(ap, size_t), param);
	else if (str[i] == '%')
		ft_conver_pct(param);
	else
		ft_putchar_param(str[i], param);
}
