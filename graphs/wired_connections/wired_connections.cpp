#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <queue>

using namespace std;

struct Vertex {
  int v;
  string pcb_side;
  vector<Vertex*> edges;
  Vertex (int v, string side = "unknown"):v(v){}  
};

vector<Vertex> buildGraph(ifstream& ifs) {
  int n_vertex;
  
  ifs >> n_vertex;

  if (n_vertex <= 0) {
    throw std::invalid_argument("Number of vertices in a Graph must be nonnegative");
  }

  vector<Vertex> graph;
  for (int i = 0; i < n_vertex; i++) graph.emplace_back(i);

  int start, end;
  while (ifs >> start >> end) {
    graph[start].edges.emplace_back(&graph[end]);
    graph[end].edges.emplace_back(&graph[start]);
  }
  return graph;
}

bool placePins (Vertex* v) {
  queue<Vertex*> q;
  v->pcb_side = "left";
  q.emplace(v);
  
  while (!q.empty()) {
    Vertex* current = q.front();
    q.pop();

    for (Vertex* vertex : current->edges) {
      if (vertex->pcb_side == current->pcb_side) return false;
      if (!(vertex->pcb_side == "unknown")) {
	vertex->pcb_side = (current->pcb_side == "left") ? "right" : "left";
	placePins(vertex);
      }
    }  
  }
  return true;
}

bool placePins (vector<Vertex>* pcb) {
  for (int i = 0; i < pcb->size(); ++i) {
    if ((*pcb)[i].pcb_side == "unknown" && !placePins(&(*pcb)[i])) return false;
  }
  return true;
}

int main (void) {
  ifstream ifs( "pcb.txt" );
  if (!ifs) throw runtime_error("pcb not defined!");
    
  auto graph = buildGraph(ifs);
}


