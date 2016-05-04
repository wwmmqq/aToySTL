namespace MySTL {

template<class T>
void HuffmanTree<T>::BuildHuffmanTree() {
	while(qnodes_.size() != 1) {
		node* p1 = qnodes_.top();
		qnodes_.pop();
		node* p2 = qnodes_.top();
		qnodes_.pop();

		node* p = new node();
		p->weight = p1->weight + p2->weight;
		if (p1->weight < p2->weight) {
			p->left = p1;
			p->right = p2;
		} else {
			p->left = p2;
			p->right = p1;
		}

		qnodes_.push(p);
		//std::cout << p1->weight <<" "<< p2->weight << "\n";
	}

	root_ = qnodes_.top();
}

template<class T>
void HuffmanTree<T>::AddNode(T d, long long weight) {
	node * p = new node(d, weight);
	qnodes_.push(p);
}

template<class T>
void HuffmanTree<T>::DeleteTree(node* &p) {
	if(p) {
		DeleteTree(p->left);
		DeleteTree(p->right);
		delete p;
	}
}

template<class T>
void HuffmanTree<T>::PrePrintPvt(node* p) {
	if(p) {
		PrePrintPvt(p->left);
		std::cout << p->weight << " ";
		PrePrintPvt(p->right);
	}
}

}//MySTL