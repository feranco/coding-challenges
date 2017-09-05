//algorithm detecting a cycle in a directed graph

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

using namespace std;

bool diffByOne (const string& s, const string& t) {
  int diff = 0;
  for (int i = 0; i < s.size() && diff <=1; ++i) {
    if (s[i] != t[i]) ++diff;
  }
  return (diff == 1) ? true : false;
}

int hasProductionSequence(const vector<string>& dictionary, const string& s, const string& t) {
	
  unordered_set<string> visited;
  unordered_map<string,string> parent;
  queue<string> bfs_queue;
  bfs_queue.emplace(s);
        
  while(!bfs_queue.empty()) {
    const string& current_word = bfs_queue.front();
    bfs_queue.pop();
    if (current_word == t) break;
/*
    any_of(begin(dictionary), end(dictionary), [&current_word](const string& word) {
	if (diffByOne(current_word, word) && visited.find(word) == visited.end()) {
	  parent[word] = current_word;
	  visited.emplace(word);
	  bfs_queue.emplace(word);
	}
      });
  */   
    for (const string& word : dictionary) {
      if (diffByOne(current_word, word) && visited.find(word) == visited.end()) {
	parent[word] = current_word;
	visited.emplace(word);
	bfs_queue.emplace(word);
      }
    }
   
  }

 
  if (parent.find(t) != parent.end()) {
    string& it = parent.find(t)->second;
    int length = 1;
    while (it != s) {
      cout << it;
      it = parent.at(it);
      ++length;
    }
    return length;
  }
  return -1;	
}

    
int main(void) {
  vector<string> dictionary{"bat","cot","dog","dag","dot","cat"};
  cout << hasProductionSequence(dictionary, "cat", "dog");
}
