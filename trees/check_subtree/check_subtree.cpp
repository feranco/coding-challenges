// algorithm to check if a tree t2 is a subtree of a bigger tree t1
// i.e. find a node n in t1 so that cutting t1 above n t1 become 
// equal to t2

// assumption: 
// 1) trees are binary trees
// 2) each node has an integer value with ptr to the left and right children
#include "../common/utility.h"

//check if t1 and t2 are equal
bool checkMatch (Link t1, Link t2) {

  if (!t1 && !t2) return true;  //input trees terminates togheter

  //if (!t1 || !t2) is better
  if ((!t1 && t2) || (t1 && !t2)) return false; //only one input tree terminates

  //if (t1->value != t2->value) return false;
  //else return (checkMatch(t1->left, t2->left) || checkMatch(t1->right, t2->right));
  //is better
  if (t1->value == t2->value && checkMatch(t1->left, t2->left))
    return checkMatch(t1->right, t2->right);
  else return false;
}

//preorder traverseal t1 of t1 comparing each node to the root of t2
bool findSubTree (Link t1, Link t2) {

  if (!t1) return false;  //a null tree can't have a not null subtree

  if (t1->value == t2->value && checkMatch(t1, t2) == true) return true;

  //if (findSubTree(t1->left, t2) || findSubTree(t1->right, t2))
  //is better
  if (findSubTree(t1->left, t2) == true) return true;
  else return findSubTree(t1->right, t2);
  
}

//check if t2 is a subtree of t1
bool isSubTree (Link t1, Link t2) {

  if (!t2) return true;  //a null tree is always a subtree
  else return findSubTree(t1, t2);

}

int main (void) {

  int  t1_val[] = {9,4,3,-1,-1,2,-1,-1,5,7,8,-1,-1,9,-1,-1,2-1,-1};
  Link t1 = 0;
  buildBtree(t1, t1_val);
  dump(cout, t1, 0);
  cout << "*****";
  int  t2_val[] = {7,8,-1,-1,9,-1,-1};
  Link t2 = 0;
  buildBtree(t2, t2_val);
  dump(cout, t2, 0);

  cout << isSubTree(t1, t2);

}
