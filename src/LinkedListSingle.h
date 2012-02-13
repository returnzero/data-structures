/*
  A templated singly linked list.

  -- Josh Haycraft
*/

#ifndef LINKED_LIST_SINGLE_H
#define LINKED_LIST_SINGLE_H

#include "LinkedListSingleNode.h"

template<typename T>
class LinkedListSingle
{
   protected:
      LinkedListSingleNode<T>* head;

   public:
      LinkedListSingle() { }

      virtual ~LinkedListSingle()
      {
          LinkedListSingleNode<T>* current = head;
          while(current)
          {
             LinkedListSingleNode<T>* next = current->next;
             delete current;
             current = next;
          }
          head = 0;
      }

      LinkedListSingleNode<T>* FindFirst(const T);
      LinkedListSingleNode<T>* GetAt(const int);

      LinkedListSingleNode<T>* Add(const T);
      LinkedListSingleNode<T>* InsertAt(const T, const int);
      
      bool Remove(const T);
      bool Remove(LinkedListSingleNode<T>*);
      bool RemoveAt(const int);

      void PrintValues();
};

template<typename T>
LinkedListSingleNode<T>* LinkedListSingle<T>::Add(const T nodeAdd)
{

   LinkedListSingleNode<T>* add = new LinkedListSingleNode<T>(nodeAdd);
   
   if (!head)
   {
      head = add;
      return head;
   } 

   LinkedListSingleNode<T>* current = head;
   while (current->next)
      current = current->next;

   current->next = add;
   return add;   
}

template<typename T>
LinkedListSingleNode<T>* LinkedListSingle<T>::InsertAt(const T nodeInsert, const int index)
{
   if (index < 0)
      return NULL;
   else if (index == 0)
   {
      LinkedListSingleNode<T>* current = head;
      head = new LinkedListSingleNode<T>(nodeInsert);
      head->next = current;
      return head;
   }

   LinkedListSingleNode<T>* prev = GetAt(index-1);
   if (prev) {
      LinkedListSingleNode<T>* add = new LinkedListSingleNode<T>(nodeInsert);
      add->next = prev->next;
      prev->next = add;
      return add;
   }

   return NULL;
}

template<typename T>
bool LinkedListSingle<T>::Remove(const T item)
{
   if (!head)
      return false;

   if (*(head->data) == item)
   {
      LinkedListSingleNode<T>* current = head;
      head = head->next;
      delete current;
      return true;
   }

   LinkedListSingleNode<T>* current = head;
   while (current->next)
   {
      if (current->next->data == item)
      {
         LinkedListSingleNode<T>* remove = current->next;
         current->next = remove->next;
         delete remove;
         return true;
      }

      current = current->next;
   }

   return false;
}

template <typename T>
bool LinkedListSingle<T>::Remove(LinkedListSingleNode<T>* ptr_item)
{
   if (!head)
      return false;

   if (head == ptr_item)
   {
      head = head->next;
      delete ptr_item;
      return true;
   }

   LinkedListSingleNode<T>* current = head;
   while (current->next)
   {
      if (*(current->next->data) == *(ptr_item->data))
      {
         LinkedListSingleNode<T>* remove = current->next;
         current->next = remove->next;
         delete remove;
         return true;
      }
      current = current->next;
   }

   return false;  
}

template <typename T>
bool LinkedListSingle<T>::RemoveAt(const int index)
{
   if (!head)
      return false;

   if (index == 0)
   {
      LinkedListSingleNode<T>* current = head;
      head = head->next;
      delete current;
      return true;
   }

   LinkedListSingleNode<T>* prev = GetAt(index-1);
   if (prev)
   {
      LinkedListSingleNode<T>* current = prev->next;
      if (current)
      {
         prev->next = current->next;
         delete current;
         return true;
      }
      else
         return false;
   }

   return false;
}

template <typename T>
void LinkedListSingle<T>::PrintValues()
{
   LinkedListSingleNode<T>* current = head;
   while (current)
   {
      std::cout << *(current->data) << std::endl;
      current = current->next;
   }
}

template <typename T>
LinkedListSingleNode<T>* LinkedListSingle<T>::FindFirst(const T item)
{

   LinkedListSingleNode<T>* current = head;
   while (current)
   {
      if (*(current->data) == item)
         return current;

      current = current->next;
   }

   return NULL;
}

template <typename T>
LinkedListSingleNode<T>* LinkedListSingle<T>::GetAt(const int index)
{
   int i = 0;
   LinkedListSingleNode<T>* current = head;
   
   while (current && i < index)
   {
      current = current->next;
      i++;
   }

   if (i == index)
      return current;
   else
      return NULL;
}
#endif