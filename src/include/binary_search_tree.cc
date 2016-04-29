#include "binary_search_tree.h"
namespace MySTL {

template <class T>
typename BinarySearchTree<T>::node* BinarySearchTree<T>::FindMin(node* p) {
	if(nullptr == p)
		return nullptr;

	while(p->left) {
		p = p->left;
	}
	return p;
}

template<class T>
typename BinarySearchTree<T>::node* BinarySearchTree<T>::FindMax(node* p) {
	if(nullptr == p)
		return nullptr;

	while(p->right) {
		p = p->left;
	}
	return p;
}

template<class T>
typename BinarySearchTree<T>::node* BinarySearchTree<T>::FindValue(T val, node* p) {
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

template<class T>
void BinarySearchTree<T>::InsertPvt(T val, node* &ptr) {
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

template<class T>
void BinarySearchTree<T>::ErasePvt(T val, node* &ptr) {
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

template<class T>
void BinarySearchTree<T>::DeleteBST(node *ptr) {
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

template<class T>
size_t BinarySearchTree<T>::HeightPvt(node *ptr) {
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

template<class T>
void BinarySearchTree<T>::PrintInorderPvt(node * ptr) {
	if (ptr) {
		PrintInorderPvt(ptr->left);
		std::cout << ptr->data << "\n";
		PrintInorderPvt(ptr->right);
	}
}

template<class T>
void BinarySearchTree<T>::PrintPreorderPvt(node *ptr) {
	if (ptr) {
		std::cout << ptr->data << "\n";
		PrintInorderPvt(ptr->left);
		PrintInorderPvt(ptr->right);
	}
}

template<class T>
void BinarySearchTree<T>::PrintPostorderPvt(node *ptr) {
	if (ptr) {
		PrintInorderPvt(ptr->left);
		PrintInorderPvt(ptr->right);
		std::cout << ptr->data << "\n";
	}
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
	DeleteBST(root_);
}
}