#pragma once
#include "Bullet.h"
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player
{
private:

	Sprite playerSprite;
	Texture *playerTexture;
	Vector2f velocity;

	Texture *bulletTexture;
	vector<Bullet>bullets;
	float movementSpeed;

	Vector2f PlayerPos;
	Vector2f MousePos;
	Vector2f aimDir;
	Vector2f aimDirNorm;
	float shootTimer;
	float shootTimerMax;


public:

	Player(Texture *texture,Texture *bulletTexture);
	virtual ~Player();

	//Bullet
	inline vector<Bullet>& getBullets() { return this->bullets; }
	//Function
	void shoot(RenderWindow& target);
	void movement(float deltaTime);
	void update(float deltaTime);
	void render(RenderWindow& target);
};

