#pragma once
class Player
{
	int pos_x, pos_y;
	char player_model='O';
public:
	void setPos(int, int);
	void getPos(int&, int&);
	bool canDown(char a[][30]);
	bool canUp(char a[][30]);
	bool canRight(char a[][30]);
};

