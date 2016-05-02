#ifndef _BIT_MAP_H_
#define _BIT_MAP_H_
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>

namespace MySTL{

class BitMap {
private:
	size_t size_;// number of bit
	size_t size_uint32_;
	uint32_t* start_;
	uint32_t* end_;

public:
	BitMap(size_t);
	~BitMap();

	void Set(size_t pos);
	void Reset(size_t pos);
	bool Test(size_t pos);
	void Clear();

	std::string ToString() const;
	size_t GetBitSize() {return size_;};
	size_t GetUint32Count() {return size_uint32_;};
};
}

#include "bit_map.cc"
#endif //_BIT_MAP_H_