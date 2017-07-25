//queue withdynamic array implementation

#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::vector;


template <typename T>
class Queue {
  vector<T> data;
  size_t front, tail, size; //tail: index of next write, front: index of next read
  static const int resize_factor = 2;
public:
  Queue (size_t size) : data(size), front(0), tail(0), size(0){}
  
  size_t Size (void) {return size;}
  
  void Enqueue (const T& value) {
    if (size < data.capacity()) {
      vector[tail++] = value;
      tail %= data.capacity();
      size++;
    }
    else {
      tail = data.capacity();
      data.resize(data.capacity()*2);
      data.rotate(data.begin(), data.begin() + head, data.end());
      head = 0;
    }
  }

  T Dequeue (void) {
    if (size == 0)  throw std::length_error("Queue empty");
    T result = data[head++];
    head %= data.capacity();
    return result;
  }
};
