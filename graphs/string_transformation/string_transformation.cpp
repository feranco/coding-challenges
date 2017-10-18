//algorithm detecting a cycle in a directed graph

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool diffByOne (const string& a, const string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) cnt++;
    }
    return (cnt == 1) ? true : false; 
}

unordered_map<string,vector<string>> buildGraph (vector<string>& dict) {
    unordered_map<string,vector<string>> graph;
    
    for (const string& s : dict) graph.emplace(s, vector<string>()); 
    for (int i = 0; i < dict.size(); ++i) {
        for (int j = i+1; j < dict.size(); ++j) {
            if (diffByOne(dict[i],dict[j])) {
                graph[dict[i]].push_back(dict[j]);
                graph[dict[j]].push_back(dict[i]);
            }
        }
    }
    return graph;
}

int hasProductionSequence(vector<string> &dict, string start, string end) {
    
    if (start == end) return 1;
    
    unordered_map<string,vector<string>> graph = buildGraph(dict);
    unordered_map<string,string> parent;
    unordered_set<string> discovered;
    queue<string> q;
    
    //init
    for (const string& s : dict) parent.emplace(s, "");
    q.emplace(start);
    discovered.emplace(start);
    
    //bfs
    while (!q.empty()) {
        const string& u = q.front();
        q.pop();
        
        if (u == end) break;
        
        for (const auto& v : graph[u]) {
            if (discovered.find(v) == discovered.end()) {
                discovered.emplace(v);
                parent[v] = u;
                q.emplace(v);
            }
        }
    }
    
    int length = 1;
    while (parent.at(end) != "") {
        length++;
        end = parent.at(end);
    }
    return (end == start) ? length : 0;
}
    
int main(void) {
  vector<string> dictionary{"bat","cot","dog","dag","dot","cat"};
  cout << hasProductionSequence(dictionary, "cat", "dog");
}
