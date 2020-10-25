#include<iostream>
#include<cstdlib>
#include<Windows.h>
#include<time.h>
#include"Player.h"
#include<conio.h>
char full_scene[6][30];
char buffer_scene[6][5];
int index_in_buffer_scene = 0;
bool no_terrain = true;
void generateTerrain() {
	srand((unsigned int)time(NULL));
	char scene1[3][6][5] = { { {' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{'-','-','-','-','-'} },
							{ {' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ','T','T',' '},
							{'_','_','T','T','_'} },
							{ {' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ','X','X'},
							{' ','T',' ',' ',' '},
							{'-','T','-','-','-'} } };
	int r = rand() % 3;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 5; j++)
			buffer_scene[i][j] = scene1[r][i][j];
	index_in_buffer_scene = 0;
	no_terrain = false;
}

void addTerrain() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 30 - 1; j++) {
			full_scene[i][j] = full_scene[i][j + 1];
		}
		full_scene[i][29] = buffer_scene[i][index_in_buffer_scene];
	}
	index_in_buffer_scene += 1;
	if (index_in_buffer_scene > 4) {
		index_in_buffer_scene = 0;
		no_terrain = true;
	}
}
	void display(char a[6][30]);

	void Display(int x, int y); 

int main() {
	std::cout<<"Hello"<<std::endl;
	std::cout << std::flush;
	Sleep(1000);
	for (int i = 0; i < 6; i++) {
		generateTerrain();
		//std::cout <<"Generated Terrain: "<<i<<std::endl;
		//std::cout << std::flush;
		//Sleep(1000);
		for (int j = 0; j < 5; j++) {
			addTerrain();
		}
		//std::cout << "Added Terrain: " << i << std::endl;
		//std::cout << std::flush;
		//display();
		//Sleep(4000);
	}
	//std::cout << "Successfully finished building\n"<<std::endl;
	//display();
	//Sleep(4000);
	int starting_pos=0;
	for (int i = 0; i < 6; i++) {
		if (full_scene[i][0] == ' ') {
			starting_pos = i;
			break;
		}
	}
	Player player1;
	player1.setPos(starting_pos, 0);
	int x, y;
	while (1) {
		player1.getPos(x, y);
		Display(x, y);
		std::cout << std::flush;
		Sleep(20);
		if (player1.canDown(full_scene)) { player1.setPos(x + 1, y); system("cls"); continue; }
		char input = _getch();
		if (input == 'w' && player1.canUp(full_scene)) { 
			player1.setPos(x - 1, y + 2); 
		}
		if (input == 'd' && player1.canRight(full_scene)) {
			if (y < 2) player1.setPos(x, y + 1);
			if (no_terrain) generateTerrain();
			addTerrain();
		}
		else if (input == 'a') {
			unsigned int temp = (y == 0) ? 0 : y - 1;
			player1.setPos(x, temp);
		}
		else if (input == 's') break;
		system("cls");
	}
	return 0;
}

void display(char a[6][30]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 30; j++) {
			std::cout << a[i][j];
		}
		std::cout << std::endl;
	}
}

void Display(int x, int y) {
	char scene_with_player[6][30];
	std::copy(&full_scene[0][0], &full_scene[0][0] + 180, &scene_with_player[0][0]);
	scene_with_player[x][y] = 'O';
	display(scene_with_player);
}