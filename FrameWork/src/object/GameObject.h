#pragma once
#include "cinder\Vector.h"
#include "cinder\Quaternion.h"
#include "cinder\Color.h"
#include "boost\noncopyable.hpp"
#include <unordered_map>

class ObjectTask;
class GameObject;

using OBJECT_MAP_ITR = std::unordered_multimap < std::string, std::shared_ptr<GameObject> >::iterator;

class GameObject : public std::enable_shared_from_this<GameObject> , private boost::noncopyable
{


	bool is_delete = false;
	bool is_active = true;


protected:
	ci::Vec3f pos;
	ci::Vec3f scale;
	ci::Quatf rotate;
	ci::ColorA color;


	std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& findsObject(const std::string& name);

public:
	std::string name;
	enum class UpdateState
	{
		START,
		UPDATE,
	};
	GameObject();
	virtual ~GameObject() = 0{}
	virtual void start(){}
	virtual void update(){}
	virtual void draw(){}
	bool isDelete()const{ return is_delete; }
	std::string getName()const{ return name; }
	ci::Vec3f getPos()const{ return pos; }
	ci::Vec3f getScale()const{ return scale; }
	ci::Quatf getRotate()const{ return rotate; }
	ci::ColorA getColor()const{ return color; }
	UpdateState getUpdateState()const{ return update_state; }
	void destory();
	static void addObject(const std::string& name, const std::shared_ptr<GameObject>& object);
	static std::shared_ptr<GameObject>& findObject(const std::string& name);

	template <class Type>
	static std::shared_ptr<Type> getObjectType(const std::string& name)
	{
		return std::dynamic_pointer_cast<Type>(findObject(name));
	}

	UpdateState update_state = UpdateState::START;
private:
};

