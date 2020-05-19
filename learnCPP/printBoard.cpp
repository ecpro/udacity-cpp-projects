#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>

std::vector<int> ParseLine(std::string line_with_comma) {
    std::istringstream stream(line_with_comma);
    std::vector<int> vector;
    std::string s;
    while(getline(stream, s, ',')) {
        int n = std::stoi(s);
        vector.push_back(n);
    }
    return vector;
}

void PrintBoard(std::vector<std::vector<int>>& board) {
    for(auto i = 0; i != board.size(); i++) {
        for(auto j = 0; j != board[1].size(); j++) {
            std::cout<< board[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    board[0][0] = 4;
}

std::vector<std::vector<int>> ReadBoardFile(std::string& filename) {
    std::ifstream inFile(filename);

    if(!inFile) {
        std::cerr << "Failed to open file" << filename << std::endl;
        exit(1);
    }
    std::string s{};
    std::vector<std::vector<int>> board;
    while (getline(inFile, s)) {
        std::vector<int> line = ParseLine(s);
        board.push_back(line);
    }
    return board;
}

void TestParseLineMethod() {
    std::string s{"0,1,2,3,"};
    std::vector<int> result = ParseLine(s);
    for(int i = 0; i != result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
} 

int main() {
    //std::vector<std::vector<int>>  board{{0,1,0,0,0,0},{0,1,0,0,0,0}, {0,1,0,0,0,0}, {0,1,0,0,0,0}, {0,0,0,0,1,0}};
    //PrintBoard(board);
    std::string file{"1.board"};
    std::vector<std::vector<int>> result = ReadBoardFile(file);
    PrintBoard(result);
    return 0;
}