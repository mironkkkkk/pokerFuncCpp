#include <iostream>
#define random(a,b) a + rand()% b + 1 - a
using namespace std;

int** generateCardsSet() {


    int** arr = new int* [52] {};
    for (int value = 2, index = 0; value < 15; value++) {
        for (int suit = 3; suit < 7; suit++) {
            arr[index++] = new int[2]{value, suit};
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

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int** mainSet = generateCardsSet();
    shuffleCardSet(mainSet);
    show(mainSet);
    // todo 
    
}
