/*
  A templated node class for derived use in multiple data structures.

  -- Josh Haycraft
*/

#ifndef NODE_H
#define NODE_H

#include <tr1/memory>

template <typename T>
class Node
{
   
public:
   
   Node(T _data) : data(new T(_data)) {  }

   std::tr1::shared_ptr<T> data;
};

#endif