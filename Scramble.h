#pragma once

/*
Position to swich to.
*/
using ScrambleType = uint8_t[8];


uint8_t Scramble(uint8_t a, ScrambleType st)
{
	uint8_t ret = 0;
	ScrambleType pow2 = { 1,2,4,8,16,32,64,128 };
	for (uint8_t bit = 0; bit < 8; ++bit)
	{
		int8_t shift = (int8_t)st[bit] - bit;
		if (bit == st[bit])
			ret += (a & pow2[bit]);
		else if (shift < 0)
			ret += (a & pow2[bit]) >> (-shift);
		else
			ret += (a & pow2[bit]) << (shift);
	}

	return ret;
}

uint8_t ScrambleOriginal(uint8_t a)
{
	return ((a & 1) << 7) +
		((a & 2) << 5) +
		((a & 4)) +
		((a & 8) << 1) +
		((a & 16) >> 1) +
		((a & 32)) +
		((a & 64) >> 5) +
		((a & 128) >> 7);
}



