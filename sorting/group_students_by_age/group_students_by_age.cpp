//algorithm to group a list of students by age
//1) counting sort implemented with two hash tables: 
//   one to store the frequency of each age and one to store their offset
//   in the output array. O(n) time O(d) space d = number of different ages
//2) hash table mapping ages to students. O(n) time O(n) space; not good for large structures

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Student {
  int age;
  string name;
public:
  Student(string name, int age) {
    this->age = age;
    this->name = name;
  }
  int getAge(void) const { return age; }
};

void groupByAge(vector<Student>* students_ptr) {
  vector<Student>& students = *students_ptr;

  unordered_map<int, int> age_frequency;
  for (const auto& student : students) ++age_frequency[student.getAge()];

  unordered_map<int, int> age_offset;
  int offset = 0;
  for (const auto& frequency : age_frequency) {
    age_offset.insert({ frequency.first,offset });
    offset += frequency.second;
  }

  int idx = 0;

  while (!age_offset.empty()) {
    auto to = age_offset.find(students[idx].getAge());
    if (idx < to->second) swap(students[to->second], students[idx]);
    else if (idx == to->second) ++idx;

    --age_frequency[to->first];
    if (age_frequency[to->first] == 0) age_offset.erase(to->first);
    else to->second++;

  }
#if 0
  while (!age_offset.empty()) {
    // from is the position where the first element of age_offset map should be placed
    // the idea is to put the element in from into its right position (to) until from 
    // contain the expected element; 
    auto got = age_offset.begin();
    auto to = age_offset.find(students[got->second].getAge());
    swap(students[got->second], students[to->second]);
    --age_frequency[to->first];
    if (age_frequency[to->first] == 0) age_offset.erase(to);
    else to->second++;	
  }
#endif
}

void groupByAge2(vector<Student>* students_ptr) {
  vector<Student>& students = *students_ptr;

  unordered_multimap<int, Student> age_to_students;
  for (const auto& student : students) age_to_students.insert({student.getAge(),student});
  int idx = 0;
  while (!age_to_students.empty()) {
    auto current_age = age_to_students.begin();
    auto range = age_to_students.equal_range(current_age->first);
    for (auto it = range.first; it != range.second; ++it) {
      students[idx++] = it->second;
    }
    age_to_students.erase(current_age->first);
  }
}

int main(void) {
  vector<Student> students = { { "Pippo",14 },{ "Pluto",12 },{ "Topolino",11 },
			       { "Luca",13 },{ "Tim",12 },{ "Bob",13 },{ "Tom",13 },{ "Afrim",14 } };
  groupByAge2(&students);
  for (auto student : students) cout << student.getAge();
}
