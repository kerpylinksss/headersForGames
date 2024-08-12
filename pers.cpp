#include "pers.h"


//entities:
Entity::Entity(float h, float sp, float st, string f, string fr)
{
	health = h;
	speed = sp;
	stamine = st;
	texture.loadFromFile(f);
	textureRev.loadFromFile(fr);
	alive = true;
	onGround = true;
	isMove = false;
};

void Entity::setFrames(const pir &stayFrames, const pir &goFrames, const pir &jumpFrames)
{
	this->animFrames.insert(stayFrames);
	this->animFrames.insert(goFrames);
	this->animFrames.insert(jumpFrames);
};

void Entity::Spawn(float x, float y, IntRect &startFrame, bool rev = false)
{
	
	if(!rev)
	{
		this->spriteEntity.setTexture(texture);
	}
	else
	{
		this->spriteEntity.setTexture(textureRev);
	}
	this->spriteEntity.setTextureRect(startFrame);
	this->x = x;
	this->y = y;
	this->dx = 0;
	this->dy = 0;
	this->spriteEntity.setPosition(Vector2f(x, y));
};

void Entity::Update(const float &time)
{
	move();
	if(isMove)
	{
		switch(state)
		{
		case go:
			if(stateMove == right){}
			else if(statesMove == left){}
			break;
		case jump:
			if(stateJump == up){}
			else if(stateJump == down){}
			break;
		default:
			break;
		}
	}
	else
	{
		switch(lst)
		{
			case lright:
				break;
			case lleft:
				break;
			default:
				break;
		}
	}
	
	x += dx * time;
	y += dy * time;
	spriteEntity.setPosition(Vector2f(x, y));
};















