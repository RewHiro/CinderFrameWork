#pragma once
#include "boost\noncopyable.hpp"
#include "object\ObjectTask.h"

enum class SceneType
{
	TITLE,
	STAGE,
};

class Scene : private boost::noncopyable
{
	ObjectTask object_task;
protected:
	SceneType type;
	void addObject(const std::string& name, const std::shared_ptr<GameObject>& object);
	void updateObject();
	void drawObject(){ object_task.draw(); }

public:
	Scene() = default;
	virtual ~Scene() = 0{}
	virtual SceneType update() = 0;
	virtual void draw() = 0;
	void setSceneType(const SceneType type){ this->type = type; }
};