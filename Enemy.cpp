#include "Enemy.h"


void Enemy::initenemyTexture()
{
	//Load a Texture from file
}

void Enemy::initenemySprite()
{
	//Set texture sprit
	//this->enemySprite.setTexture(this->enemyTexture);
	//Resize the 
	this->enemySprite.setScale(0.05f, 0.05f);
}

void Enemy::initVariable()
{
	this->points = 0;
	this->enemySpawnTimer = 100.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;

	this->type   = 0;
	this->hpMax  = 10;
	this->hp     = 0;
	this->damage = 1;
}

Enemy::Enemy(float pos_x,float pos_y,Texture* enemyTexture)
{

	this->initenemyTexture();
	this->initenemySprite();
	this->enemySprite.setPosition(pos_x, pos_y);
	this->enemySprite.setTexture(*enemyTexture);
	this->initVariable();
}

Enemy::~Enemy()
{

}

//Accessor
const FloatRect Enemy::getBounds() const
{
	return this->enemySprite.getGlobalBounds();
}


//Function

void Enemy::update()
{
	this->enemySprite.move(0.f, 2.f);
}

void Enemy::render(RenderTarget* target)
{
	target->draw(this->enemySprite);
}

