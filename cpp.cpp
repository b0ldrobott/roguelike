#include <iostream>
#include <Windows.h>
using namespace std;

const int n = 20;
char map[n][n + 1] =
{
"####################",
"# # ^ #Y  ###Ma ^^#",
"# ^ M  ##M#######^##",
"#####M  #^     M#  #",
"#  ^   #MM M#M  ^^#",
"#  ##^ #^  ^#####  #",
"#M  ^^#M #MY^ ^## M#",
"# ^# M#^ ###^   #^M#",
"# ^# ^M M### # M#  #",
"#  #Ma#  MYM # ^#M^#",
"# ^  Ma# ###^#M^#  #",
"#^###### ###^#^^^  #",
"#^## M ^  ^ ^ ###  #",
"#^## ^^##M#a# ##  ##",
"#^## ^#^^Y#######^^#",
"#^   ## ###M #   ^^#",
"# ###aM^ ^^^^  # ###",
"# ########### ^#  ##",
"#             ^#M aM",
"####################",
};

int nowY = 1;
int nowX = 1;
int hp = 100;

void print() {
	system("cls");
	int y, x;
	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++) {
			if (y == nowY && x == nowX) {
				cout << "☆";
			}
			else if (map[y][x] == ' ') {
				cout << "  ";
			}
			else if (map[y][x] == '^') {
				cout << "▲";
			}
			else if (map[y][x] == 'Y') {
				cout << "Y";
			}
			else if (map[y][x] == 'M') {
				cout << "Ψ";
			}
			else if (map[y][x] == '#') {
				cout << "▨";
			}
			else if (map[y][x] == 'a') {
				cout << "♬";
			}

		}
		cout << "\n";
	}

	cout << "\n";
	cout << "HP: " << hp;
}

int main()
{
	system("color 0f");
	system("mode con lines=25 cols=45");

	print();

	while (1) // infinite loop
	{
		if (GetAsyncKeyState(VK_UP) & 0x8001) {
			if (map[nowY - 1][nowX] != '#') {
				nowY--;
			}
			if (map[nowY][nowX] == '^') {
					hp -= 10;
				}
			print();
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
			if (map[nowY + 1][nowX] != '#') {
				nowY++;
			}
			if (map[nowY][nowX] == '^') {
				hp = hp - 10;
			}
			print();
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
			if (map[nowY][nowX - 1] != '#') {
				nowX--;
			}
			if (map[nowY][nowX] == '^') {
				hp = hp - 10;
			}
			print();
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
			if (map[nowY][nowX + 1] != '#') {
				nowX++;
			}
			if (map[nowY][nowX] == '^') {
				hp = hp - 10;
			}
			print();
		}
		Sleep(150);

		if (map[nowY][nowX] == 'Y') {
			print();
			for (int i = 0; i < 5; i++) {
				Sleep(200);
				system("color c4");
				Sleep(200);
				system("color 3f");
				Sleep(200);
			}
			system("cls");
			Sleep(400);
			cout << "\n\n\n\n\n WIN!" << " " << hp << "\n\n\n\n\n";
			Sleep(500);
			break;
		}

		if (map[nowY][nowX] == 'M' || hp == 0) {
			print();
			for (int i = 0; i < 5; i++) {
				Sleep(200);
				system("color c4");
				Sleep(200);
				system("color 3f");
				Sleep(200);
			}
			system("cls");
			Sleep(400);
			cout << "\n\n\n\n\n GAME OVER!\n\n\n\n\n";
			Sleep(500);
			break;
		}

		if (map[nowY][nowX] == 'a') {
			print();
			Sleep(200);
			hp = 100;
			for (int i = 0; i < 3; i++) {
				system("color 2f");
				Sleep(200);
				system("color 6f");
				Sleep(200);
			}
			map[nowY][nowX] = ' ';
			print();
			system("color 0f");

		}

	}
	return 0;
}

