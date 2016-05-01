#include <iostream>
#include "../include/avl_tree.cc"

int main(int argc, char const *argv[])
{
	MySTL::AVLTree<int> myavltree;
	myavltree.Insert(4);
	myavltree.Insert(3);
	myavltree.Insert(2);
	std::cout << "Post: ";
	myavltree.PrintPostorder();
	std::cout<<std::endl;

	myavltree.Insert(1);
	std::cout << "Post: ";
	myavltree.PrintPostorder();
	std::cout<<std::endl;

	myavltree.Insert(5);
	myavltree.Insert(6);

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