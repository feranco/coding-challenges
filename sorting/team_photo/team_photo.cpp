//algorithm to check if it is possible to place two teams
//of player in two different rows and takes a photo
//Constraints:
//1) each team shall be placed in the same row
//2) each player in the back row shall be taller than
//the player in the front row

#include <vector>
#include <iostream>

using namespace std;

struct Player {
  int height;
  bool operator< (const Player& rhs) const {
    return height < rhs.height;
  }
};

class Team {
  vector<Player> players;
  vector<Player> sortPlayers (void) const{
    vector<Player> sorted_players(players);
    sort(sorted_players.begin(), sorted_players.end());
    return sorted_players;
  }
public:
  Team (const vector<int>& heights) {
    for (int height : heights) players.emplace_back(Player{height});
  }

  static bool existsValidPlacement (const Team& a, const Team&b) {
    vector<Player> sorted_a = a.sortPlayers();
    vector<Player> sorted_b = b.sortPlayers();
    const vector<Player>& back_row = (sorted_a.back().height < sorted_b.back().height) ?
       sorted_b : sorted_a;
    const vector<Player>& front_row = (sorted_a.back().height < sorted_b.back().height) ?
       sorted_a : sorted_b;
    for (int i = 0; (i < back_row.size() && i < front_row.size()); ++i) {
      if (front_row[i].height > back_row[i].height) return false;
    }
    return true;
  }
};

int main (void) {
  Team a({175, 165, 190, 185, 177, 183});
  Team b({164, 176, 190, 184, 192, 188});
  cout << Team::existsValidPlacement(a,b);
}
