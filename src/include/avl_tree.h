#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <cstddef>

namespace MySTL {

	template<class K>
	class AVLTree {
	public:
		typedef K value_type;
		struct node {
			K key;
			node *left;
			node *right;
			size_t height;
			explicit node(K k, node* l=nullptr, node *r=nullptr, size_t h=1)
						 :key(k), left(l), right(r), height(h){}
		};

	private:
		node* root_;
		size_t size_;

	public:
		AVLTree(): root_(nullptr), size_(0) {};
		AVLTree(const AVLTree&) = delete;
		AVLTree& operator =(const AVLTree&) = delete;
		~AVLTree();

		void Insert(const K val) {return InsertPvt(val, root_);};
		void Erase(const K val) {return ErasePvt(val, root_);};
		void FindKey(const K val) {return FindKeyPvt(val, root_);};
		size_t GetHeight() {return GetHeightPvt(root_);};
		void PrintInorder(){ return PrintInorderPvt(root_);}
		void PrintPreorder(){ return PrintPreorderPvt(root_);}
		void PrintPostorder(){ return PrintPostorderPvt(root_);}

	private:
		void InsertPvt(K val, node *&);
		void ErasePvt(K val, node *&);
		size_t GetHeightPvt(node *ptr) const { return nullptr == ptr ? 0 : ptr->height;}
		void PrintInorderPvt(node *);
		void PrintPreorderPvt(node *);
		void PrintPostorderPvt(node *);
		void DeleteAVLTree(node *);

	private:
		inline int max(int a, int b) { return a>b ? a : b;}
		node * FindKeyPvt(K val, node *);
		node * FindMinPvt(node *);
		node * FindMaxPvt(node *);
		void SingleLeftLeftRotate(node *&);
		void DoubleLeftRightRotate(node *&);
		void DoubleRightLeftRotate(node *&);
		void SingleRightRightRotate(node *&);
	};
}

//https://zh.wikipedia.org/wiki/AVL%E6%A0%91
#endif	// _AVL_TREE_H_