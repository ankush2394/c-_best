//
// Created by OLX on 22/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

int visited[400][400];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isInside(int i, int j, vector<vector<char>>&graph ) {
    if(i>=0 && j>=0 && i<graph.size() && j<graph[0].size()) {
        return true;
    }
    return false;
}

void dfs( int i, int j, vector<vector<char>>&graph) {

    if (isInside(i,j,graph)) {
        visited[i][j] = 1;
    }

    for (int k=0;k<4;k++) {
        int posi=i+dx[k];
        int posj =j+dy[k];

        if(isInside(posi,posj,graph) && graph[posi][posj] == '1' && visited[posi][posj]==-1) {
            dfs(posi, posj, graph);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int cnt=0;
    for(int i=0;i<grid.size();i++) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (visited[i][j]==-1 && grid[i][j]=='1') {
                dfs(i, j, grid);
                cnt++;
            }
        }
    }
    return cnt;
}

//int main() {
//
//    vector<vector<char>> grid= {
//            {'1','1','1','1','0'},
//            {'1','1','0','1','0'},
//            {'1','1','0','0','0'},
//            {'0','0','0','0','0'}
//    };
//    memset(visited, -1, sizeof visited);
//
//    cout<<numIslands(grid);
//    return 0;
//
//}
