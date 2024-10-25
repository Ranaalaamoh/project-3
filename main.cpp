
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


bool Ifempty(char X) {
    return X == ' ';
}

int IfWin(char(&a)[3][3], char sumpol) {
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == sumpol && a[i][1] == sumpol && a[i][2] == sumpol) {
            return 1;
        } else if (a[0][i] == sumpol && a[1][i] == sumpol && a[2][i] == sumpol) {
            return 1;
        }
    }

    if (a[0][0] == sumpol && a[1][1] == sumpol && a[2][2] == sumpol) {
        return 1;
    } else if (a[0][2] == sumpol && a[1][1] == sumpol && a[2][0] == sumpol) {
        return 1;
    }

    return 0;
}

bool IsTie(char(&a)[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int cGame(char(&a)[3][3]) {
    srand(static_cast<unsigned int>(time(nullptr)));

    int i = rand() % 3;
    int j = rand() % 3;

    if (Ifempty(a[i][j])) {
        a[i][j] = 'O';

        if (IfWin(a, 'O')) {
            cout << "The computer wins!"<<endl;
            return 0;
        } else if (IsTie(a)) {
            cout << "It's a tie"<<endl;
            return 0;
        }
    } else {

    }

    return 1;
}

int main() {
    char tic[3][3] = { {' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '} };

     cout << "0 0| 0 1| 0 2"<<endl
          << "1 0| 1 1| 1 2"<<endl
          << "2 0| 2 1| 2 2"<<endl;

   cout << "Enter the place you want to put X: ";

    int i, j;

    while (true) {
        std::cout << tic[0][0] << "|" << tic[0][1] << "|" << tic[0][2] <<endl
                  << tic[1][0] << "|" << tic[1][1] << "|" << tic[1][2] << endl
                  << tic[2][0] << "|" << tic[2][1] << "|" << tic[2][2] << endl;

        cin >> i >> j;

        if (Ifempty(tic[i][j])) {
            tic[i][j] = 'X';

            if (IfWin(tic, 'X') == 1) {
                cout << "You win!"<<endl;
                return 0;
            }
        }

        if (!cGame(tic)) {
            break;
        }
    }

    return 0;
}