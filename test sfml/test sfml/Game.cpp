#include "Game.h"

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->player;
	delete this->window;
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->updatePollEvents();
		this->render();
	}
}

void Game::initWindow()
{
	this->window = new RenderWindow(VideoMode(1600, 900), "Circle Bounce!", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(165);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::updatePollEvents()
{
	Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	this->window->display();
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
}
