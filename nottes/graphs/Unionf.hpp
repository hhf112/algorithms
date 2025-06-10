//DISJOINT SET - UNION 
//     * used to find divide the graph into connected componenets 
//     --> provides O(1) lookup time for checking which component a certain vertex belongs to
//
#pragma once
#include <bits/stdc++.h>

class Unionf {
  std::vector<int> parent;
  std::vector<int> size;
  // std::vector<int> rank;

public:
  Unionf(int n) {
    // rank.resize(n + 1, 1);
    size.resize(n + 1, 1);
    parent.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }


  int find(int u){
    if (u == parent[u])
      return u;

    else 
      return parent[u] = find(parent[u]);
  }


  bool _union(int u, int v) {
    int up = find(u), vp = find(v);

    if (up == vp) 
      return false;

    if (size[up] > size[vp]){
      parent[vp] = up;
      size[vp] += size[vp];
    }

    else {
      parent[up] = vp;
      size[up] += size[vp];
    }

    return true;
  }

  // bool unionr(int u, int v) {
  //   int up = find(u), vp = find(v);
  //
  //   if (up == vp)
  //     return false;
  //
  //   if (rank[up] > rank[vp]) 
  //     parent[vp] = up;
  //   else if (rank[vp] > rank[up]) 
  //     parent[up] = vp;
  //   else{
  //     parent[up] = vp;
  //     rank[up]++;
  //   }
  //
  // return true;
  // }

  std::vector<int>& getParents() {
    return parent;
  }

  std::vector<int>& getSizes() {
    return size;
  }

  // std::vector<int>& getRanks (){
  //   return rank;
  // }
};
