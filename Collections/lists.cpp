#include <string>

namespace Collections
{

  template <typename T>
  class List {
    private:
    T* arr;

    void resizeUp() {
    }

    void resizeDown() {
    }

    public:
    int Count, Capacity;
    int HalfCapacity;

    List(size_t startingCapacity=1) {
      this->Capacity = startingCapacity;
      this->HalfCapacity = this->Capacity;
      this->Count = 0;
      this->arr = new T[this->Capacity];
    }

    void push( T item ) {
      if ( this->Count+1 > this->Capacity ) {
        resizeUp();
      }

      this->arr[this->Count] = item;
      this->Count++;
    }

    T at( int idx ) {
      try {
        return this->arr[idx];
      } catch (std::string msg) {
        throw ("Index: "+std::to_string(idx)+" is out of bounds");
      }
    }

    T pop() {
      T h = this->arr[this->Count-1];

      this->arr[this->Count-1] = nullptr;
      this->Count--;

      if ( this->Count <= this->HalfCapacity ) {
        resizeDown();
      }

      return h;
    }

    T shift() {
      try {
        // Create a tmp holder for the first element
        T h = this->arr[0];

        // Move all elements 1 back in the array
        for ( int i = 1; i < this->Count; i++ ) {
          this->arr[i-1] = this->arr[i];
        }

        // Remove the dup of the last element
        // then decroment the Count var
        this->arr[this->Count-1] = nullptr;
        this->Count--;

        // Check if a resize is needed, then do it, if it is
        if ( this->Count <= this->HalfCapacity ) {
          resizeDown();
        }

        // Return the h variable
        return h;
      } catch (std::string msg) {
        throw ("List is empty, cannot shift an empty list");
      }
    }

    void remove( int idx ) {
      try {
        this.arr[idx] = nullptr;

        for ( int i = idx+1; i < this->Count; i++ ) {
          this->arr[i-1] = this->arr[i];
        }

        this->arr[this->Count-1] = nullptr;

        if ( this->Count <= this->Capacity ) {
          resizeDown();
        }

      } catch (std::string msg) {
        throw ("Index: "+std::to_string(idx)+" is out of bounds");
      }
    }

    void remove( T item ) {
      // TODO: Remove a specific item
    }

    ~List() {
      for ( T item : this->arr ) {
        item.~T();
      }
      free(this->arr);
    }

  };

} // namespace Collections

