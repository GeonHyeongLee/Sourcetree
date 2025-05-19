#include<stdio.h>
#include<windows.h>

int block[4][4] = {
	{1,1,0,0},
	{0,1,1,0},
	{0,0,0,0},
	{0,0,0,0},
};

void gotoxy(int x, int y);

void setcolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

int main(void) {
	setcolor(3, 0);
	//gotoxy(2, 2);
	//printf("□□□□");//한글 ㅁ을 누르고 한자키를 누르면 2번째 페이지에 있음

	//gotoxy(2, 2);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[i][j] == 1) {
				printf("□");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	getchar();
	return 0;
}

void gotoxy(int x, int y) {
	//COORD pos = { x,y };
	COORD pos = { x * 2,y };//여기만 바뀜
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
