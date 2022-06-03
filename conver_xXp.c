#include "ft_printf.h"

void	ft_conver_x(unsigned long nbr, t_params *param)
{
	char	*str;
	int		len;

	str = ft_itoa_base(nbr, 16);
	len = ft_strlen(str);
	if (param->precis != -1 && param->precis > len)
		len = param->precis;
	while (param->width > len && !param->flag_dash)
		ft_right_width(param);
	ft_fill_zero(str, len, param);
	if (!nbr && param->precis == 0)
	{
		write(1, "", 0);
		if (param->width)
		{
			param->width++;
			ft_putchar_param(' ', param);
		}
	}
	else
		ft_putstr_param(str, ft_strlen(str), param);
	ft_left_width(str, param);
	free(str);
}

static void	ft_toupperX(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str [i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
}

void	ft_conver_X(unsigned long nbr, t_params *param)
{
	char	*str;
	int		len;

	str = ft_itoa_base(nbr, 16);
	ft_toupperX(str);
	len = ft_strlen(str);
	if (param->precis != -1 && param->precis > len)
		len = param->precis;
	while (param->width > len && !param->flag_dash)
		ft_right_width(param);
	ft_fill_zero(str, len, param);
	if (!nbr && param->precis == 0)
	{
		write(1, "", 0);
		if (param->width)
		{
			param->width++;
			ft_putchar_param(' ', param);
		}
	}
	else
		ft_putstr_param(str, ft_strlen(str), param);
	ft_left_width(str, param);
	free(str);
}

static void	ft_width_p(t_params *param)
{
	ft_putchar_param(' ', param);
	param->width--;
}

void	ft_conver_p(size_t pntr, t_params *param)
{
	char	*str;
	int		len;
	int		flag;

	str = ft_itoa_base(pntr, 16);
	len = ft_strlen(str);
	flag = 0;
	if ((param->point || !param->precis) && *str == '0')
	{
		len = 0;
		flag = 1;
	}
	param->width = param->width - 2;
	while (param->width > len && !param->flag_dash)
		ft_width_p(param);
	write(1, "0x", 2);
	param->result = param->result + 2;
	if (flag == 0)
		ft_putstr_param(str, ft_strlen(str), param);
	while (param->flag_dash && param->width > len)
		ft_width_p(param);
	free(str);
}
