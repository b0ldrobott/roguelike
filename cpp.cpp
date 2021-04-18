#include <iostream>
#include <Windows.h>
using namespace std;

const int n = 5;
char map[n][n + 1] = {
	"#####",
	"#   #",
	"#   #",
	"#   #",
	"#####"
};

int nowX = 1;
int nowY = 1;

void print() {
	system("cls");
	int y, x;
	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++) {
			if (y == nowY && x == nowX) {
				cout << "@";
			}
			else {
				cout << map[y][x];
			}

		}
		cout << "\n";
	}
}

int main()
{
	system("color 0f");
	system("mode con lines=25 cols=45");

	while (1) // infinite loop
	{
		print();

		if (GetAsyncKeyState(VK_UP) & 0x8001) {
			nowY--;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
			nowY++;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
			nowX--;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
			nowX++;
		}
		Sleep(100);
	}
	return 0;
}