#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(ObjectTask& task);
	void update();
	void draw();
};