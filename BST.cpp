#include "Node.h"
#include "BST.h"

using namespace std;

BST::BST() {
	root = NULL;
}
BST:: ~BST() {
	clear();
}

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
Node * BST::getRootNode() const{
	return root;
}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/

bool BST::addToNode(Node* localRoot, Node* newNode){
	if(newNode->getData() < localRoot->getData()){
		if(localRoot->getLeftChild() == NULL){
			localRoot->setLeftChild(newNode);
			return true;
		}else{
			return(addToNode(localRoot->getLeftChild(), newNode));
		}
	}else if(newNode->getData() > localRoot->getData()){
		if(localRoot->getRightChild() == NULL){
			localRoot->setRightChild(newNode);
			return true;
		}else{
			return(addToNode(localRoot->getRightChild(), newNode));
		}
	}else if(newNode->getData() == localRoot->getData()){
		return false;
	}
	return false;
}


bool BST::add(int data){
	Node* newNodeptr = new Node();
	newNodeptr->setData(data);
	if(root == NULL){
		root = newNodeptr;
		return true;
	}else if(addToNode(root, newNodeptr)){
		return true;
	}else{
		delete newNodeptr;
		return false;
	}
}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
Node* replaceNode(Node* deadNode){
	//returns replacement node
	if(deadNode->getLeftChild() == NULL){
		//replaces node with its right child if it has no left child
		Node* replacement = deadNode->getRightChild();
		return replacement;
	}else if(deadNode->getRightChild() == NULL){
		//replaces node with its left child if it has no right child
		Node* replacement = deadNode->getLeftChild();
		return replacement;
	}else{
		//if the replaced node has two children:
		Node* replacementParent = deadNode->getLeftChild();

		//if the replaced node's left child has only a left child, replace with the left child
		if(replacementParent->getRightChild() == NULL){
			replacementParent->setRightChild(deadNode->getRightChild());
			return replacementParent;
		}
		
		//if the replaced node's left child has a right child, find it's right-most descendant and replace with that
		while(replacementParent->getRightChild()->getRightChild() != NULL){
			replacementParent = replacementParent->getRightChild();
		}
		//replace the rightmost child with its left child
		Node* replacement = replacementParent->getRightChild();
		replacementParent->setRightChild(replacement->getLeftChild());
		replacement->setLeftChild(deadNode->getLeftChild());
		replacement->setRightChild(deadNode->getRightChild());
		return replacement;
	}
}

bool BST::findRemoveNode(Node* localRoot, int value){
	if(value < localRoot->getData() && localRoot->getLeftChild() != NULL){
		if(value == localRoot->getLeftChild()->getData()){
			//we found the node, start deleting it!
			Node* toDelete = localRoot->getLeftChild();
			localRoot->setLeftChild(replaceNode(toDelete));
			delete toDelete;
			return true;
		}else{
			return findRemoveNode(localRoot->getLeftChild(), value);
		}
	}else if(value > localRoot->getData() && localRoot->getRightChild() != NULL){
		if(value == localRoot->getRightChild()->getData()){
			//we found the node, start deleting it!
			Node* toDelete = localRoot->getRightChild();
			localRoot->setRightChild(replaceNode(toDelete));
			delete toDelete;
			return true;
		}else{
			return findRemoveNode(localRoot->getRightChild(), value);
		}
	}else{
		return false;
	}
}

bool BST::remove(int data){
	if(root->getData() == data){
		Node* toDelete = root;
		root = replaceNode(root);
		delete toDelete;
		return true;
	}
	return findRemoveNode(root, data);
}

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
void BST::recursiveClear(Node* node){
	if(node == NULL){
		return;
	}else{
		recursiveClear(node->getLeftChild());
		recursiveClear(node->getRightChild());
		delete node;
		return;
	}
}

void BST::clear(){
	recursiveClear(root);
	root = NULL;
	return;
}
