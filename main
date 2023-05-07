#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void rank_pairing_heap(vector<int>& arr) {
    vector<vector<int>> tree;
    tree.push_back(arr);
    int n = tree.size();

    for (int i = n-1; i > 0; i--) {
        if (tree[i].size() < tree[i-1].size()) {
            swap(tree[i], tree[i-1]);
        }
        tree[i].push_back(tree[i-1].back());
        tree[i-1].pop_back();
        if (tree[i].size() == tree[i-1].size() + 2) {
            tree[i-1].push_back(tree[i].back());
            tree[i].pop_back();
        }
        while (i > 1 && tree[i].size() == tree[i-2].size()) {
            vector<int> temp;
            temp.insert(temp.end(), tree[i-2].begin(), tree[i-2].end());
            temp.insert(temp.end(), tree[i].begin(), tree[i].end());
            sort(temp.begin(), temp.end());
            tree[i-2] = temp;
            tree.erase(tree.begin() + i - 1, tree.begin() + i + 1);
            i -= 2;
        }
    }

    arr = tree[0];
}

int main() {
    ifstream infile("input.txt");
    int n;
    infile >> n;

    vector<vector<int>> arrays(n);
    for (int i = 0; i < n; i++) {
        int x;
        while (infile >> x) {
            arrays[i].push_back(x);
        }
    }

    for (auto& arr : arrays) {
        rank_pairing_heap(arr);
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
