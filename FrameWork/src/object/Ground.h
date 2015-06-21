#pragma once
#include "object\GameObject.h"
#include "cinder\gl\gl.h"
#include "cinder\app\App.h"
#include "cinder\ImageIo.h"
#include "cinder\gl\Texture.h"

class Ground : public GameObject
{
	ci::gl::Texture texture;
public:
	Ground();
	void update();
	void draw();
};