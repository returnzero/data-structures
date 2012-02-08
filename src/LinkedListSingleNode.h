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
protected:
   LinkedListSingleNode* _next;

public:
   LinkedListSingleNode(T data) : Node<T>(data) { }

   // getter/setter
   LinkedListSingleNode* next() const { return _next; }
   void next(const LinkedListSingleNode* const value) { _next = value; }
};

#endif