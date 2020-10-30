#include<iostream>
#include<cstdlib>
#include<Windows.h>
#include<time.h>
char full_scene[6][10];
char buffer_scene[6][5];
int index_in_buffer_scene = 0;
void generateTerrain() {
	srand((unsigned int)time(NULL));
	char scene1[3][6][5] = { { {' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{'-','-','-','-','T'} },
							{ {' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{'_','-','-','-','T'},
							{' ',' ',' ',' ',' '} },
							{ {'X','X','X','X','X'},
							{' ','X','X','X','X'},
							{' ',' ','X','X','X'},
							{' ',' ','X','X','X'},
							{' ',' ',' ',' ',' '},
							{'-','-','-','T','-'} } };
	int r = rand() % 3;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 5; j++)
			buffer_scene[i][j] = scene1[r][i][j];
	index_in_buffer_scene = 0;
}

void addTerrain() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10 - 1; j++) {
			full_scene[i][j] = full_scene[i][j + 1];
		}
		full_scene[i][9] = buffer_scene[i][index_in_buffer_scene];
	}
	index_in_buffer_scene += 1;
}

void display() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << full_scene[i][j];
		}
		std::cout << std::endl;
	}
}
int main() {
	std::cout<<"Hello"<<std::endl;
	std::cout << std::flush;
	Sleep(1000);
	for (int i = 0; i < 2; i++) {
		generateTerrain();
		std::cout <<"Generated Terrain: "<<i<<std::endl;
		std::cout << std::flush;
		Sleep(1000);
		for (int j = 0; j < 5; j++) {
			addTerrain();
		}
		std::cout << "Added Terrain: " << i << std::endl;
		std::cout << std::flush;
		display();
		Sleep(4000);
	}
	std::cout << "Successfully finished building"<<std::endl;
	display();
	Sleep(4000);
	return 0;
}
