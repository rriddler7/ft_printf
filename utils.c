#include "ft_printf.h"

t_params	*ft_init_param(t_params *param)
{
	param->width = 0;
	param->precis = -1;
	param->flag_zero = 0;
	param->zero_perc = 0;
	param->point = 0;
	param->flag_dash = 0;
	return (param);
}

void	ft_putchar_param(char c, t_params *param)
{
	param->result += write(1, &c, 1);
}

void	ft_putstr_param(char *str, int len, t_params *param)
{
	while (*str != '\0' && len > 0)
	{
		ft_putchar_param(*str, param);
		str++;
		len--;
	}
}

int	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
