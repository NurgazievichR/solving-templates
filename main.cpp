//C++ base template

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

int n;
void solve() {

}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int tt = 1;
int main() {
    fast_io();
    cin >> tt;
    while (tt--) solve();
    return 0;
}

int maxn, MOD;

//DSU (Disjoint Set Union)
//Система непересекающихся множеств

//parent хранит представителя множества (корень), size хранит размер компоненты связности только для корней
int parent[maxn], size_dsu[maxn];

int find_dsu(int x) {
    if (parent[x]!=x) parent[x] = find_dsu(parent[x]);
    return parent[x];
}

void union_dsu(int a, int b) {
    int a_parent = find_dsu(a);
    int b_parent = find_dsu(b);

    if (a_parent == b_parent) return;

    if (size_dsu[a_parent] < size_dsu[b_parent]) {
        swap(a_parent, b_parent);
    }
    parent[b_parent] = a_parent;
    size_dsu[a_parent] += size_dsu[b_parent];
    size_dsu[b_parent] = 0; //optional
}