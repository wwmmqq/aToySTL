#include "binary_search_tree.h"
namespace MySTL {
	BinarySearchTree::node* BinarySearchTree::FindMin(node* p) {
		while(nullptr != p && nullptr != p->left) {
			p = p->left;
		}
		return p;
	}

	BinarySearchTree::node* BinarySearchTree::FindMax(node* p) {
		while(nullptr != p && nullptr != p->right) {
			p = p->right;
		}
		return p;
	}

	BinarySearchTree::node* BinarySearchTree::FindValue(value_type val) {
		auto p = root_;
		while(nullptr != p) {
			if (val < p->data)
				p = p->left;
			else if (val > p->data)
				p = p->right;
			else
				break;
		}
		return p;
	}

	void BinarySearchTree::InsertAux(value_type val, node* &ptr) {
		if(nullptr == ptr) {
			ptr = new node(val);
			size_++;
			//std::cout << "Insert new: "<<ptr->data <<"\n";
		} else if (val < ptr->data) {
			InsertAux(val, ptr->left);

		} else if (val > ptr->data) {
			InsertAux(val, ptr->right);

		} else {
			return;
		}
	}

	void BinarySearchTree::EraseAux(value_type val, node* ptr) {
		if (ptr == 0)
			return;
		if (val < ptr->data)
			return EraseAux(val, ptr->left);
		else if (val > ptr->data)
			return EraseAux(val, ptr->right);
		else{ // found
			if (ptr->left != 0 && ptr->right != 0){// has two children
				size_t choose = size_ % 2;
				//random to erase left or right
				auto pos = choose == 0 ? FindMin(ptr->right) : FindMax(ptr->left);
				ptr->data = pos->data;
				return (choose == 0 ? EraseAux(pos->data, ptr->right) : EraseAux(pos->data, ptr->left));
			} else{ //has one or no child
				auto temp = ptr;
				if (ptr->left == 0)
					ptr = ptr->right;
				else
					ptr = ptr->left;
					//delete temp; // segmenfault
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

	void BinarySearchTree::PrintInorderAux(node * ptr) {
		if (ptr) {
			PrintInorderAux(ptr->left);
			std::cout << ptr->data << "\n";
			PrintInorderAux(ptr->right);
		}
	}
	void BinarySearchTree::PrintPreorderAux(node *ptr) {
		if (ptr) {
			std::cout << ptr->data << "\n";
			PrintInorderAux(ptr->left);
			PrintInorderAux(ptr->right);
		}
	}
	void BinarySearchTree::PrintPostorderAux(node *ptr) {
		if (ptr) {
			PrintInorderAux(ptr->left);
			PrintInorderAux(ptr->right);
			std::cout << ptr->data << "\n";
		}
	}

	BinarySearchTree::~BinarySearchTree() {
		DeleteBST(root_);
	}
}

int main(int argc, char *argv[])
{	
	MySTL::BinarySearchTree bst;
	bst.Insert(2);
	bst.Insert(1);
	bst.Insert(-1);
	bst.Insert(0);
	bst.Insert(3);
	std::cout << "		print bst: 		\n";
	bst.PrintInorder();
	bst.Erase(2);
	std::cout << "		print bst: 		\n";
	bst.PrintInorder();
	return 0;
}