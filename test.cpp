#include <iostream>
#include <vector>
using namespace std;

void printGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << "+---";
        }
        cout << "+" << endl;

        for (char cell : row) {
            cout << "| " << cell << " ";
        }
        cout << "|" << endl;
    }

    for (char cell : grid[0]) {
        cout << "+---";
    }
    cout << "+" << endl;
}

int main() {
    vector<vector<int>> pattern = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };

    vector<vector<char>> grid(pattern.size(), vector<char>(pattern[0].size(), ' '));

    for (size_t i = 0; i < pattern.size(); ++i) {
        for (size_t j = 0; j < pattern[i].size(); ++j) {
            if (pattern[i][j] == 1) {
                grid[i][j] = 'X';
            }
        }
    }

    printGrid(grid);

    return 0;
}
