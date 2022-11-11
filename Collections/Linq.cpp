
#include <stdarg.h>
#include "./List.cpp"
#include "./LinkedList.cpp"

namespace Collections {

  template <typename T>
  Collections::LinkedList<T> Collections::List<T>::Where(T* (*func)(T)) {
    LinkedList<T>* head = new LinkedList(this->arr[0]);
    LinkedList<T>* tail = head;

    for ( int i = 1; i < this->Count; i++ ) {
      tail->next = new LinkedList(this->arr[i]);
      tail = tail->next;
    }
    return &head;
  }

  template <typename T>
  int Collections::LinkedList<T>::Count(bool (*func)(...)) {
    int r = 0;
    LinkedList<T>* head = this;

    while ( head != nullptr ) {
      if ( func(head->val) ) {
        r++;
      }
      head = head->next;
    }

    return r;
  }

}
