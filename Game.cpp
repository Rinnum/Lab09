#include "Game.h"

//Private function
void Game::initVariables()
{
	this->window = nullptr;
	this->level = 1;
	this->enemyMax = 10;

}

void Game::initWindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new RenderWindow(this->videoMode, "Don't Touch My Town", Style::Titlebar | Style::Close);
	this->bgTexture.loadFromFile("character/bg.png");
	this->bgSprite.setTexture(bgTexture);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(true);
}

void Game::initPlayer()
{
	this->playerTexture.loadFromFile("character/player1.png");
	this->bulletTexture.loadFromFile("character/bullet.png");
	this->player.push_back(Player(&this->playerTexture, &this->bulletTexture));
}

void Game::initEnemies()
{
	this->enemyTexture.loadFromFile("character/enemy1.png");
	this->spawmTimerMax = 50.f;
	this->spawmTimer = this->spawmTimerMax;
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initEnemies();

}

Game::~Game()
{

}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}


//Function

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		if (ev.Event::type == Event::Closed)
			this->window->close();
		if (ev.Event::KeyPressed && ev.Event::key.code == Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{

}


void Game::updateBullets()
{

}

void Game::updateEnemies()
{
	if (this->spawmTimer >= this->spawmTimerMax)
	{
		this->enemies.push_back(Enemy(rand() % this->window->getSize().x - 20.f, -100.f, &this->enemyTexture));
		this->spawmTimer = 0.f;
	}
	else
	{
		this->spawmTimer += 0.5f;
	}
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].update();

		//Remove enemy at bottom of the screen
		if (this->enemies[i].getPos().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}


void Game::update(float deltaTime)
{
	this->pollEvents();
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].update(deltaTime);
		for (int k = 0; k < player[i].getBullets().size(); k++)
		{
			player[i].getBullets()[k].update(deltaTime);
		}
	}	this->updateInput();
	this->updateBullets();
	this->updateEnemies();
	// cout << deltaTime << endl;
}




void Game::render()
{
	/*
	   @return void

		-clear old frame
		-Render new object
		-display frame in Wiondow
		Render the game objects.
	*/

	this->window->clear();

	//Draw Game Objects
	this->window->draw(this->bgSprite);
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].render(*this->window);
	}

	for (size_t i = 0; i < this->enemies.size(); i++) {
		this->enemies.at(i).render(this->window);
	}
	this->window->display();
}
