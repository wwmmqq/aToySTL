#include <cstddef>
#include <iostream>
namespace MySTL {
	//template <class Key, class T>
	class BinarySearchTree {
	public:
		struct node {
			typedef int value_type;
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
		typedef int value_type;
		BinarySearchTree(): root_(nullptr), size_(0){};
		BinarySearchTree(const BinarySearchTree&) = delete;
		BinarySearchTree& operator=(const BinarySearchTree&) = delete;
		~BinarySearchTree();

		void Insert(value_type val) {return InsertAux(val, root_);}
		void Erase(value_type val) {return EraseAux(val, root_);}
		size_t Height() { return HeightAux(root_); }
		void PrintInorder(){ return PrintInorderAux(root_); }
		void PrintPreorder(){ return PrintPreorderAux(root_); }
		void PrintPostorder(){ return PrintPostorderAux(root_); }
	private:
		node* FindMin(node*);
		node* FindMax(node*);
		node* FindValue(value_type val);
		size_t HeightAux(node *);

		void DeleteBST(node *ptr);
		void InsertAux(value_type val, node* &ptr);
		void EraseAux(value_type val, node* ptr);
		void PrintInorderAux(node *ptr);
		void PrintPreorderAux(node *ptr);
		void PrintPostorderAux(node *ptr);
	};
}

/*
if (nullptr != ptr->left && nullptr != ptr->right) {
				// if ptr have two children
				int choose = 1;
				auto place = choose ? FindMax(ptr->left) : FindMin(ptr->right);
				ptr->data = place->data;
				return EraseAux(place->data, place);
			} else {
				// if ptr have only one child
				auto temp = ptr;
				if (ptr->left) {
					ptr = ptr->left;
				}
				else if (ptr->right)
					ptr = ptr->right;

				// leaf can be delete
				if (!ptr->left && !ptr->right)
					delete temp;
			}
*/