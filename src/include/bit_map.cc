namespace MySTL {

	BitMap::BitMap(size_t n):size_(n){
		size_uint32_ = size_t(n>>5); // equal: n/32
		if (n%32)
			size_uint32_ +=1;
		//start_ = new uint32_t[size_uint32_] // default initialized (ie nothing happens)
		start_ = new uint32_t[size_uint32_](); // zero initialized (ie all elements set to 0)
		end_ = start_ + size_uint32_-1;
	}

	BitMap::~BitMap() {
		delete []start_;
	}

	void BitMap::Set(size_t pos) {
		pos--;
		if(pos > size_){
			throw std::out_of_range("out of range");
		}
		*(start_ + (pos>>5)) |= (1 << pos%32) ; // operator '>>' has lower precedence than '+';
	}
	
	void BitMap::Reset(size_t pos) {
		pos--;
		if(pos > size_){
			throw std::out_of_range("out of range");
		}
		*(start_ + (pos>>5)) &= ~(1 << pos%32) ;
	}
	bool BitMap::Test(size_t pos) {
		pos--;
		if(pos > size_){
			throw std::out_of_range("out of range");
		}
		return *(start_ + (pos>>5)) & (1 << pos%32);
	}
	void BitMap::Clear() {
		for(size_t i = 0; i < size_uint32_; ++i) {
			*(start_ + i) &= 0x00;
		}
	}

	std::string BitMap::ToString() const {
		std::string result;
		for(size_t i = 0; i < size_uint32_; ++i) {
			uint32_t temp = *(start_ + i);
			for (size_t i = 0; i < 32; ++i) {
				if(temp & (1<<i))
					result += '1';
				else
					result += '0';
			}
		}
		return result;
	}
}