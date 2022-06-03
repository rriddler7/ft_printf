#include "ft_printf.h"

void	ft_right_width(t_params *param)
{
	if (param->flag_zero)
	{
		ft_putchar_param('0', param);
		param->width--;
	}
	else
	{
		ft_putchar_param(' ', param);
		param->width--;
	}
}

void	ft_left_width(char *str, t_params *param)
{
	if (param->flag_dash && (param->precis >= ft_strlen(str)))
	{
		while (param->width > param->precis)
		{
			ft_putchar_param(' ', param);
			param->width--;
		}
	}
	else if (param->flag_dash && (param->precis < ft_strlen(str)))
	{
		while (param->width > ft_strlen(str))
		{
			ft_putchar_param(' ', param);
			param->width--;
		}
	}
}
