#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using std::list;
using std::unordered_map;
using std::pair;

template <typename Key, typename T>
class CacheLRU {
  int capacity, n;
  //map each key to its position in the lru and its data
  unordered_map <Key, pair<typename list<Key>::iterator, T>> entries;
  //sort the keys from most recently used to lru
  list<Key> lru;
  typename list<Key>::iterator moveToHead (typename list<Key>::iterator it);
    
public:
  CacheLRU (int capacity = 10) {this->capacity = capacity; n = 0;}
  bool lookup (Key key, T data);
  void insert (Key key, T data);
  void erase  (Key key);
};
    
// move a key in the most recently used position and return the new iterator
template <typename Key, typename T>
typename list<Key>::iterator CacheLRU<Key,T>::moveToHead (typename list<Key>::iterator it) {
  Key key = *it;
  lru.erase(it);
  lru.push_front(key);
  return lru.begin();
}
    
//if the input key is already in the cache
//update its data and the lru list and return true
//otherwise return false
template <typename Key, typename T>
bool CacheLRU<Key,T>::lookup (Key key, T data) {
  auto got = entries.find(key);
  if (got == entries.end()) return false;
  got->second = data;
  got->first = moveToHead(got->first);
  return true;
}
    
//if the input key is already in the cache
//update the lru list CHECK
template <typename Key, typename T>
void CacheLRU<Key,T>::insert (Key key, T data) {
  auto got = entries.find(key);
  if (got != entries.end()) got->first = moveToHead(got->first);
  else {
    auto it = lru.push_front();
    entries.insert({key,{it, data}});
    if (++n > capacity) {
      auto evicted = lru.back();
      lru.pop_back();
      entries.erase(evicted);
    }
  }
}
    
//if the input key is already in the cache
//update the lru list CHECK
template <typename Key, typename T>
void CacheLRU<Key,T>::erase (Key key) {
  auto got = entries.find(key);
  if (got != entries.end()) {
    lru.erase(got->first);
    entries.erase(key);
    --n;
  }
}

int main(void) {
  CacheLRU<int,int> isb(3);
}
