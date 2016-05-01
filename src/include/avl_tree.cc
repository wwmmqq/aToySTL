#include <iostream>
#include "avl_tree.h"

namespace MySTL{
template <class K>
typename AVLTree<K>::node * AVLTree<K>::FindKeyPvt(K key, node * p) {
	while(nullptr != p && key != p->key) {
		if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}

template <class K>
typename AVLTree<K>::node* AVLTree<K>::FindMinPvt(node* p) {
	if(nullptr == p)
		return nullptr;

	while(p->left) {
		p = p->left;
	}
	return p;
}

template<class K>
typename AVLTree<K>::node* AVLTree<K>::FindMaxPvt(node* p) {
	if(nullptr == p)
		return nullptr;

	while(p->right) {
		p = p->left;
	}
	return p;
}

// ll rotate
template<class K>
void AVLTree<K>::SingleLeftLeftRotate(node* &p) {
	std::cout<< "sll rotate: " << p->key <<std::endl;
	auto temp = p->left;
	p->left = temp->right;
	temp->right = p;

	p->height = max(GetHeightPvt(p->left), GetHeightPvt(p->right)) + 1;
	temp->height = max(GetHeightPvt(temp->left), p->height) + 1;

	p = temp;
}

//lr rotate
template<class K>
void AVLTree<K>::DoubleLeftRightRotate(node* &p) {
	SingleRightRightRotate(p->left);
	SingleLeftLeftRotate(p);
}

//rl rotate
template<class K>
void AVLTree<K>::DoubleRightLeftRotate(node* &p) {
	SingleLeftLeftRotate(p->right);
	SingleRightRightRotate(p);
}

//rr rotate
template<class K>
void AVLTree<K>::SingleRightRightRotate(node* &p) {
	std::cout<< "srr rotate: " << p->key <<std::endl;
	auto temp = p->right;
	p->right = temp->left;
	temp->left = p;

	p->height = max(GetHeightPvt(p->left), GetHeightPvt(p->right)) + 1;
	temp->height = max(p->height, GetHeightPvt(temp->right)) + 1;
	
	p = temp;
}


template<class K>
void AVLTree<K>::InsertPvt(K key, node* &p) {
	if(nullptr == p) {
		p = new node(key);
		size_++;

	} else if (key < p->key) {
		InsertPvt(key, p->left);
		if (GetHeightPvt(p->left) - GetHeightPvt(p->right) == 2) {
			if (key < p->left->key)
				SingleLeftLeftRotate(p);
			else
				DoubleLeftRightRotate(p);
		}
	} else if (key > p->key) {
		InsertPvt(key, p->right);
		if (GetHeightPvt(p->right) - GetHeightPvt(p->left) == 2) {
			if(key < p->right->key)
				DoubleRightLeftRotate(p);				
			else
				SingleRightRightRotate(p);
		}
	}

	p->height = max(GetHeightPvt(p->left), GetHeightPvt(p->right)) + 1;
}

template<class K>
void AVLTree<K>::ErasePvt(K key, node* &p) {
	if (nullptr == p)
		return;
	if (key < p->key) {
		ErasePvt(key, p->left);
	}else if (key > p->key) {
		ErasePvt(key, p->right);
	}else { // found
		if (p->left != 0 && p->right != 0){// has two children
			size_t choose = size_ % 2;
			//random to erase left or right
			auto pos = choose == 0 ? FindMinPvt(p->right) : FindMaxPvt(p->left);
			p->key = pos->key;
			return (choose == 0 ? ErasePvt(pos->key, p->right) : ErasePvt(pos->key, p->left));
		}else{ //has one or no child
			auto temp = p;
			if (nullptr != p->left)
				p = p->left;
			else
				p = p->right;
			delete temp; // segmentation fault: because err: node* p shold be: node* &p
			temp = nullptr;
			--size_;
		}
	}

	if(p) {
		p->height = max(GetHeightPvt(p->left), GetHeightPvt(p->right)) + 1;

		if (GetHeightPvt(p->left) - GetHeightPvt(p->right) == 2) {
			// left is higher
			if (nullptr == p->left->right)
				SingleLeftLeftRotate(p);
			else
				DoubleLeftRightRotate(p);

		} else if (GetHeightPvt(p->right) - GetHeightPvt(p->left) == 2) {
			// right is higher
			if (nullptr == p->right->left)
				SingleRightRightRotate(p);
			else
				DoubleRightLeftRotate(p);
		}
	}
}

template<class K>
void AVLTree<K>::PrintPreorderPvt(node* p) {
	if(p) {
		std::cout << p->key <<"  ";
		PrintPreorderPvt(p->left);
		PrintPreorderPvt(p->right);
	}
}

template<class K>
void AVLTree<K>::PrintInorderPvt(node* p) {
	if(p) {
		PrintInorderPvt(p->left);
		std::cout << p->key <<"  ";
		PrintInorderPvt(p->right);
	}
}

template<class K>
void AVLTree<K>::PrintPostorderPvt(node* p) {
	if(p) {
		PrintPostorderPvt(p->left);
		PrintPostorderPvt(p->right);
		std::cout << p->key <<"  ";
	}
}


template<class K>
void AVLTree<K>::DeleteAVLTree(node *p) {
	if(p) {
		DeleteAVLTree(p->left);
		DeleteAVLTree(p->right);
		if(nullptr != p) {
			delete p;
			p = nullptr;
		} else {
			return;
		}
	}
}

template<class K>
AVLTree<K>::~AVLTree() {
	DeleteAVLTree(root_);
}
}