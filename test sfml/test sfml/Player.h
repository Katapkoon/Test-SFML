#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Player
{
private:
	RectangleShape shape;
	Texture texture;

	float movementSpeed;

	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	~Player();

	void move(float dx,float dy);
	void render(RenderTarget& target);

};

