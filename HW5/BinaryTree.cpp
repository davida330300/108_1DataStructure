/**
 * @file BinaryTree.cpp
 * @author Shau-Shiun,Chu (b06501018@ntu.edu.tw)
 * @ID 				B06501018
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	    National Taiwan University
 * @version 0.1
 * @date 2019-12-25
 *
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "BinaryTree.h"
using namespace std;

template<typename K, typename V>
BinaryTree<K, V>::BinaryTree()
{
	root = nullptr;
	makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int BinaryTree<K, V>::size()
{
	return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool BinaryTree<K, V>::isEmpty()
{
	return size() == 0;
}

template<typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V>* entry, const K& key, BinaryTreeNode<K, V>* node)
{
	/*
		if the insert key is smaller than the value(including no value)
	*/
	if (key.compareTo(node->entry->getkey()) <= 0)
	{
		// there is no existing entry
		if (node->leftChild == NULL)
		{
			node->leftChild = new BinaryTreeNode<K, V>(entry, node);
		}
		// if the insert key is smaller than existing entry
		else
		{
			insertHelper(entry, key, node->leftChild);
		}
	}
	/*

	*/
	else
	{
		// larger, no existing
		if (node->rightChild == NULL)
		{
			node->rightChild = new BinaryTreeNode<K, V>(entry, node);
		}
		// larger, existing
		else
		{
			insertHelper(entry, key, node->rightChild);
		}
	}
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void BinaryTree<K, V>::insert(const K& key, const V& value)
{
	Entry<K, V>* entry = new Entry<K, V>(key, value);
	if (root == NULL)
	{
		root = new BinaryTreeNode<K, V>(entry);
	}
	else
	{
		insertHelper(entry, key, root);
	}
	tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return null.
 *
 *  Be sure this method returns null if node == null.
 **/
template<typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::findHelper(const K& key, BinaryTreeNode<K, V>* node)
{
	// Replace the following line with your solution.
	BinaryTreeNode<K, V> *current = node;
	while (current != NULL)
	{
		int compare = key.compareTo(current->entry->getkey());
		// larger
		if (compare > 0)
		{
			current = current->rightChild;
		}
		// smaller
		else if (compare < 0)
		{
			current = current->leftChild;
		}
		// exact
		else
		{
			return current;
		}
	}
	return NULL;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or null if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
Entry<K, V>* BinaryTree<K, V>::find(const K& key)
{
	BinaryTreeNode<K, V>* node = findHelper(key, root);
	if (node != NULL)
	{
		return node->entry;
	}
	else
	{
		return NULL;
	}
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void BinaryTree<K, V>::remove(const K& key)
{
	// Your solution here.
	remove(key, root);
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void BinaryTree<K, V>::makeEmpty()
{
	// Your solution here.
	if (root != NULL)
	{
		delete root;
		root = NULL;
	}
	tsize = 0;
}

/**
 *  Convert the tree into a string.
 **/
template<typename K, typename V>
std::string BinaryTree<K, V>::toString()
{
	if (root == NULL)
	{
		return "";
	}
	else
	{
		return root->toString();
	}
}

/**
   * Search the smallest key in node which is not smaller than the given key.
   * @param subroot : regard subroot as root to find in the subtree.
   * @param key : the givne key.
   * @return the node which store the smallest key bigger than @key
   */
template<typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::smallestKeyNotSmaller(const K& key, BinaryTreeNode<K, V> *subroot)
{
	BinaryTreeNode<K, V> *current = subroot;
	BinaryTreeNode<K, V> *target = subroot;

	while (current != nullptr)
	{
		int comp = key.compareTo(current->entry->getkey());
		if (comp > 0)
		{
			current = current->rightChild;
		}
		else if (comp < 0)
		{
			current = current->leftChild;
		}
		if (target->entry->getkey().compareTo(current->entry->getkey()) <= 0)
			target = current;
	}
	return target;
}

/**
   *  Remove an entry with the specified key (start from the subroot).
   *  If such an entry is found, remove it from the table.
   *  If several entries have the specified key, choose one arbitrarily, then
   *  remove it.
   *
   *  @param key the search key.
   *  @param subroot the node you started to search
   */
template<typename K, typename V>
void BinaryTree<K, V>::remove(const K& key, BinaryTreeNode<K, V> *subroot)
{
	// Your solution here.
	BinaryTreeNode<K, V> *beremoved = findHelper(key, subroot);
	// no tree
	if (beremoved == NULL)
	{
		return;
	}
	else if (beremoved == root)
	{
		if (beremoved->leftChild == NULL && beremoved->rightChild == NULL)//have no child
		{
			delete root;
			root = NULL;
		}

		else if (beremoved->leftChild && beremoved->rightChild) //have two child
		{
			goto remove_root;
		}		
		else //have one child
		{
			if (beremoved->rightChild != NULL)
			{
				root = root->rightChild;
			}
			else
			{
				root = root->leftChild;
			}
			delete beremoved;
		}
	}
	else
	{
		if (beremoved->leftChild == NULL && beremoved->rightChild == NULL)//have no child
		{
			BinaryTreeNode<K, V> *bparent = beremoved->parent;
			if (bparent->entry->getkey().compareTo(beremoved->entry->getkey()) > 0)//beremoved is left child
			{
				bparent->leftChild = NULL;
			}
			else//beremoved is right child
			{
				bparent->rightChild = NULL;
			}
			delete beremoved;
		}
		else if (beremoved->leftChild && beremoved->rightChild)// have two child
		{
			remove_root:
			BinaryTreeNode<K, V> *replace_node = beremoved->rightChild;
			while (replace_node->leftChild != nullptr)
			{
				replace_node = replace_node->leftChild;
			}
			delete beremoved->entry;
			beremoved->entry = new Entry<K, V>(replace_node->entry->getkey(), replace_node->entry->getvalue());
			remove(replace_node->entry->getkey(), replace_node); // tsize decrease an extra time
			tsize++;// correct the error
		}
		else//have one child
		{
			BinaryTreeNode<K, V> *bparent = beremoved->parent;
			if (bparent->entry->getkey().compareTo(beremoved->entry->getkey()) > 0)//beremoved is left child
			{
				if (beremoved->leftChild == NULL)
				{
					bparent->leftChild = beremoved->rightChild;
				}
				else
				{
					bparent->leftChild = beremoved->leftChild;
				}
			}
			else//beremoved is right child
			{
				if (beremoved->rightChild == NULL)
				{
					bparent->rightChild = beremoved->rightChild;
				}
				else
				{
					bparent->rightChild = beremoved->leftChild;
				}
			}
			delete beremoved;
		}

	}
	tsize--;
}