/**
 *  A DList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

 /**
   Briefly explain the function of this class.

   @author 			shau shiun chu
   @ID 				B06501018
   @Department 		Engineering Science and Ocean Engineering
   @Affiliation 	    National Taiwan University

   DList.cpp
   version 2.0
 */
#include <iostream>
#include "DList.h"
using namespace std;

/** DList invariants:
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
template<typename T>
DListNode<T>* DList<T>::newNode(const T& item,
	DListNode<T>* prev, DListNode<T>* next) {
	return new DListNode<T>(item, prev, next);
}

/**
 *  DList() constructor for an empty DList.
 */
template<typename T>
DList<T>::DList() {
	//  Your solution here.
	T nothing;
	DListNode<T> *sentinel = nullptr;
	sentinel = newNode(nothing, nullptr, nullptr);
	size = 0;
	head = sentinel;
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
}

/**
 *  isEmpty() returns true if this DList is empty, false otherwise.
 *  @return true if this DList is empty, false otherwise.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
bool DList<T>::isEmpty() {
	return size == 0;
}

/**
 *  length() returns the length of this DList.
 *  @return the length of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
int DList<T>::length() {
	return size;
}

/**
 *  insertFront() inserts an item at the front of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertFront(const T& item) {
	// Your solution here.
	DListNode<T> *original_first = head->next;
	head->next = newNode(item, head, original_first);
	original_first->prev = head->next;
	size += 1;
}

/**
 *  insertBack() inserts an item at the back of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertBack(const T& item) {
	// Your solution here.
	DListNode<T> *original_last = head->prev;
	head->prev = newNode(item, original_last, head);
	original_last->next = head->prev;
	size += 1;
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
template<typename T>
DListNode<T>* DList<T>::front() {
	// Your solution here.
	if (isEmpty())
	{
		return nullptr;
	}
	else
	{
		return head->next;
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
template<typename T>
DListNode<T>* DList<T>::back() {
	// Your solution here.
	if (isEmpty())
	{
		return nullptr;
	}
	else
	{
		return head->prev;
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
template<typename T>
DListNode<T>* DList<T>::next(DListNode<T>* node) {
	// Your solution here.
	if (node == nullptr || head->prev == node)
	{
		return nullptr;
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
template<typename T>
DListNode<T>* DList<T>::prev(DListNode<T>* node) {
	// Your solution here.
	if (node == nullptr || head->next == node)
	{
		return nullptr;
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
template<typename T>//unsure
void DList<T>::insertAfter(const T& item, DListNode<T>* node) {
	// Your solution here.
	if (node == nullptr)
	{
		return;
	}
	DListNode<T> *temp = node->next;
	node->next = newNode(item, node, temp);
	temp->prev = node->next;
	size += 1;
	return;
}

/**
 *  insertBefore() inserts an item in this DList immediately before "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item before.
 *  Performance:  runs in O(1) time.
 */
template<typename T>//unsure
void DList<T>::insertBefore(const T& item, DListNode<T>* node) {
	// Your solution here.
	if (node == nullptr)
	{
		return;
	}
	DListNode<T> *temp = node->prev;
	node->prev = newNode(item, temp, node);
	temp->next = node->prev;
	size += 1;
	return;
}

/**
 *  remove() removes "node" from this DList.  If "node" is null, do nothing.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::remove(DListNode<T>* node) {
	// Your solution here.
	if (node == nullptr)
	{
		return;
	}
	DListNode<T> *dprev = node->prev, *dnext = node->next;
	delete node;
	dprev->next = dnext;
	dnext->prev = dprev;
	size -= 1;
	return;
}

/**
 *  toString() prints a string representation of this DList.
 *
 *  DO NOT CHANGE THIS METHOD.
 *
 *  Performance:  runs in O(n) time, where n is the length of the list.
 */
template<typename T>
void DList<T>::toString() {
	cout << "  ListNode     Item   " << endl;
	cout << "----------------------" << endl;
	DListNode < T > *current = head->next;
	int i = 1;
	while (current != head) {
		cout << i++ << "        " << current->item << endl;
		current = current->next;
	}
}

/**
 *  getItem() returns the item in the given node.
 */
template<typename T>
T DList<T>::getItem(DListNode<T> *node)
{
	return node->item;
}

