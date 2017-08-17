#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Student {
  int age;
  string name;
public:
  Student (string name, int age) {
    this->age = age;
    this->name = name;
  }
  int getAge (void) {return age;}
};

void groupByAge (vector<Student>* students_ptr) {
  vector<Student>& students =  *students_ptr;

  unordered_map<int,int> age_frequency;
  for (const auto& student : students) ++age_frequency[student.getAge()];

  unordered_map<int,int> age_offset;
  int offset = 0;
  for (const auto& frequency : age_frequency) {
    age_offset.insert({frequency.first,offset});
    offset += frequency.second;
  }

  while (!age_offset.empty()) {
    auto got = age_offset.begin();
    if (got != age_offset.end()) {
      swap(students[got->second],students[idx]);
      --age_frequency[got->first];
      if (age_frequency[got->first]==0) age_offset.erase(got->first);
      else got->second++;
    }
  }
}

int main (void) {
  vector<Student> students = {{"Pippo",14},{"Pluto",12},{"Topolino",11},
			      {"Luca",13},{"Tim",12},{"Bob",13},{"Tom",13},{"Afrim",14}};
  groupByAge(&students);
  for (auto student : students) cout << student.getAge();
}

