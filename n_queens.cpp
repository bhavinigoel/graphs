#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10;

bool isSafe(int row, int col, char board[MAX_N][MAX_N], int N) {
    for (int j = 0; j < N; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }
    for (int i = 0; i < N; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i < N && j < N; i++, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
void saveBoard(char board[MAX_N][MAX_N], vector<vector<string>>& allBoards, int N) {
    vector<string> newBoard;
    for (int i = 0; i < N; i++) {
        string row = "";
        for (int j = 0; j < N; j++) {
            row += board[i][j];
        }
        newBoard.push_back(row);
    }
    allBoards.push_back(newBoard);
}
void solve(char board[MAX_N][MAX_N], vector<vector<string>>& allBoards, int col, int N) {
    if (col == N) {
        saveBoard(board, allBoards, N);
        return;
    }
    for (int row = 0; row < N; row++) {
        if (isSafe(row, col, board, N)) {
            board[row][col] = 'Q';
            solve(board, allBoards, col + 1, N);
            board[row][col] = '.';
        }
    }
}
void solution(int N) {
    vector<vector<string>> allBoards;
    char board[MAX_N][MAX_N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }
    solve(board, allBoards, 0, N);

    for (auto aboard : allBoards) {
        for (auto row : aboard) {
            cout << row << endl;
        }
        cout << endl;
    }
}
int main() {
    solution(4);
    return 0;
}
