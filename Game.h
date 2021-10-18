#pragma once
#include<iostream>
#include<vector>
#include"Player.h"
#include"Enemy.h"
#include<ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;
/*
	Class that acts the game engine
*/

class Game
{
private:
	//Variable

	//Window
	//vector<Background> backgrounds;
	RenderWindow* window;
	VideoMode videoMode;
	RectangleShape bg;
	Texture bgTexture;
	Sprite bgSprite;
	Event ev;

	//Bullet
	

	//Player
	Texture playerTexture;
	vector<Player> player;

	//Enemies
	float spawmTimer;
	float spawmTimerMax;
	vector<Enemy> enemies;
	Texture enemyTexture;
	Texture bulletTexture;
	int level;
	int enemyMax;

	//Enemy* enemy;


	//Private function
	void initVariables();
	void initWindow();

	void initPlayer();
	void initEnemies();
	void initBullet();

public:
	//Constructor/Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;


	//Function 
	void pollEvents();
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void update(float deltaTime);
	void render();
};
