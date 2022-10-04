#pragma once
#include "Player.h"
class Game
{
private:
	RenderWindow* window;

	Player* player;

public:
	Game();
	~Game();
	void run();
	void initWindow();
	void initPlayer();
	void updatePollEvents();
	void render();
	void updateInput();
	void update();
};

