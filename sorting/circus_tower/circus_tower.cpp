// algorithm to compute the maximum number of people in a circus tower

// assumption: 
// 1) each person is specified by its height and weight
// 2) a person can be above another person if both its height and weight are lower than the person below

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::sort;
using std::vector;

struct Acrobat {
  int height;
  int weight;
  Acrobat(int height, int weight): height(height), weight(weight){}
};

bool compareByHeight (const Acrobat& lhs, const Acrobat& rhs) {
  return lhs.height > rhs.height;
}

bool compareByWeight (const Acrobat& lhs, const Acrobat& rhs) {
  return lhs.weight < rhs.weight;
}

struct Result {
  vector<int> size;
  vector<int> idx;
  Result (int n): size(n, 1), idx(n, -1) {for (int i = 0; i < n; ++i) idx[i] = i; }
};

Result buildMaxTower (const vector<Acrobat>& acrobats) {
  Result res(static_cast<int>(acrobats.size()));
  for (int i = 1; i != acrobats.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      //size i = 1 + max{size j}
      //idx i = idx(max(size j))
      if(compareByWeight(acrobats[i], acrobats[j])) {
	if ((res.size[j]+1) > res.size[i]) {
	  res.size[i] = res.size[j]+1;
	  res.idx[i] = j;
	}
      }
    }
  }
  return res;
}

void maxAcrobatsInTower (vector<Acrobat>& acrobats) {
    
  sort(acrobats.begin(), acrobats.end(), compareByHeight);
  Result res = buildMaxTower(acrobats);
  auto max_acrobats = max_element(res.size.begin(), res.size.end());
  int top_acrobat = static_cast<int>(distance(res.size.begin(), max_acrobats));
  std::cout << "max acrobats " << *max_acrobats << std::endl;
  while (res.idx[top_acrobat] != top_acrobat) {
    std::cout << acrobats[top_acrobat].height << " ";
    top_acrobat = res.idx[top_acrobat];
  }
  std::cout << acrobats[top_acrobat].height;
}

int main (void) {
  vector<Acrobat> circus_people;
  circus_people.emplace_back(65,100);
  circus_people.emplace_back(70,150);
  circus_people.emplace_back(56,90);
  circus_people.emplace_back(75,190);
  circus_people.emplace_back(60,95);
  circus_people.emplace_back(68,110);
  maxAcrobatsInTower(circus_people);
  
}

#if 0
//force brute solution: build all valid towers and find the one with more acrobats
//time O(2^n) space O(n)
bool canBeAbove (const acrobat& above, const acrobat& below) {
  if (above.height < below.height && above.weight < below.weight) return true;
  return false;
}
static int cnt = 0;
vector<acrobat> buildMaxTower (const vector<acrobat>& people, vector<acrobat> tower) {
  vector<acrobat> max_tower, current;
  int max_people = 0;
  
  for (auto p : people) {
    cnt++;
    if (tower.size() == 0 || canBeAbove(p, tower.back())) {	
      tower.push_back(p);
      current = buildMaxTower(people, tower);
      if (current.size() > max_people) {	  
	max_tower = current;
	max_people = current.size();
	//std::cout << max_people << std::endl;
	//for (const auto& p : max_tower) std::cout << p.height << " ";
	//std::cout << std::endl;
      }
      tower.pop_back();
    }    
  }
  return max_tower.size() == 0 ? tower : max_tower;
}

int maxPeopleInTower (const vector<acrobat>& people) {
  vector<acrobat> max_tower;
  max_tower = buildMaxTower(people, max_tower);
  std::cout << "cnt " << cnt << std::endl;
  for (const auto& p : max_tower) std::cout << p.height << " ";
  std::cout << std::endl;
  return max_tower.size();
}
#endif
