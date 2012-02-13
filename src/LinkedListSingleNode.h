/*
  A templated node class for a singly linked list.

  -- Josh Haycraft
*/

#ifndef LINKED_LIST_SINGLE_NODE_H
#define LINKED_LIST_SINGLE_NODE_H

#include "Node.h"


template <typename T>
class LinkedListSingleNode : public Node<T>
{
public:
   LinkedListSingleNode(T _data) : Node<T>(_data) { }

   LinkedListSingleNode* next;
};

#endif