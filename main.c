//игра в жизнь
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>// для bool

#define HEIGHT 25
#define WIDTH 25
#define LIFE_YES 1
#define LIFE_NO 0

typedef int TableType[HEIGHT][WIDTH];

void printTable(TableType table)
{
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++) 
		{
			if (table[i][j] == LIFE_YES)
				printf("X");
			else
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
}
void clearTable(TableType table) {

    for (size_t i = 0; i < HEIGHT; i++) 
	{
        for (size_t j = 0; j < WIDTH; j++) 
		{
            table[i][j] = LIFE_NO;
        }
    }
}

int getNeighbourValue(TableType table, int row, int col) {
	if (row < 0 || row >= HEIGHT
		|| col < 0 || col >= WIDTH
		|| table[row][col] != LIFE_YES)
	{
		return 0;
	}
	else {
		return 1;
	}
}
//если мы вышли за пределы игровой зоны или клетка не жива возвращаем 0
//иначе 1

int getNeighborCount(TableType table, int row, int col) {
	int neighbour = 0;

	neighbour += getNeighbourValue(table, row - 1, col - 1);
	neighbour += getNeighbourValue(table, row - 1, col);
	neighbour += getNeighbourValue(table, row - 1, col + 1);
	neighbour += getNeighbourValue(table, row, col - 1);
	neighbour += getNeighbourValue(table, row, col + 1);
	neighbour += getNeighbourValue(table, row + 1, col - 1);
	neighbour += getNeighbourValue(table, row + 1, col);
	neighbour += getNeighbourValue(table, row + 1, col + 1);

	return neighbour;
}
//Функция чекает все соседние координаты на наличие соседей

void checkRules(TableType tableA) {
	TableType tableB;
	int neighbour;

	for (size_t i = 0; i < HEIGHT; i++) {
		for (size_t j = 0; j < WIDTH; j++) {
			neighbour = getNeighborCount(tableA, i, j);
			if (neighbour == 3) {
				tableB[i][j] = LIFE_YES;
			}
			else if (neighbour == 2 && tableA[i][j] == LIFE_YES) {
				tableB[i][j] = LIFE_YES;
			}
			else {
				tableB[i][j] = LIFE_NO;
			}
		}
	}
	for (size_t i = 0; i < HEIGHT; i++) {
		for (size_t j = 0; j < WIDTH; j++) {
			tableA[i][j] = tableB[i][j];
		}
	}
}
//в этой функции проверяется выполнение правил игры

void loaddata(TableType table) {

	//glider
	table[10][4] = LIFE_YES;
	table[11][5] = LIFE_YES;
	table[12][5] = LIFE_YES;
	table[12][4] = LIFE_YES;
	table[12][3] = LIFE_YES;
}
//Загружаем начальные данные


int main(int argc, char* argv[])
{
	TableType table;
	int generation = 0;
	int i;
	clearTable(table);
	loaddata(table);
	printTable(table);
	for (generation = 0; generation < 100000; generation++)
	{
		checkRules(table);
		printTable(table);
		printf("Generation %d\n", generation);
		Sleep(200);
	}
	return 0;
}
