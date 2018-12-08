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

	////Seriallize/Deserialize
	virtual void write(ostream &f);
	virtual void read(istream &f);
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
void Game::print() {
	cout << "Platform: " << this->platform << endl;
}


//Binary file functions
void Game::write(ostream &f) {
	Media::write(f);
}

void Game::read(istream &f) {
	Media::read(f);

}
