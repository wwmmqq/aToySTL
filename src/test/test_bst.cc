#include "../include/binary_search_tree.cc"
#include <iostream>
int main(int argc, char *argv[])
{	
	MySTL::BinarySearchTree bst;
	bst.Insert(100);
	bst.Insert(50);
	bst.Insert(30);
	bst.Insert(20);
	bst.Insert(10);
	bst.Insert(150);
	bst.Insert(75);
	bst.Insert(80);
	bst.Insert(25);
	bst.Insert(125);
	bst.Insert(175);
	bst.Insert(200);
	std::cout << "height: " << bst.Height() <<std::endl;
	std::cout << "		print bst: 		\n";
	bst.PrintInorder();
	bst.Erase(30);
	bst.Erase(125);
	bst.Erase(150);
	std::cout << "		print bst: 		\n";
	bst.PrintInorder();
	return 0;
}