#pragma once
#include "cinder/Vector.h"
#include "cinder\Quaternion.h"
#include "boost\noncopyable.hpp"
#include <unordered_map>

class ObjectTask;
class GameObject;

using OBJECT_MAP_ITR = std::unordered_multimap < std::string, std::shared_ptr<GameObject> >::iterator;

class GameObject : public std::enable_shared_from_this<GameObject> , private boost::noncopyable
{
	bool is_delete = false;
	bool is_active = true;
	std::string name;
	ObjectTask& task;
protected:
	ci::Vec3f pos;
	ci::Vec3f scale;
	ci::Quatf rotate;
	void addObject(const std::string& name,const std::shared_ptr<GameObject>& object);
	std::shared_ptr<GameObject>& findObject(const std::string& name);
	std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& findsObject(const std::string& name);
public:
	GameObject(ObjectTask& task);
	virtual ~GameObject() = 0{}
	virtual void update(){}
	virtual void draw(){}
	bool isDelete()const{ return is_delete; }
	std::string getName()const{ return name; }
	void destory();
};

