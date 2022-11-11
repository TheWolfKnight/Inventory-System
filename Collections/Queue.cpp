
namespace Collections
{
  template <typename T>
  class Queue {
    private:
      T arr[];
      size_t length;

      T[] resize( T from[], size_t newLen ) {
        T to[] = new T[newLen];
        for ( int i = 0; i < newLen; i++ ) {
          to[i] = from[i];
        }
        return to;
      }

    public:
    Queue( T contents[], size_t len ) {
      this->arr = contents;
      this->length = len;
    }

    Queue( size_t size ) {
      this->arr = new T[size];
      this->length = size;
    }

    void rotate( int amt ) {
    }

    T pop() {
      T r = this->arr[this->length-1];
      this->arr = resize( this->arr, this->length-1 );
      this->length--;
      return r;
    }

    T shift() {
      T r = this->arr[this->length-1];
      this->arr = resize( this->arr, this->length-1 );
      this->length--;
      return r;
    }

  };
} // namespace Collections

