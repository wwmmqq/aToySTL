#include <iostream>
#include "../include/avl_tree.cc"

int main(int argc, char const *argv[])
{
	MySTL::AVLTree<int> myavltree;

	for (int i = 1; i < 7; ++i) {
		myavltree.Insert(i);
	}

	myavltree.Erase(4);

	std::cout << "pre: ";
	myavltree.PrintPreorder();
	std::cout << std::endl;
	std::cout << "Post: ";
	myavltree.PrintPostorder();
	std::cout << std::endl;
	std::cout << "In: ";
	myavltree.PrintInorder();
	std::cout <<std::endl;
	std::cout <<"height: "<< myavltree.GetHeight()<<std::endl;
	return 0;
}