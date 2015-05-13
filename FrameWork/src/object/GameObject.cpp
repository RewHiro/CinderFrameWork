#include "GameObject.h"
#include "ObjectTask.h"

GameObject::GameObject(ObjectTask& task):
task(task)
{

}
std::shared_ptr<GameObject>& GameObject::findObject(const std::string& name){ return task.find(name); }
std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& GameObject::findsObject(const std::string& name){ return task.finds(name); }
void GameObject::addObject(const std::string& name, const std::shared_ptr<GameObject>& object)
{
	object->name = name;
	task.add(name, object);
}

void GameObject::destory()
{
	is_delete = true;
	task.addDelete(shared_from_this());
}