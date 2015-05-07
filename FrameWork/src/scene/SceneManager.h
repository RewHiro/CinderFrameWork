#pragma once
#include "Scene.h"
#include "boost\noncopyable.hpp"
#include <memory>

class SceneManager : private boost::noncopyable
{
	SceneType type;
	std::unique_ptr<Scene>scene;
public:
	SceneManager();
	void update();
	void draw();
};