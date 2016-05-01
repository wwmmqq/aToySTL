#ifndef _SKIP_LIST_HEAD_H_
#define _SKIP_LIST_HEAD_H_

namespace MySTL {
	class SkipList {
	typedef std::string value_type;
	private:
		struct Node {
			int key;
			int value;
			struct Nodde *next;
		};

		size_t level_;
		struct Node * head_;

	public:
		SkipList();
		~SkipList();

		SkipList(const SkipList&) = delete;
		SkipList& operator = (const SkipList&) = delete;

	};
}

#endif //_SKIP_LIST_HEAD_H_