#include "binary_search_tree.h"
namespace MySTL {
	BinarySearchTree::node* BinarySearchTree::FindMin(node* p) {
		if(nullptr == p)
			return nullptr;

		while(p->left) {
			p = p->left;
		}
		return p;
	}

	BinarySearchTree::node* BinarySearchTree::FindMax(node* p) {
		if(nullptr == p)
			return nullptr;

		while(p->right) {
			p = p->left;
		}
		return p;
	}

	BinarySearchTree::node* BinarySearchTree::FindValue(value_type val, node* p) {
		while(nullptr != p) {
			if (val < p->data)
				p = p->left;
			else if (val > p->data)
				p = p->right;
			else {
				break;
			}
		}
		return p;
	}

	void BinarySearchTree::InsertPvt(value_type val, node* &ptr) {
		if(nullptr == ptr) {
			ptr = new node(val);
			size_++;
		} else if (val < ptr->data) {
			InsertPvt(val, ptr->left);

		} else if (val > ptr->data) {
			InsertPvt(val, ptr->right);

		} else {
			return;
		}
	}

	void BinarySearchTree::ErasePvt(value_type val, node* &ptr) {
		if (ptr == 0)
			return;
		if (val < ptr->data)
			return ErasePvt(val, ptr->left);
		else if (val > ptr->data)
			return ErasePvt(val, ptr->right);
		else{ // found
			if (ptr->left != 0 && ptr->right != 0){// has two children
				size_t choose = size_ % 2;
				//random to erase left or right
				auto pos = choose == 0 ? FindMin(ptr->right) : FindMax(ptr->left);
				ptr->data = pos->data;
				return (choose == 0 ? ErasePvt(pos->data, ptr->right) : ErasePvt(pos->data, ptr->left));
			} else{ //has one or no child
				auto temp = ptr;
				if (nullptr != ptr->left)
					ptr = ptr->left;
				else
					ptr = ptr->right;
				delete temp; // segmentation fault: because err: node* ptr shold be: node* &ptr
				temp = nullptr;
				--size_;
			}
		}
	}

	void BinarySearchTree::DeleteBST(node *ptr) {
		if(ptr) {
			DeleteBST(ptr->left);
			DeleteBST(ptr->right);
			if(nullptr != ptr) {
				delete ptr;
				ptr = nullptr;
			} else {
				return;
			}
		}
	}

	size_t BinarySearchTree::HeightPvt(node *ptr) {
		size_t height_l = 0; 
		size_t height_r = 0;
		if(ptr->left){
			height_l = 1 + HeightPvt(ptr->left);
		}

		if(ptr->right){
			height_r = 1 + HeightPvt(ptr->right);
		}

		return height_l > height_r ? height_l : height_r;
	}

	void BinarySearchTree::PrintInorderPvt(node * ptr) {
		if (ptr) {
			PrintInorderPvt(ptr->left);
			std::cout << ptr->data << "\n";
			PrintInorderPvt(ptr->right);
		}
	}
	void BinarySearchTree::PrintPreorderPvt(node *ptr) {
		if (ptr) {
			std::cout << ptr->data << "\n";
			PrintInorderPvt(ptr->left);
			PrintInorderPvt(ptr->right);
		}
	}
	void BinarySearchTree::PrintPostorderPvt(node *ptr) {
		if (ptr) {
			PrintInorderPvt(ptr->left);
			PrintInorderPvt(ptr->right);
			std::cout << ptr->data << "\n";
		}
	}

	BinarySearchTree::~BinarySearchTree() {
		DeleteBST(root_);
	}
}