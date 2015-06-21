#pragma once
#include "Scene.h"
#include "cinder\gl\Light.h"
#include "Camera.h"
#include "cinder\gl\TextureFont.h"
#include "cinder\app\app.h"
#include <memory>

class Title : public Scene
{
	ci::CameraOrtho camera;
	std::unique_ptr<ci::gl::Light> light;
	ci::Font font;
	ci::Font font01;
	int count = 0;
	int interval = 0;
public:
	Title();
	SceneType update();
	void draw();
	void resize();
};