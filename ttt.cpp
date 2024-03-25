#include <iostream>
#include <limits>
using namespace std;

char board[4][4] = {' ', ' ', ' ', ' ', ' ', ' '};
int gameover = 0;
char winner;
int row, column;
char input;

void change_input() {
    switch (row) {
        case 1:
            row = 0;
            break;
        case 2:
            row = 1;
            break;
        case 3:
            row = 2;
            break;
    }
    switch (column) {
        case 1:
            column = 0;
            break;
        case 2:
            column = 1;
            break;
        case 3:
            column = 2;
            break;
    }
}

void char_input() {
    cout << "Enter Position and value (e.g 1 2 x): ";
    cin >> row >> column >> input;

    // Clear input stream and ignore any remaining characters
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (row > 3 || column > 3) {
        cout << "** Position out of range **" << '\n';
        cout << "Re-enter position: ";
        cin >> row >> column;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if (row < 1 || row < 1) {
        cout << "** Position below range **" << '\n';
        cout << "Re-enter position: ";
        cin >> row >> column;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    change_input();
    if (input == 'x' || input == 'o') {
        if (board[row][column] == 'x' || board[row][column] == 'o' ) {
            cout << "** Position occupied **\n";
            cout << "Re-enter position: ";
            cin >> row >> column;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            change_input();
        }
        board[row][column] = input;
    }
    else {
        cout << "** You can only input 'x' or 'o' **'\n'";
        cout << "Re-enter value: \n";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        board[row][column] = input;
    }
}

void logic() {
    if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) && (board[1][1] == 'x' || board[1][1] == 'o')) {
        winner = board[1][1];
        gameover = true; // '\'
    }
    else if (((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) && (board[1][1] == 'x' || board[1][1] == 'o')) {
        winner = board[1][1];
        gameover = true; // '/'
    }
    else if (((board[0][0] == board[0][1]) && (board[0][1] == board[0][2])) && (board[0][1] == 'x' || board[0][1] == 'o')) {
        winner = board[0][1];
        gameover = true;
    }
    else if (((board[1][0] == board[1][1]) && (board[1][1] == board[1][2])) && (board[1][1] == 'x' || board[1][1] == 'o')) {
        winner = board[1][1];
        gameover = true;
    }
    else if (((board[2][0] == board[2][1]) && (board[2][1] == board[2][2])) && (board[2][1] == 'x' || board[2][1] == 'o')) {
        winner = board[2][1];
        gameover = true;
    }
    else if (((board[0][1] == board[1][1]) && (board[1][1] == board[2][1])) && (board[1][1] == 'x' || board[1][1] == 'o')) {
        winner = board[1][1];
        gameover = true;
    }
    else if (((board[0][2] == board[1][2]) && (board[1][2] == board[2][2])) && (board[1][2] == 'x' || board[1][2] == 'o')) {
        winner = board[1][2];
        gameover = true;
    }
    else if (((board[0][0] == board[1][0]) && (board[1][0] == board[2][0])) && (board[1][0] == 'x' || board[1][0] == 'o')) {
        winner = board[1][0];
        gameover = true;
    }
}

void draw() {
    cout << '\n' << '\n';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ' ' << board[i][j] << ' ';
            if (j == 0 || j == 1)
                cout << "\t ||";
        }
        if (i == 0 || i == 1)
            cout << '\n' << "---- ++ ---- ++ ----";
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    int loop_count = 0;
    system("clear");
    while (!gameover) {
        draw();
        char_input();
        logic();
        if (!gameover)
            system("clear");
        if (gameover) {
            system("clear");
            draw();
            cout << "Game Over: Player " << winner << " won the game!\n" << endl;
        }
        loop_count++;
        if (loop_count == 9) {
            cout << "Game Over: It's a draw!" << endl;
            gameover = true;
        }
    }
    return 0;
}
