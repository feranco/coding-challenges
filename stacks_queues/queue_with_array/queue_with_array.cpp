//queue withdynamic array implementation

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

using std::rotate;
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
    if (size == data.size()) {
      //it's important first rotate and only then resize,
      //otherwise new adde elements will be between head and tail
      rotate(data.begin(), data.begin() + front, data.end());
      data.resize(data.size()*resize_factor);
      front = 0;
      tail = size;
    }
    data[tail++] = value;
    tail %= data.capacity();
    ++size;
  }

  T Dequeue (void) {
    if (size == 0)  throw std::length_error("Queue empty");
    T result = data[front++];
    front %= data.size();
    --size;
    return result;
  }
};


int main (void) {
  Queue<int> q(3);
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  q.Enqueue(4);
  cout << q.Dequeue() << " ";
  cout << q.Dequeue() << " ";
  cout << q.Dequeue() << " ";
  cout << q.Dequeue() << " ";
  cout << q.Dequeue() << " ";
}
