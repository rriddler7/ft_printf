#include "ft_printf.h"

static int	ft_digits_number(unsigned long number, int base)
{
	int	size;

	size = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		size++;
		number /= base;
	}
	return (size);
}

char	*ft_itoa_base(unsigned long nbr, int base)
{
	int		len;
	char	*str;

	len = ft_digits_number(nbr, base);
	str = malloc((len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}
