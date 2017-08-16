#include <string>
#include <vector>
#include <unordered_map>

class Student {
  int age;
  string name;
public:
  Student (string name, int age) {
    this->age = age;
    this->name = name;
  }
  int age (void) {return age;}
};

void groupByAge (vector<Student>* students_ptr) {
  vector<Student>& students =  *students_ptr;

  unordered_map<int,int> age_frequency;
  for (auto student : students) ++age_frequency[student.age()];

  unordered_map<int,int> age_offset;
  int offset = 0;
  for (auto frequency : age_frequency) {
    age_offset.insert({frequency->first,offset});
    offset += frequency->second;
  }

  int idx = 0;
  while (!age_offset.empty()) {
    auto got = age_offset.find(students[idx].age());
    if (got != age_offset.end()) {
      swap(students[got->second],students[idx]);
      --age_frequency[got->first];
      if (age_frequency[got->first]==0) age_offset.erase(got->first);
      else got->second++;
    }
  }
}


