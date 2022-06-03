#include "ft_printf.h"

static int	ft_parse_digits(const char *str, int i, t_params *param)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (param->point == 1)
		{
			param->precis = param->precis * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			param->width = param->width * 10 + (str[i] - '0');
			i++;
		}
	}
	return (i++);
}

static void	ft_dash(t_params *param)
{
	param->flag_dash = 1;
	if (param->flag_zero)
		param->flag_zero = 0;
}

static void	ft_point(t_params *param)
{
	param->point = 1;
	param->precis = 0;
	if (param->flag_zero)
		param->flag_zero = 0;
}

static int	ft_parse_flags(const char *str, int i, t_params *param, va_list ap)
{
	while (str[i] && str[i] != '%')
	{
		if (str[i] == '.')
		{
			ft_point(param);
			i++;
		}
		else if (str[i] == '-')
		{
			ft_dash(param);
			i++;
		}
		else if (str[i] == '0' && !param->flag_dash && !param->point)
		{
			param->flag_zero = 1;
			param->zero_perc = 1;
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i = ft_parse_digits(str, i, param);
		else
			break ;
	}
	ft_parse_type(str, i, param, ap);
	return (i++);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	t_params	param;
	va_list		ap;

	i = 0;
	param.result = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_init_param(&param);
			i = ft_parse_flags(str, i, &param, ap);
		}
		else
			ft_putchar_param(str[i], &param);
		i++;
	}
	va_end(ap);
	return (param.result);
}
