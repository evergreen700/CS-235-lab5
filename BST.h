#ifndef BST_H
#define BST_H

#include "Node.h"

using namespace std;

class BST{
public:
	BST();
	virtual ~BST();

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual Node * getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool addToNode(Node* localRoot, Node* newNode);

	virtual bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/

	bool findRemoveNode(Node* localRoot, int value);
	virtual bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear();

	void recursiveClear(Node* node);

protected:
	Node* root;
};

#endif
