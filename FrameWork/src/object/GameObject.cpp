#include "GameObject.h"
#include "ObjectTask.h"

GameObject::GameObject()
{

}
std::shared_ptr<GameObject>& GameObject::findObject(const std::string& name){ return ObjectTask::getInstance().find(name); }
std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& GameObject::findsObject(const std::string& name){ return ObjectTask::getInstance().finds(name); }
void GameObject::addObject(const std::string& name, const std::shared_ptr<GameObject>& object)
{
	object->name = name;
	ObjectTask::getInstance().add(name, object);
}

void GameObject::destory()
{
	is_delete = true;
	ObjectTask::getInstance().addDelete(shared_from_this());
}