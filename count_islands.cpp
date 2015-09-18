// count the number of islands (connected 1s) in an n by n array
//
// example:
// {1, 1, 0, 0, 0}
// {0, 1, 0, 0, 1}
// {1, 0, 0, 1, 1}
// {0, 0, 0, 0, 0}
// {1, 0, 1, 0, 1}
//
// has 5 islands

#include <iostream>
#include <queue>

using namespace std;

const int size = 5;


// naive version - look at all n^2 elements
// runtime O(n^2)
void count_num_islands(bool** arr) {
    bool visited[size][size];
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
           //FINISH THIS 
        }
    }
}

bool valid_land_cell(bool arr[][size], bool visited[][size], int i, int j) {
    // return true if cell is within bounds of array
    // and is a 1 and hasn't been visited yet 
    return((i >= 0 && i < size) &&
       (j >= 0 && j < size) &&
       (arr[i][j] == 1 && !visited[i][j]));
}

void dfs(bool arr[][size], bool visited[][size], int r, int c) {
    
    visited[r][c] = true;
    
    // used to calculate indeces of neighbors
    int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i = 0; i < 8; i++) {
        if(valid_land_cell(arr, visited, r + row[i], c + col[i]))
            dfs(arr, visited, r + row[i], c + col[i]);
    }
}

// perform DFS on the array and count number of components
void count_num_islands_2(bool arr[][size]) {
    bool visited[size][size];
    memset(visited, 0, sizeof(visited));

    // traverse through all cells of the matrix
    int count = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            // if unvisited cell == 1, increment count
            // and visit all cells in the island
            if(arr[i][j] && !visited[i][j]) {
                count++;
                dfs(arr, visited, i, j);
            }
        }
    }
    cout << "There are " << count << " islands." << endl;
}

int main() {

    bool arr[][size] = {{1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1}};

    count_num_islands_2(arr);
}
