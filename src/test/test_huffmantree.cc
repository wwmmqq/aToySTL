#include "../include/huffman_tree.h"
#include <string>
int main(int argc, char const *argv[])
{
	MySTL::HuffmanTree<int> mytree1;
	mytree1.AddNode(1,0);
	mytree1.AddNode(2,1);
	mytree1.AddNode(3,2);
	mytree1.AddNode(4,3);
	mytree1.AddNode(5,4);
	mytree1.BuildHuffmanTree();
	mytree1.PrePrint();
	std::cout<<std::endl;

	MySTL::HuffmanTree<std::string> mytree2;
	mytree2.AddNode("hello",0);
	mytree2.AddNode("wmq",1);
	mytree2.AddNode("b",2);
	mytree2.BuildHuffmanTree();
	mytree2.PrePrint();
	std::cout<<std::endl;


	return 0;

}