#pragma once

/*
генерация колоды
*/
int** generateCardsSet();
/*
отображение колоды
*/
void show(int** arr);
/*
перемешивание колоды
*/
void shuffleCardSet(int** arr);
/*
создание игроков
*/
string* createPlayers(int count);
/*
стартовая раздача денег
*/
int* createCash(int countPlayer, int countMoney);
/*
отображение игроков на поле
*/
void showPlayers(string*& players, int* cash, int count);



