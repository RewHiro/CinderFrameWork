#pragma once
#include "Scene.h"
class Title : public Scene
{
public:
	Title() = default;
	SceneType update();
	void draw();
};