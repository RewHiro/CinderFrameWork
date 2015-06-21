#pragma once
#include "GameObject.h"
#include "cinder\params\Params.h"
#include "cinder\gl\Texture.h"

class Background : public GameObject
{
	ci::gl::Texture texture;
	float size = 0.0f;
public:
	Background();
	void update();
	void draw();
};