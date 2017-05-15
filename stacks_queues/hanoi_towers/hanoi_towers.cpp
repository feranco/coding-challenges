#include <stack>
#include <iostream>
#include <stdexcept>

using std::stack;
using std::cout;
using std::ostream;

class Tower {
  stack<int> disks;
public:
  Tower (void){}

  void addDisk (int disk) {
    disks.push(disk);
  }

  int removeDisk (void) { 
    if(disks.empty()) throw std::runtime_error("Remove from empty tower!");
    else {
      int disk = disks.top(); 
      disks.pop();
      return disk;
    }
  }

  bool empty (void) {return disks.empty();}

  void moveDisks (int disk, Tower& src, Tower& buf);

  friend ostream& operator<<(ostream& out, Tower& rhs);
};

ostream& operator<<(ostream& out,  Tower& rhs) {
  if (rhs.empty()) out << "Empty Tower!" << "\n";
  else {
    stack<int> tmp;
    while (!rhs.empty()) {
      int x = rhs.removeDisk() ;
      out << x << " ";
      tmp.push(x);
    }
    out << "\n";
    while (!tmp.empty()) {
      rhs.addDisk(tmp.top());
      tmp.pop();
    }
  }
  return out;
}

void Tower::moveDisks (int disk, Tower& dst, Tower& buf) {
  if (disk == 0) return;
  moveDisks(disk-1, buf, dst);
  dst.addDisk(removeDisk());
  buf.moveDisks(disk-1, dst, *this);
}

int main (void) {
  Tower towers[3];
  for (int i = 5; i > 0; --i) towers[0].addDisk(i);
  for (int i = 0; i < 3; ++i) cout << towers[i];
  towers[0].moveDisks(5, towers[2], towers[1]);
  for (int i = 0; i < 3; ++i) cout << towers[i];
}

