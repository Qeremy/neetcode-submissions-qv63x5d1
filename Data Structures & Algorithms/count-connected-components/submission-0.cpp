class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return false;

        if (size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int components = n;

        for (auto& edge : edges) {
            if (dsu.unite(edge[0], edge[1])) {
                components--;
            }
        }

        return components;
    }
};