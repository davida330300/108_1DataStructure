/**
 * @file LockDList.cpp
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
#include "LockDList.h"
#include <iostream>
using namespace std;

//add new function
template <typename T>
LockDList<T>::LockDList()
{
    LockDListNode<T> *dummy = NULL;
    dummy = newNode(0, NULL, NULL);
    this->size = 0;
    this->head = dummy;
    dummy->prev = dummy;
    dummy->next = dummy;
}

template <typename T> //uncompleted
void LockDList<T>::lockNode(DListNode<T> *node)
{
    LockDListNode<T> *Lnode = dynamic_cast<LockDListNode<T> *>(node);
    Lnode->isLocked = true;
    return;
}

//edit old function
template <typename T>
void LockDList<T>::remove(DListNode<T> *node)
{
    LockDListNode<T> *Lnode = dynamic_cast<LockDListNode<T> *>(node);
    if (Lnode->isLocked == true)
    {
        return;
    }
    else
    {
        DList<T>::remove(Lnode);
        return;
    }
}

template <typename T>
LockDListNode<T> *LockDList<T>::newNode(const T &item, DListNode<T> *prev, DListNode<T> *next)
{
    return new LockDListNode<T>(item, prev, next);
}
