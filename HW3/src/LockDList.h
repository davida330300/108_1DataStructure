/**
 * @file LockDList.h
 * @author Shau-Shiun,Chu (b06501018@ntu.edu.tw)
 * @ID 				B06501018
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	    National Taiwan University
 * @version 0.1
 * @date 2019-10-25
 * 
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LockDList_H
#define LockDList_H

// #ifndef LOCKDLIST_H
// #define LOCKDLIST_H

#include "DList.h"
#include "LockDListNode.h"

template <typename T>
class LockDList : public DList<T>
{
public:
  LockDList();

  void lockNode(DListNode<T> *node);
  void remove(DListNode<T> *node);

  virtual LockDListNode<T> *newNode(const T &i, DListNode<T> *p, DListNode<T> *n);
};
#endif