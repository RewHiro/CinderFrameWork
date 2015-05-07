#pragma once
#include "boost\noncopyable.hpp"


enum class SceneType
{
	TITLE,
	STAGE,
};

class Scene : private boost::noncopyable
{
protected:
	SceneType type;
public:
	Scene() = default;
	virtual ~Scene() = 0{}
	virtual SceneType update() = 0;
	virtual void draw() = 0;
	void setSceneType(const SceneType type){ this->type = type; }
};