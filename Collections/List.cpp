#pragma once

#include <string>
#include <iostream>
#include "./LinkedList.cpp"

template <typename T>
class LinkedList;

namespace Collections
{

  template <typename T>
  class List {
    private:
    T* arr;

    void upsize( size_t newLen, size_t oldLen ) {
      T* newArr = new T[newLen];
      for ( size_t i = 0; i < oldLen; i++ ) {
        newArr[i] = this->arr[i];
      }
      this->arr = newArr;
    }

    void downsize( size_t newLen ) {
      T* newArr = new T[newLen];
      for ( size_t i = 0; i < newLen; i++ ) {
        newArr[i] = this->arr[i];
      }
      this->arr = newArr;
    }

    public:

    size_t Count, Capacity, HalfCapacity;

    List(size_t startingCapacity=1) {
      this->Capacity = startingCapacity;
      this->HalfCapacity = this->Capacity;
      this->Count = 0;
      this->arr = new T[this->Capacity];
    }

    void push( T item ) {
      if ( this->Count+1 > this->Capacity ) {
        size_t newSize = this->Capacity*2;
        this->upsize( newSize, this->Capacity );
        this->HalfCapacity = this->Capacity;
        this->Capacity = newSize;
      }

      this->arr[this->Count] = item;
      this->Count++;
    }

    T at( size_t idx ) {
      if ( -1 < idx && idx < this->Count ) {
        throw ("index: "+std::to_string(idx)+" is out of bounds");
      }
      return this->arr[idx];
    }

    T pop() {
      if ( this->Count < 1 ) {
        throw ("Cannot pop an empty list");
      }

      T r = this->arr[this->Count-1];
      this->Count--;

      if ( this->Count <= this->HalfCapacity ) {
        this->downsize(this->HalfCapacity);
        size_t h = this->HalfCapacity;
        this->Capacity = this->HalfCapacity;
        this->HalfCapacity = (size_t)(h/2);
      }

      return r;

    }

    T shift() {
      if ( this->Count < 1 ) {
        throw ("Cannot shift an empty list");
      }

      T r = this->arr[0];

      for ( int i = 1; i < this->Count; i++) {
        this->arr[i-1] = this->arr[i];
      }

      this->arr[this->Count-1] = nullptr;
      this->Count--;

      if ( this->Count <= this->HalfCapacity ) {
        this->downsize(this->HalfCapacity);
        size_t h = this->HalfCapacity;
        this->Capacity = this->HalfCapacity;
        this->HalfCapacity = (size_t)(h/2);
      }

      return r;
    }

    void remove( int idx ) {
    }

    void remove( T item ) {
      // TODO: Remove a specific item
    }

    LinkedList<T> Where(T* (*func)(T));

    ~List() {
      this->arr = nullptr;
    }
  };

} // namespace Collections

