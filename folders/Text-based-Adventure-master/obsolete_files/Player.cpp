#include "Player.h"
void Player::getPos(int &n1, int &n2) {
	n1 = pos_x;
	n2 = pos_y;
}

void Player::setPos(int n1, int n2) {
	pos_x = n1;
	pos_y = n2;
}

bool Player::canDown(char a[][30]) {
	return a[pos_x+1][pos_y] == ' ';
}

bool Player::canUp(char a[][30]) {
	return a[pos_x - 1][pos_y] == ' ';
}

bool Player::canRight(char a[][30]) {
	return a[pos_x][pos_y + 1] == ' ';
}