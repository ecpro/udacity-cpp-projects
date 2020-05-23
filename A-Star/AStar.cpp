#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<cmath>
#include<algorithm>

using std::vector;
using std::abs;
using std::sort;
using std::cout;
using std::endl;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

std::vector<State> ParseLine(std::string line_with_comma) {
    std::istringstream stream(line_with_comma);
    std::vector<State> vector;
    std::string s;
    while(getline(stream, s, ',')) {
        int n = std::stoi(s);
        if(n == 0) {
            vector.push_back(State::kEmpty);
        }
        else {
            vector.push_back(State::kObstacle);
        }
    }
    return vector;
}

std::string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰   ";
    case State::kPath: return "🚗  ";
    default: return "0   "; 
  }
}

void PrintBoard(std::vector<std::vector<State>>& board) {
    for(auto i = 0; i != board.size(); i++) {
        for(auto j = 0; j != board[1].size(); j++) {
            std::cout<< CellString(board[i][j]);
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<State>> ReadBoardFile(std::string& filename) {
    std::ifstream inFile(filename);

    if(!inFile) {
        std::cerr << "Failed to open file " << filename << std::endl;
        exit(1);
    }
    std::string s{};
    std::vector<std::vector<State>> board;
    while (getline(inFile, s)) {
        std::vector<State> line = ParseLine(s);
        board.push_back(line);
    }
    return board;
}

void TestParseLineMethod() {
    std::string s{"0,1,2,3,"};
    std::vector<State> result = ParseLine(s);
    for(int i = 0; i != result.size(); i++) {
        std::cout << static_cast<int>(result[i]) << std::endl;
    }
} 


bool Compare(const vector<int> a, const vector<int> b) {
    int f1 = a[2] + a[3];
    int f2 = b[2] + b[3];
    return f1 > f2;
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>>& open_nodes, vector<vector<State>>& grid) {
    vector<int> open_node {x, y, g, h};
    open_nodes.push_back(open_node);
    grid[x][y] = State::kClosed;
}

bool CheckValidCell(int x, int y, vector<vector<State>>& grid) {
    int col_Len = grid[0].size();
    int row_Len = grid.size();

    if(x < 0 || x >= row_Len) return false;
    if(y < 0 || y >= col_Len) return false;
    if(grid[x][y] == State::kEmpty || grid[x][y] == State::kFinish) return true;
    return false;
}

int Heuristic(int x1, int y1, int x2, int y2) {
    // manhattan_dist = abs{x1-x2} + abs{y1-y2}
    return abs(x2 - x1) + abs(y1 - y2);
}

void expandNeighbour(vector<int>& curr_node, vector<vector<int>>& open_nodes, vector<vector<State>>& grid, int dest[]) {
    int x = curr_node[0], y = curr_node[1], g = curr_node[2], h = curr_node[3];
    for(auto i : delta) {
        int x_neighbour = x + i[0];
        int y_neighbour = y + i[1];
        if(CheckValidCell(x_neighbour, y_neighbour, grid)){
            
            h = Heuristic(x_neighbour, y_neighbour, dest[0], dest[1]);
            AddToOpen(x_neighbour, y_neighbour, g+1, h, open_nodes, grid);
        }
    }
}

void CellSort(vector<vector<int>>* nodes) {
    sort(nodes->begin(), nodes->end(), Compare);
}

vector<vector<State>> Search(vector<vector<State>> grid, int src [], int dest[]) {

    grid[0][0] = State::kStart;
    grid[grid.size() - 1][grid[0].size() - 1] = State::kFinish;

    int g = 0;
    int h = Heuristic(src[0], src[1], dest[0], dest[1]);
    vector<vector<int>> open_nodes {};
    AddToOpen(src[0], src[1], g, h, open_nodes, grid);
    while(!open_nodes.empty()) {
        CellSort(&open_nodes);
        auto curr = open_nodes.back();
        open_nodes.pop_back();
        int x{curr[0]}, y{curr[1]};
        grid[x][y] = State::kPath;
        if(x == dest[0] && y == dest[1]) {
            cout<< "Path found" << endl;  
            return grid;
        }
        expandNeighbour(curr, open_nodes, grid, dest);
    }
    return grid;
}




int main() {
    std::string fileName{"1.board"};
    auto board = ReadBoardFile(fileName); 
    PrintBoard(board);
    int src [] {0,0};
    int dest [] {4,5};   
    auto solution = Search(board, src, dest);
    PrintBoard(solution);
    return 0;
}