/**
 * @file LockDListNode.h
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
#ifndef lockDListNode_h
#define lockDListNode_h

#include "DListNode.h"
template <typename T>
class LockDList;

template <typename T>
class LockDListNode : public DListNode<T>
{

public:
    friend class LockDList<T>;
    bool isLocked;

    LockDListNode(const T &i, DListNode<T> *p, DListNode<T> *n) : DListNode<T>::DListNode(i, p, n)
    {
        isLocked = false;
    }
};

#endif