#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
#include "./levels/level.h"

using namespace std;
using namespace sf;

typedef vector<IntRect> vir;
typedef pair<vir, vir> pVir;

class Entity
{
private:
	float x, y;
	float dx, dy;
	float health, speed;
	const float gravity = 0.0098f;
	string File;
	string FileRev; // for reversed animation
	Texture texture;
	map<pVir> animFrames;
	map<pVir>::iterator mpIterAnim;
	int currentStayFrame, currentMoveFrame, currentJumpFrame;
	//iter->first - usual frames, iter->second - reversed frames
	Texture textureRev;
	Sprite spriteEntity;
	void checkIfAlive();
	bool alive, isMove, onGround;
	Clock clAnim;
	void Jump(const float* const time);
	void interactionWithLevel(const Level* lev);
protected:
	Entity(float h, float sp, float st, string f, string fr){};
	enum statesOfPers = {stay, go, jump};
	statesOfPers state;
	
	enum statesOfJump = {no, up, down};
	statesOfJump stateJump;
	
	enum statesOfMove = {right, left};
	statesOfMove stateMove;
	
	enum lastStateMove = {lright, lleft};
	lastStateMove lst;
	
	virtual void move() = 0;
	virtual void checkForDamage(const Entity* const en);
	
	
public:
	void Spawn(float x, float y, IntRect &startFrame);
	void Update(const float &time);
	setFrames(const pVir &stayFrames, const pVir &goFrames, const pVir &jumpFrames);
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













