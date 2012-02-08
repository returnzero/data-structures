/*
  A templated node class for derived use in multiple data structures.

  -- Josh Haycraft
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
   T _data;

public:
   Node(T data) : _data(data) { }

   // getter/setter
   T const& data() const { return _data; }
   void data(T const& value) { _data = value; }
};

#endif