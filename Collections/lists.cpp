
namespace Collections
{

  template <typename T>
  class List {
    private:
    T[] arr;

    void resize() {
    }

    public:
    int Count, Capacity;

    List() {
      Capacity = 1;
      Count = 0;
      arr = new T[Capacity];
    }

    void add( T item ) {
      // TODO: add item, and resize list
    }

    T at( int idx ) {
      try {
        return arr[idx];
      } catch () {
        throw ("Index: "+idx+" is out of bounds");
      }
    }

    T pop() {
      // TODO: pop the list
    }

    T shift() {
      // TODO: shift the list
    }

    void remove( int idx ) {
      // TODO: Remove a specific index
    }

    void remove( T item ) {
      // TODO: Remove a specific item
    }

  };

} // namespace Collections

