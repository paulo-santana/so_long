/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:17:44 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/26 19:17:44 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

unsigned int	get_random_seed(void)
{
	int	random_seed;
	int	fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (0xabcdeb);
	read(fd, &random_seed, sizeof(unsigned int));
	return (random_seed);
}

/**
 * This function was fetched from 
 * */

unsigned int	get_random_noise(int positionX, unsigned int seed)
{
	const unsigned int	bit_noise1 = 0x68e31da4;
	const unsigned int	bit_noise2 = 0xb5297a4d;
	const unsigned int	bit_noise3 = 0x1b56c4e9;
	unsigned int		mangled_bits;

	mangled_bits = (unsigned int)positionX;
	mangled_bits *= bit_noise1;
	mangled_bits += seed;
	mangled_bits ^= (mangled_bits >> 8);
	mangled_bits += (bit_noise2);
	mangled_bits ^= (mangled_bits << 8);
	mangled_bits *= (bit_noise3);
	mangled_bits ^= (mangled_bits >> 8);
	return (mangled_bits);
}

unsigned int	get_random_int(unsigned int seed)
{
	static int	position;

	return (get_random_noise(position++, seed));
}
