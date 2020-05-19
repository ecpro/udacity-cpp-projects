#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>

enum class State {kEmpty, kObstacle};

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
    case State::kObstacle: return "⛰️   ";
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
        std::cerr << "Failed to open file" << filename << std::endl;
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

int main() {
    std::string fileName{"1.board"};
    auto board = ReadBoardFile(fileName);    
    PrintBoard(board);
    return 0;
}