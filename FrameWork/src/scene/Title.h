#pragma once
#include "Scene.h"
class Title : public Scene
{
public:
	Title();
	SceneType update();
	void draw();
};