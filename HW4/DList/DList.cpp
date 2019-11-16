/**
 * @file DList.cpp
 * @author Shau-Shiun,Chu (b06501018@ntu.edu.tw)
 * @ID 				B06501018
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	    National Taiwan University
 * @version 0.1
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
/*
 *  A DList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

/**
  Briefly explain the function of this class.

  DList.cpp
  version 1.0
*/
#include "DList.h"
#include <iostream>
using namespace std;

/* DList invariants:
 *  1)  head != null.
 *  2)  For any DListNode x in a DList, x.next != null.
 *  3)  For any DListNode x in a DList, x.prev != null.
 *  4)  For any DListNode x in a DList, if x.next == y, then y.prev == x.
 *  5)  For any DListNode x in a DList, if x.prev == y, then y.next == x.
 *  6)  size is the number of DListNodes, NOT COUNTING the sentinel,
 *      that can be accessed from the sentinel (head) by a sequence of
 *      "next" references.
 */

/**
 *  newNode() calls the DListNode constructor.  Use this class to allocate
 *  new DListNodes rather than calling the DListNode constructor directly.
 *  That way, only this method needs to be overridden if a subclass of DList
 *  wants to use a different kind of node.
 *  @param item the item to store in the node.
 *  @param prev the node previous to this node.
 *  @param next the node following this node.
 */
template <typename T>
DListNode<T> *DList<T>::newNode(const T &item, DListNode<T> *prev, DListNode<T> *next)
{
	return new DListNode<T>(item, prev, next);
}

/**
 *  DList() constructor for an empty DList.
 */
template <typename T>
DList<T>::DList() // complete
{
	//  Your solution here.
	/*
	create dummy to store head and tail info
		initialize:
			1.	should not store any item, item = NULL, item is type <T>
			2.	only one node, so the prev and next all point to dummy itself
			3.	modify protect memeber data, size = 0, head = dummy

			notice: the "head" memeber always point to dummy! 
	*/
	DListNode<T> *dummy = NULL;
	dummy = newNode(NULL, NULL, NULL);
	dummy->prev = dummy;
	dummy->next = dummy;

	size = 0;
	head = dummy;
}

/**
 *  isEmpty() returns true if this DList is empty, false otherwise.
 *  @return true if this DList is empty, false otherwise. 
 *  Performance:  runs in O(1) time.
 */
template <typename T>
bool DList<T>::isEmpty()
{
	return size == 0;
}

/** 
 *  length() returns the length of this DList. 
 *  @return the length of this DList.
 *  Performance:  runs in O(1) time.
 */
template <typename T>
int DList<T>::length()
{
	return size;
}

/**
 *  insertFront() inserts an item at the front of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template <typename T>
void DList<T>::insertFront(const T &item)
{
	// Your solution here.
	/**
	 * @brief insertFront() inserts an item at the front of this DList.
	 * 
	 * notice: the "head" memeber always point to dummy! 
	 * 	1.	remeber the "originHead"(head->next), it doesn't matter where the "originTail" is
	 *	2.	cut originHead->prev
	 * 	3.	create and initialize a new node called "addNode", item = item, item is type <T> (not yet connect to original linked list!)
	 * 	4.	link back originHead->prev to addNode, link back head->next to addNode
	 * 	5.	modify protected memeber
	 * 
	 * 
	 */

	DListNode<T> *originHead = head->next;
	originHead->prev = NULL;
	head->next = NULL;
	DListNode<T> *addNode = newNode(item, head, originHead);
	originHead->prev = addNode;
	head->next = addNode;

	size++;

	return;
}

/**
 *  insertBack() inserts an item at the back of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template <typename T>
void DList<T>::insertBack(const T &item)
{
	// Your solution here.
	/**
	 * @brief insertBack() inserts an item at the back of this DList.
	 * 
	 * notice: the "head" memeber always point to dummy! 
	 * 	1.	remeber the "originTail"(head->prev), it doesn't matter where the "originHead" is
	 *	2.	cut originTail->next
	 *	3.	create and initialize a new node called "newnode", item = item, item is type <T>
	 *	4.	link back originTail->next to newnode
	 *	5.	modify protected memeber
	 *
	 */

	DListNode<T> *originTail = head->prev;
	originTail->next = NULL;
	head->prev = NULL;
	DListNode<T> *addNode = newNode(item, originTail, head);
	originTail->next = addNode;
	head->prev = addNode;

	size++;
}

