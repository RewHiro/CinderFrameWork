#pragma once
#include "Scene.h"
class Stage : public Scene
{
public:
	Stage() = default;
	SceneType update();
	void draw();
};