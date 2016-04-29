#include "../include/binary_search_tree.cc"
#include <iostream>
#include <string>
/*
int main2()
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
}*/

int main(int argc, char const *argv[])
{
	MySTL::BinarySearchTree<std::string> bst;
	bst.Insert("hello1");
	bst.Insert("hello2");
	bst.Insert("hello3");
	bst.Insert("ahello1");
	bst.Insert("ahello2");
	bst.Insert("bhello1");
	bst.Erase("hello1");
	bst.PrintInorder();

	MySTL::BinarySearchTree<int> bst2;
	bst2.Insert(10);
	bst2.Insert(5);
	bst2.Insert(15);
	bst2.Insert(1);
	bst2.Insert(16);
	bst2.Insert(17);
	bst2.Erase(5);
	bst2.PrintInorder();
	return 0;
}