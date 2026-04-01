class DSU {
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        int findA = find(a);
        int findB = find(b);
        if(findA == findB) return false;

        if(size[findA] < size[findB]){
            swap(findA, findB);
        }
        parent[findB] = findA;
        size[findA] += size[findB];
        return true;
    }
};


class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        vector<int> redundantEdge(2);
        for(auto& edge : edges){
            if(!dsu.unite(edge[0], edge[1])){
                redundantEdge[0] = edge[0];
                redundantEdge[1] = edge[1];
            }
        }
        return redundantEdge;
    }
};
