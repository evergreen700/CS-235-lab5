#include <iostream>
#include "Node.h"


Node::Node(){
	value = -1;
	leftChildptr = NULL;
	rightChildptr = NULL;
}
Node::~Node(){}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
int Node::getData() const{
	return value;
}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
Node * Node::getLeftChild() const{
	return leftChildptr;
}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
Node * Node::getRightChild() const{
	return rightChildptr;
}

void Node::setData(int _data){
	this->value = _data;
}

void Node::setLeftChild(Node* _left){
	this->leftChildptr = _left;
}

void Node::setRightChild(Node* _right){
	this->rightChildptr = _right;
}