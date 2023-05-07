#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Implementation of rank pairing heap method
void rank_pairing_heap_sort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    // Create the initial forest of trees
    vector<vector<int>> forest;
    for (int i = 0; i < arr.size(); i++) {
        forest.push_back(vector<int>{arr[i]});
    }

    // Repeatedly merge pairs of trees until only one tree remains
    while (forest.size() > 1) {
        vector<vector<int>> new_forest;
        for (int i = 0; i < forest.size(); i += 2) {
            if (i == forest.size() - 1) {
                // If there's an odd number of trees, add the last one to the new forest
                new_forest.push_back(forest[i]);
            } else {
                // Merge the two trees and add the result to the new forest
                vector<int> merged_tree;
                int j = 0, k = 0;
                while (j < forest[i].size() && k < forest[i + 1].size()) {
                    if (forest[i][j] < forest[i + 1][k]) {
                        merged_tree.push_back(forest[i][j]);
                        j++;
                    } else {
                        merged_tree.push_back(forest[i + 1][k]);
                        k++;
                    }
                }
                while (j < forest[i].size()) {
                    merged_tree.push_back(forest[i][j]);
                    j++;
                }
                while (k < forest[i + 1].size()) {
                    merged_tree.push_back(forest[i + 1][k]);
                    k++;
                }
                new_forest.push_back(merged_tree);
            }
        }
        forest = new_forest;
    }

    // Copy the sorted array back into the original array
    arr = forest[0];
}

int main() {
    // Read input from file
    ifstream input_file("input.txt");
    int n;
    input_file >> n;

    vector<vector<int>> arrays;
    for (int i = 0; i < n; i++) {
        vector<int> arr;
        int len;
        input_file >> len;
        for (int j = 0; j < len; j++) {
            int x;
            input_file >> x;
            arr.push_back(x);
        }
        arrays.push_back(arr);
    }
    input_file.close();

    // Sort the arrays using rank pairing heap method
    for (int i = 0; i < n; i++) {
        rank_pairing_heap_sort(arrays[i]);
    }

    // Write sorted arrays to output file
    ofstream output_file("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arrays[i].size(); j++) {
            output_file << arrays[i][j] << " ";
        }
        output_file << endl;
    }
    output_file.close();

    return 0;
}
