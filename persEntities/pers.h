#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>

using namespace std;
using namespace sf;

typedef pair<IntRect, IntRect> pir;

class Entity
{
private:
	float x, y;
	float dx, dy;
	float health, speed, stamine;
	const float gravity = 0.0098f;
	string File;
	string FileRev; // for reversed animation
	Texture texture;
	map<vector<IntRect>, vector<IntRect>> animFrames;
	//iter->first - usual frames, iter->second - reversed frames
	Texture textureRev;
	Sprite spriteEntity;
	virtual void move() = 0;
	bool alive, isMove, onGround;
	Clock clAnim;
protected:
	Entity(float h, float sp, float st, string f, string fr){};
	enum statesOfPers = {stay, go, jump};
	statesOfPers state;
	
	enum statesOfJump = {no, down, up};
	statesOfJump stateJump;
	
	enum statesOfMove = {right, left};
	statesOfMove stateMove;
	
	enum lastStateMove = {lright, lleft};
	lastStateMove lst;
public:
	void Spawn(float x, float y, IntRect &startFrame);
	void Update(const float &time);
	setFrames(const pir &stayFrames, const pir &goFrames, const pir &jumpFrames);
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
