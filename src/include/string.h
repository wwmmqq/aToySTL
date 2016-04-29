#ifndef _STRING_H_
#define _STRING_H_

#include <cstring>

namespace MySTL {
	class string {
	private:
		char * start_;
		char * end_;
		char * endOfStorage_;

	public:
		string() : start_(nullptr), end_(nullptr) {};
		string(const string& str);
		string(const char* s);
		string(size_t n, char c);

		string& operator= (const string& str);
		string& operator= (const char* s);
		string& operator= (char c);

		~string();

		char* begin(){ return start_; }
		const char* begin() { return const start_; }
		char* end() { return end_; }
		const char* end() {return const end_; }
	};
}
#endif
//_STRING_H_