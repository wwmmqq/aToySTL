#include <iostream>
#include "../include/bit_map.h"

int main(int argc, char const *argv[])
{
	//  n >= 1 && n <= N
	MySTL::BitMap bm(32);
	bm.Set(20);
	std::cout << bm.Test(20) << std::endl;
	bm.Reset(20);
	std::cout << bm.Test(1) << std::endl;
	bm.Set(20);
	bm.Set(21);
	bm.Set(1);
	bm.Set(2);
	bm.Set(32);
	bm.Set(31);
	std::cout << bm.ToString() <<std::endl;
	bm.Clear();
	std::cout << bm.ToString() <<std::endl;
	std::cout << bm.Test(20) << std::endl;
	std::cout << bm.GetBitSize() << std::endl;
	std::cout << bm.GetUint32Count() << std::endl;
	return 0;
}