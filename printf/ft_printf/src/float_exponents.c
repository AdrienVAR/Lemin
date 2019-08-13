/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_exponents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:24:08 by acostaz           #+#    #+#             */
/*   Updated: 2019/07/18 18:28:31 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	normalize_float_neg2(double *nb, int *exponent)
{
	if (*nb < 1e-7)
	{
		*nb *= 1e8;
		*exponent -= 8;
	}
	if (*nb < 1e-3)
	{
		*nb *= 1e4;
		*exponent -= 4;
	}
	if (*nb < 1e-1)
	{
		*nb *= 1e2;
		*exponent -= 2;
	}
	if (*nb < 1e0)
	{
		*nb *= 1e1;
		*exponent -= 1;
	}
}

static void	normalize_float_neg1(double *nb, int *exponent)
{
	if (*nb < 1e-255)
	{
		*nb *= 1e256;
		*exponent -= 256;
	}
	if (*nb < 1e-127)
	{
		*nb *= 1e128;
		*exponent -= 128;
	}
	if (*nb < 1e-63)
	{
		*nb *= 1e64;
		*exponent -= 64;
	}
	if (*nb < 1e-31)
	{
		*nb *= 1e32;
		*exponent -= 32;
	}
	if (*nb < 1e-15)
	{
		*nb *= 1e16;
		*exponent -= 16;
	}
}

static void	normalize_float_pos2(double *nb, int *exponent)
{
	if (*nb >= 1e8)
	{
		*nb /= 1e8;
		*exponent += 8;
	}
	if (*nb >= 1e4)
	{
		*nb /= 1e4;
		*exponent += 4;
	}
	if (*nb >= 1e2)
	{
		*nb /= 1e2;
		*exponent += 2;
	}
	if (*nb >= 1e1)
	{
		*nb /= 1e1;
		*exponent += 1;
	}
}

static void	normalize_float_pos1(double *nb, int *exponent)
{
	if (*nb >= 1e256)
	{
		*nb /= 1e256;
		*exponent += 256;
	}
	if (*nb >= 1e128)
	{
		*nb /= 1e128;
		*exponent += 128;
	}
	if (*nb >= 1e64)
	{
		*nb /= 1e64;
		*exponent += 64;
	}
	if (*nb >= 1e32)
	{
		*nb /= 1e32;
		*exponent += 32;
	}
	if (*nb >= 1e16)
	{
		*nb /= 1e16;
		exponent += 16;
	}
}

int			normalize_float(double *nb)
{
	double	positive_max;
	double	negative_max;
	int		exponent;

	positive_max = 1e7;
	negative_max = 1e-5;
	exponent = 0;
	if (*nb >= positive_max)
	{
		normalize_float_pos1(nb, &exponent);
		normalize_float_pos2(nb, &exponent);
	}
	if (*nb > 0 && *nb <= negative_max)
	{
		normalize_float_neg1(nb, &exponent);
		normalize_float_neg2(nb, &exponent);
	}
	return (exponent);
}
