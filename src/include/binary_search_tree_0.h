#include <cstddef>
#include <iostream>
#include <string>
namespace MySTL {
	//template<class T>
	class BinarySearchTree {
	public:
		//typedef int value_type;
		typedef std::string value_type;
		struct node {
			value_type data;

			node *left;
			node *right; 
			explicit node(value_type mydata, node *myleft = nullptr, node *myright =nullptr)
						 :data(mydata), left(myleft), right(myright){}
		};

	private:
		node * root_;
		size_t size_; // cnt of node

	public:
		BinarySearchTree(): root_(nullptr), size_(0){};
		BinarySearchTree(const BinarySearchTree&) = delete;
		BinarySearchTree& operator=(const BinarySearchTree&) = delete;
		~BinarySearchTree();

		void Insert(value_type val) {return InsertPvt(val, root_);}
		void Erase(value_type val) {return ErasePvt(val, root_);}
		size_t Height() { return HeightPvt(root_); }
		void PrintInorder(){ return PrintInorderPvt(root_); }
		void PrintPreorder(){ return PrintPreorderPvt(root_); }
		void PrintPostorder(){ return PrintPostorderPvt(root_); }
	private:
		node* FindMin(node*);
		node* FindMax(node*);
		node* FindValue(value_type, node*);
		size_t HeightPvt(node *);

		void DeleteBST(node *ptr);
		void InsertPvt(value_type val, node* &ptr);
		void ErasePvt(value_type val, node* &ptr);
		void PrintInorderPvt(node *ptr);
		void PrintPreorderPvt(node *ptr);
		void PrintPostorderPvt(node *ptr);
	};
}