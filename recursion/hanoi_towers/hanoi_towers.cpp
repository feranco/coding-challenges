//algorithm to solve the classic hanoi tower problem
#include <vector>
#include <iostream>
using namespace std;

//the id identifies the ring according to its size
//1 the smallest,... , n the largest
struct Ring {
    int id;
    Ring(int x) : id(x){}
};

struct Peg {
    int id;
    vector<Ring> rings;
    Peg (int id, int n) {this->id = id;
      for (int i = n; i >=1; --i) rings.emplace_back(i);
    }
    void addRing (Ring& ring) {rings.emplace_back(ring);}
    void eraseRing (void) {rings.pop_back();}
    void moveRing (Peg& destination) {
        auto ring = rings.back();
        eraseRing();
        destination.addRing(ring);
        cout << "Move " << ring.id << " from Peg " << id << " to Peg "
        << destination.id << "/n";
    }
    bool empty (void) {return rings.empty();}
    friend ostream& operator<< (ostream& os, const Peg& peg) {
        os << "Peg " << peg.id << " : ";
        for (auto ring : peg.rings) os << ring.id << " ";
        os << "/n";
        return os;
    }
};

void hanoi_towers (int n_rings, Peg& source, Peg& destination, Peg& tmp) {
    if (n_rings == 0) return;
    hanoi_towers(n_rings-1, source, tmp, destination);
    source.moveRing(destination);
    hanoi_towers(n_rings-1, tmp, destination, source);
}

int main (void) {
    vector<Peg> pegs{{1,4},{2,0},{3,0}};
    hanoi_towers(4,pegs[0],pegs[1],pegs[2]);
};

