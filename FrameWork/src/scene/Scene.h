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

protected:
	ObjectTask object_task;
	SceneType type;
	void addObject(const std::string& name, const std::shared_ptr<GameObject>& object);
	void updateObject();
	void drawObject(){ object_task.draw(); }
	std::shared_ptr<GameObject>& findObject(const std::string& name){ return object_task.find(name); }
public:
	Scene() = default;
	virtual ~Scene() = 0{}
	virtual SceneType update() = 0;
	virtual void draw() = 0;
	void setSceneType(const SceneType type){ this->type = type; }
};