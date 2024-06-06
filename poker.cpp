#include <iostream>
#define random(a,b) a + rand()% b + 1 - a
using namespace std;

const string NAMES[] = { "Вася", "Катя", "Ира", "Коля", "Жора", "Игорь", "Гога" };
const int COUNT_NAMES = 7;

int** generateCardsSet() {


    int** arr = new int* [52] {};
    for (int value = 2, index = 0; value < 15; value++) {
        for (int suit = 3; suit < 7; suit++) {
            arr[index++] = new int[2] {value, suit};
        }
    }
    return arr;
}

void shuffleCardSet(int** arr) {
    int size = _msize(arr) / sizeof(arr[0]);
    for (int i = 0; i < 52; i++) {
        swap(arr[i], arr[random(0, size - 1)]);
    }
}

int* createCash(int countPlayer, int countMoney) {
    int* cash = new int[countPlayer];
    for (int i = 0; i < countPlayer; i++) {
        cash[i] = countMoney;
    }
    return cash;
}

void show(int** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);

    for (int i = 0; i < size1; i++) {
        if (arr[i][0] == 11) {
            cout << "J" << char(arr[i][1]) << " ";
        }
        else if (arr[i][0] == 12) {
            cout << "Q" << char(arr[i][1]) << " ";
        }
        else if (arr[i][0] == 13) {
            cout << "K" << char(arr[i][1]) << " ";
        }
        else if (arr[i][0] == 14) {
            cout << "A" << char(arr[i][1]) << " ";
        }
        else {
            cout << arr[i][0] << char(arr[i][1]) << " ";
        }
    }
}

string* createPlayers(int count) {
    if (count > 5 || count < 1) {
        cout << "недостаточное кол-во игроков" << endl;
        return nullptr;
    }
    else {
        string* arr = new string[count];
        for (int i = 0, flag; i < count; i++) {
            arr[i] = NAMES[random(0, COUNT_NAMES - 1)];
            flag = false;
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) i--;
        }
        return arr;
    }

}

void showPlayers(string*& players, int* cash, int count) {
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << players[i] << "\t" << cash[i] << endl;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int** mainSet = generateCardsSet();
    shuffleCardSet(mainSet);
    show(mainSet);
    int playersCount = 5;
    int* cash = createCash(playersCount, 1000);
    string* playersName = createPlayers(playersCount);
    showPlayers(playersName, cash, playersCount);

}
