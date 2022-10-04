#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 1.f;
}

void Player::initTexture()
{

}

void Player::initSprite()
{
	this->shape.setSize(Vector2f(50.f,50.f));
	this->shape.setFillColor(Color::Green);
	this->shape.setPosition(Vector2f(800,450));
}

Player::Player()
{
	this->initVariables();
	this->initSprite();
}

Player::~Player()
{
}

void Player::move(const float dx,const float dy)
{
	this->shape.move(this->movementSpeed * dx,this->movementSpeed * dy);
}

void Player::render(RenderTarget& target)
{
	target.draw(this->shape);
}


