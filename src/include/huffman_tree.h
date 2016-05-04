#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>// std::priority_queue
namespace MySTL {

template<class T>
class HuffmanTree {
private:
	struct node {
		node *left;
		node *right;
		node *parent;
		long long weight;
		T data;
		node(){};
		explicit node(T &d, long long w, node* l = nullptr, node* r = nullptr, node* p=nullptr)
					 :data(d), weight(w), left(l), right(r), parent(p) {}
	};
	struct Comp {
	    bool operator()(const node* a, const node* b){
	        return a->weight > b->weight;
	    }
    };

	node* root_;
	std::priority_queue<node*, std::vector<node*>, Comp> qnodes_;
public:
	HuffmanTree() {};

	~HuffmanTree() {
		DeleteTree(root_);
	}

	void AddNode(T, long long);
	void PrePrint() {
		PrePrintPvt(root_);
	}
	void BuildHuffmanTree();

private:
	void PrePrintPvt(node*);
	void DeleteTree(node* &);
};

}
#include "huffman_tree.cc"
#endif //_HUFFMAN_TREE_H_
