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
	SceneType type;
	void addObject(const std::string& name, const std::shared_ptr<GameObject>& object);
	void updateObject();
	void drawObject(){ ObjectTask::getInstance().draw(); }
	std::shared_ptr<GameObject>& findObject(const std::string& name){ return ObjectTask::getInstance().find(name); }
	enum class PlayerNum
	{
		ONE = 1,
		TWO,
		THREE,
		FOUR,
	};

public:
	static PlayerNum& playerNum();
	Scene() = default;
	virtual ~Scene();
	virtual SceneType update() = 0;
	virtual void draw() = 0;
	virtual void resize(){}
	void setSceneType(const SceneType type){ this->type = type; }
};