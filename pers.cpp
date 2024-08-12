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
	mpIterAnim = animFrames.begin();
	currentStayFrame = currentMoveFrame = currentJumpFrame = 0;
	lst = lright;
};

void Entity::setFrames(const pVir &stayFrames, const pVir &goFrames, const pVir &jumpFrames)
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
			if(stateMove == right)
			{
				if(lst != lright)
				{
					this->spriteEntity.setTexture(texture);
					currentMoveFrame = 0;
				}
				lst = lright;
				if(clAnim.getElapsedTime() >= milliseconds(70))
				{
					clAnim.restart();
					currentMoveFrame++;
					if(currentMoveFrame >= ((mpIterAnim + go)->first).size()) currentMoveFrame = 0;
					this->spriteEntity.setTextureRect((mpIterAnim + go)->first[currentMoveFrame]);
				}
			}
			else if(statesMove == left)
			{
				if(lst != lleft)
				{
					this->spriteEntity.setTexture(textureRev);
					currentMoveFrame = 0;
				}
				lst = lleft;
				if(clAnim.getElapsedTime() >= milliseconds(70))
				{
					clAnim.restart();
					currentMoveFrame++;
					if(currentMoveFrame >= ((mpIterAnim + go)->second).size()) currentMoveFrame = 0;
					this->spriteEntity.setTextureRect((mpIterAnim + go)->second[currentMoveFrame]);
				}
			}
			break;
		case jump:
			switch(lst)
			{
			case lright:
				this->spriteEntity.setTexture(texture);
				
				if(stateJump == up)
				{	if(clAnim.getElapsedTime() > milliseconds(70))
					{
						clAnim.restart();
						currentJumpFrame++;
						if(currentJumpFrame >= ((mpIterAnim + jump)->first).size()) currentJumpFrame = 0;
						this->spriteEntity.setTextureRect((mpIterAnim + jump)->first[currentJumpFrame]);
					}
				}
				else if(stateJump == down)
				{
					if(clAnim.getElapsedTime() > milliseconds(70))
					{
						clAnim.restart();
						currentJumpFrame--;
						if(currentJumpFrame < 0) currentJumpFrame = ((mpIterAnim + jump)->first).size() - 1;
						this->spriteEntity.setTextureRect((mpIterAnim + jump)->first[currentJumpFrame]);
					}
				}
			case lleft:
				this->spriteEntity.setTexture(textureRev);
				break;
			}
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















