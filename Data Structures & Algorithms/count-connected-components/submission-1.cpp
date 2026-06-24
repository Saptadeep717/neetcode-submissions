class Disjoint{
public:
    vector<int>parent, size;
    Disjoint(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        size.resize(n,1);
    }

    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]) ;
    }

    void connect(int u, int v){
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if(pu==pv) return;

        if(size[pu] <= size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Disjoint ds(n);
        for(int i=0;i<edges.size();i++){
            ds.connect(edges[i][0], edges[i][1]);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            ds.parent[i] = ds.findUltimateParent(i);
        }

        unordered_set<int>st(ds.parent.begin(),ds.parent.end());
        return st.size();
    }
};
