#include "ft_printf.h"

void	ft_conver_c(int code, t_params *param)
{
	int	i;

	i = 1;
	while (param->width > i && !param->flag_dash)
	{
		ft_putchar_param(' ', param);
		i++;
	}
	ft_putchar_param((char)code, param);
	while (param->width > i)
	{
		ft_putchar_param(' ', param);
		i++;
	}
}

void	ft_conver_s(char *str, t_params *param)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (param->point && param->precis < 1)
		param->precis = 0;
	if (param->precis != -1 && param->precis < len)
		len = param->precis;
	while (param->width > len && !param->flag_dash)
	{
		ft_putchar_param(' ', param);
		param->width--;
	}
	if (param->precis != 0)
		ft_putstr_param(str, len, param);
	while (param->width > len)
	{
		ft_putchar_param(' ', param);
		param->width--;
	}
}

void	ft_conver_pct(t_params *param)
{
	int	i;

	i = 1;
	while (param->width > i && !param->flag_dash)
	{
		if (param->zero_perc)
		{
			ft_putchar_param('0', param);
			i++;
		}
		else
		{
			ft_putchar_param(' ', param);
			i++;
		}
	}
	ft_putchar_param('%', param);
	while (param->width > i)
	{
		ft_putchar_param(' ', param);
		i++;
	}
}
