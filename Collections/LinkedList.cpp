#pragma once

#include <stdarg.h>
#include "./List.cpp"

template <typename T>
class List;

namespace Collections
{

  template <typename T>
  class LinkedList {
    private:
    public:
    T val;
    LinkedList* next;
    LinkedList() {next=nullptr;}
    LinkedList(T in) {val=in; next=nullptr;}
    LinkedList(T in, LinkedList* nxt) {val=in; next=nxt;}

    int Count(bool (*func)(...));
    Collections::List<T> ToList();

  };

} // namespace Collections

