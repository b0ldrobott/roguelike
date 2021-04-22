#include <iostream>
#include <Windows.h>
using namespace std;

const int n = 5;
char map[n][n + 1] = {
	"#####",
	"#   #",
	"# Y #",
	"#M  #",
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
			if (map[nowY - 1][nowX] != '#') {
				nowY--;
			}

		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
			if (map[nowY + 1][nowX] != '#') {
				nowY++;
			}
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
			if (map[nowY][nowX - 1] != '#') {
				nowX--;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
			if (map[nowY][nowX + 1] != '#') {
				nowX++;
			}
		}
		Sleep(100);

		if (map[nowY][nowX] == 'Y') {
			print();
			for (int i = 0; i < 5; i++) {
				Sleep(200);
				system("color c4");
				Sleep(200);
				system("color 3f");
				Sleep(300);
			}
			system("cls");
			Sleep(500);
			cout << "\n\n\n\n\n WIN!\n\n\n\n\n";
			Sleep(500);
			break;
		}

		if (map[nowY][nowX] == 'M') {
			print();
			for (int i = 0; i < 5; i++) {
				Sleep(200);
				system("color c4");
				Sleep(200);
				system("color 3f");
				Sleep(300);
			}
			system("cls");
			Sleep(500);
			cout << "\n\n\n\n\n GAME OVER!\n\n\n\n\n";
			Sleep(500);
			break;
		}
	}
	return 0;
}