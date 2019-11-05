#include <iostream>
#include "Scramble.h"

/*
Reverisble obfuscation function
Used in DOOM. See https://twitter.com/foone/status/1189249817492557826

{ 7,6,2,4,3,5,1,0 } -> Move bit 0 to 7, 1 to 6, 2 to 2 etc. 
If this is symmetric, the same array can be used to encode and decode. 
*/

int main()
{
	ScrambleType DOOMScramble = { 7,6,2,4,3,5,1,0 };
	for (uint8_t c= 0; c < 255; c++)
	{
		if (ScrambleOriginal(c) != Scramble(c, DOOMScramble))
			std::cout << "Ouch!" << c << "\n";
	}

	ScrambleType AssymetricScramble = { 1,0,2,3,5,4,6,7 };
	for (uint8_t c = 0; c < 255; c++)
	{
		if (c != Scramble(Scramble(c, AssymetricScramble), AssymetricScramble))
			std::cout << "Ouch!" << c << "\n";
	}

	ScrambleType FourStepScramble = { 2,3,4,5,6,7,0,1 };
	for (uint8_t c = 0; c < 255; c++)
	{
		if (c != Scramble(Scramble(Scramble(Scramble(c, FourStepScramble), FourStepScramble), FourStepScramble), FourStepScramble))
			std::cout << "Ouch!" << c << "\n";
	}


}
