#include "ft_printf.h"

static long	ft_neg_nbr(long nbr, int *minus)
{
	if (nbr < 0)
	{
		nbr *= -1;
		*minus = 1;
	}
	return (nbr);
}

int	ft_fill_zero (char *str, int len, t_params *param)
{
	while (len > ft_strlen(str))
	{
		ft_putchar_param('0', param);
		len--;
	}
	return (len);
}

static void	ft_nbr_null(t_params *param)
{
	write(1, "", 0);
	if (param->width)
	{
		param->width++;
		ft_putchar_param(' ', param);
	}
}

void	ft_conver_di(long nbr, t_params *param)
{
	char	*str;
	int		minus;
	int		len;

	minus = 0;
	nbr = ft_neg_nbr(nbr, &minus);
	str = ft_itoa_base(nbr, 10);
	len = ft_strlen(str);
	if (param->precis != -1 && param->precis > ft_strlen(str))
		len = param->precis;
	if (minus == 1 && param->width > 0)
		param->width--;
	if (minus == 1 && param->flag_zero)
		ft_putchar_param('-', param);
	while (param->width > len && !param->flag_dash)
		ft_right_width(param);
	if (minus == 1 && !param->flag_zero)
		ft_putchar_param('-', param);
	ft_fill_zero(str, len, param);
	if (!nbr && param->precis == 0)
		ft_nbr_null(param);
	else
		ft_putstr_param(str, ft_strlen(str), param);
	ft_left_width(str, param);
	free(str);
}
