#ifndef GAME_H
#define GAME_H




#pragma once
#include "Media.h"
class Game :public Media
{
private:
	string platform;
public:
	Game();
	~Game();
	string getPlatform();
	void setPlatform(string);
	virtual void print();
};
#endif // !GAME_H


Game::Game()
{
	iType = "Game";
}


Game::~Game()
{
}

string Game::getPlatform() { return this->platform; }
void Game::setPlatform(string platform) {this->platform = platform; }
void Game::print() {}
