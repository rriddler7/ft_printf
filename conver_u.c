#include "ft_printf.h"

void	ft_conver_u(unsigned int nbr, t_params *param)
{
	char	*str;
	int		len;

	str = ft_itoa_base(nbr, 10);
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
