//algorithm detecting a cycle in a directed graph

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

//white = undiscovered, grey = discovered but not totally processed, black = processed
enum class Color { white, grey, black };

template <typename T>
unordered_map<T, unordered_set<T>> buildGraph(const vector<pair<T, T>>& edges) {
  unordered_map<T, unordered_set<T>> graph;
  for (const auto& edge : edges) {
    graph[edge.first].emplace(edge.second);
  }
  return graph;
}

template <typename T>
bool isCyclic(const unordered_map<T, unordered_set<T>>& graph,  const T& current_vertex, unordered_map<T, Color>* state_ptr) {
  unordered_map<T, Color>& state = *state_ptr;
  state[current_vertex] = Color::grey;
#if 0
  any_of(begin(graph.at(current_vertex)), end(graph.at(current_vertex)), [&](const T& vertex) {
      if (state[vertex] == Color::grey) return true;
      if (state[vertex] == Color::white) {
	if (isCyclic(graph, vertex, &state)) return true;
      }
    });
#endif
  for (const auto& vertex : graph.at(current_vertex)) {//const and  []
    if (state[vertex] == Color::grey) return true;
    if (state[vertex] == Color::white) {
      if (isCyclic(graph, vertex, state_ptr)) return true;
    }
  }

  state[current_vertex] = Color::black;
  return false;
}

template <typename T>
bool isCyclic(const unordered_map<T, unordered_set<T>>& graph) {
  unordered_map<T, Color> state;
  for (const auto& vertex : graph) state[vertex.first] = Color::white;
  return isCyclic(graph, graph.begin()->first, &state);

}

int main(void) {
  vector<pair<char, char>> edges;
  edges.emplace_back(make_pair('A', 'B'));
  edges.emplace_back(make_pair('B', 'C'));
  edges.emplace_back(make_pair('C', 'E'));
  edges.emplace_back(make_pair('E', 'D'));
  edges.emplace_back(make_pair('D', 'B'));
  edges.emplace_back(make_pair('E', 'F'));
  edges.emplace_back(make_pair('F', 'D'));
  auto graph = buildGraph(edges);
  cout << isCyclic(graph);
}