/**
 *  front() returns the node at the front of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the front of this DList.
 *  Performance:  runs in O(1) time.
 */
template <typename T>
DListNode<T> *DList<T>::front()
{

	// Your solution here.
	/**
	 * @brief front() returns the node at the front of this DList.  If the DList is empty, return null.
	 * 
	 * notoce: the "head" always point to dummy
	 * 	1.	head(dummy)->next is the real head
	 * 
	 */
	if (head->next->item != NULL)
	{
		return head->next;
	}
	else
	{
		return NULL;
	}
}

/**
 *  back() returns the node at the back of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the back of this DList.
 *  Performance:  runs in O(1) time.
 */
template <typename T>
DListNode<T> *DList<T>::back()
{
	// Your solution here.
	/**
	 * @brief back() returns the node at the back of this DList.  If the DList is empty, return null.
	 * 
	 * notice: the "head" always point to dummy
	 * 	1.	head(dummy)->prev is real tail
	 * 
	 */
	if (head->prev->item != NULL)
	{
		return head->prev;
	}
	else
	{
		return NULL;
	}
}

/**
 *  next() returns the node following "node" in this DList.  If "node" is
 *  null, or "node" is the last node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose successor is sought.
 *  @return the node following "node".
 *  Performance:  runs in O(1) time.
 */
template <typename T>
DListNode<T> *DList<T>::next(DListNode<T> *node)
{
	// Your solution here.
	if (node == NULL || head->prev == node)
	{
		return NULL;
	}
	else
	{
		return node->next;
	}
}

/**
 *  prev() returns the node prior to "node" in this DList.  If "node" is
 *  null, or "node" is the first node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose predecessor is sought.
 *  @return the node prior to "node".
 *  Performance:  runs in O(1) time.
 */
template <typename T>
DListNode<T> *DList<T>::prev(DListNode<T> *node)
{
	// Your solution here.
	if (node == NULL || head->next == node)
	{
		return NULL;
	}
	else
	{
		return node->prev;
	}
}

/**
 *  insertAfter() inserts an item in this DList immediately following "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item after.
 *  Performance:  runs in O(1) time.
 */
template <typename T>
void DList<T>::insertAfter(const T &item, DListNode<T> *node)
{
	// Your solution here.
	if (node == NULL || head->next == node)
	{
		return;
	}
	else
	{
		DListNode<T> *temp = node->next;
		DListNode<T> *addNode = newNode(item, node, temp);
		node->next = addNode;
		temp->prev = addNode;
		size += 1;
		return;
	}
}

/**
 *  insertBefore() inserts an item in this DList immediately before "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item before.
 *  Performance:  runs in O(1) time.
 */

template <typename T>
void DList<T>::insertBefore(const T &item, DListNode<T> *node)
{
	// Your solution here.
	if (node == NULL)
	{
		return;
	}
	else
	{
		DListNode<T> *temp = node->prev;
		DListNode<T> *addNode = newNode(item, temp, node);
		node->prev = addNode;
		temp->next = addNode;
		size += 1;
		return;
	}
}

/**
 *  remove() removes "node" from this DList.  If "node" is null, do nothing.
 *  Performance:  runs in O(1) time.
 */
template <typename T>
void DList<T>::remove(DListNode<T> *node)
{
	// Your solution here.
	if (node == NULL)
	{
		return;
	}
	else
	{

		DListNode<T> *deletePrev = node->prev;
		DListNode<T> *deleteNext = node->next;
		node->next = NULL;
		node->prev = NULL;

		delete node;

		deletePrev->next = deleteNext;
		deleteNext->prev = deletePrev;

		size--;
	}
	return;
}

/**
 *  toString() prints a string representation of this DList.
 *
 *  DO NOT CHANGE THIS METHOD.
 *
 *  Performance:  runs in O(n) time, where n is the length of the list.
 */
template <typename T>
void DList<T>::toString()
{
	cout << "  ListNode     Item   " << endl;
	cout << "----------------------" << endl;
	DListNode<T> *current = head->next;
	int i = 1;
	while (current != head)
	{
		cout << i++ << "        " << current->item << endl;
		current = current->next;
	}
}
