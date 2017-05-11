#include <stack>
#include <iostream>
#include <stdexcept>

using std::stack;
using std::cout;

class Tower {
  stack<int> disks;
public:
  Tower (void){}
  void addDisk (int disk) {disks.push(disk);}
  int removeDisk (void) { 
    if(disks.empty()) throw std::runtime_error("Remove from empty tower!");
    else {
      int disk = disks.top(); 
      disks.pop();
      return disk;
    }
    friend ostream& operator<<(ostream& out, const Tower& rhs);
  };

  ostream& operator<<(ostream& out, const Tower& rhs) {
    if (rhs.disks.empty()) out << "Empty Tower!" << "\n";
    else {
      stack<int> tmp;
      while (!rhs.disks.empty()) {
	cout << rhs.disks.top() << " ";
	tmp.push(rhs.disks.top());
	rhs.disks.pop();
      }
      cout << "\n";
      while (!tmp.empty()) {
	rhs.disks.push(tp.top());
	tmp.pop();
      }
    }
  }

  void moveDisk (int disk, Tower& src, Tower& dst) {
    if (disk == 0) return;
    moveDisk()
  }
