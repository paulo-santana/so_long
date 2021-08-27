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
	const unsigned int	BIT_NOISE1 = 0x68e31da4;
	const unsigned int	BIT_NOISE2 = 0xb5297a4d;
	const unsigned int	BIT_NOISE3 = 0x1b56c4e9;
	unsigned int		mangledBits;

	mangledBits = (unsigned int)positionX;
	mangledBits *= BIT_NOISE1;
	mangledBits += seed;
	mangledBits ^= (mangledBits >> 8);
	mangledBits += (BIT_NOISE2);
	mangledBits ^= (mangledBits << 8);
	mangledBits *= (BIT_NOISE3);
	mangledBits ^= (mangledBits >> 8);
	return (mangledBits);
}

unsigned int	get_random_int(unsigned int seed)
{
	static int	position;

	return (get_random_noise(position++, seed));
}
