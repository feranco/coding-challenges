#include <iostream>
#include <vector>

struct btNode {
  int value;
  btNode *left, *right;
};

using btNode* Link;

void printPath (vector<int>& path, int start, int end) {

}

void findPath (Link v, vector<int>& path, int target) {
  if (!v) return;
  path.push_back(v->value);
  int i, sum;
  for (i = path.size(), sum = 0; i > 0; --i) {
    sum += path[i];
    if (sum == target) printPath(path, i, path.size()); 
  }
  findPath(v->left, path, target);
  findPath(v->right, path, target);
  path.pop_back();
}
