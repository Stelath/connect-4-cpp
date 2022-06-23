#include <iostream>

class GameController
{
public:
    GameController() {}

    int isWinner() {
        for(int p = 1; p < 3; p++){
        for(int r = 0; r < boardSize[1] - 3; r++) {
            for(int c = 0; c < boardSize[0]; c++) {
                if (board[r][c] != 0)
                {
                    int countL = 0;
                    int countR = 0;
                    int countD = 0;
                    for(int i = 0; i < 4; i++) {   
                        if(c > 2 && board[r - i][c - i] == p) {
                            // Left
                            countL++;
                        }
                        if(c < boardSize[0] - 3 && board[r - i][c + i] == p) {
                            // Right
                            countR++;
                        }
                        if(board[r - i][c] == p) {
                            // Right
                            countD++;
                        }
                    }

                    if (countL >= 4 || countR >= 4 || countD >= 4)
                    {
                        return p;
                    }
                }
            }
        }
        }
        return 0;
    }

    bool dropPiece(int col) {
        bool completed = false;
        for (int r = 1; r < boardSize[1]; r++) {
            if (board[r][col] != 0) {
                board[r - 1][col] = activePlayer;
                completed == true;
            }
        }
        return completed;
    }

    int newTurn() {
        int input;
        do {
            std::cout << "Please Choose a Column to Drop Your Piece " << activePlayer << std::endl;
            std::cin >> input;
        }
        while (dropPiece(input));

        activePlayer++;

        int winner = isWinner();
        if (winner != 0) {
            gameOver();
        }
    }

    void gameOver() {
        // Game over Stuff
    }

    const int (*getBoard())[7] {
        return board;
    }
private:
    int boardSize[2] = {7, 6};
    int board[6][7];
    int activePlayer = 1;
    int input;
};

int main()
{
    GameController gameController;
    std::cout << gameController.board;
    return 0;
}