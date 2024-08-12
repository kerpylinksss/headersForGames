#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Entity
{
private:
	float x, y;
	float health, speed, stamine;
	const float gravity = 0.0098f;
	string File;
	string FileRev; // for reversed animation
	Texture texture;
	Texture textureRev;
	Sprite spriteEntity;
	virtual void move() = 0;
protected:
	Entity(float h, float speed, float stamine, string File){};
	enum statesOfPers = {stay, right, left, jump};
	enum statesofJump = {no, down, up};
public:
	void Spawn(float x, float y);
	void Update(const float &time);
};



class Player : public Entity
{
private:
public:
};



class Bot : public Entity
{
private:
protected:
};



class Enemy : public Bot
{
private:
public:
};



class Friend : public Bot
{
private:
public:
};
