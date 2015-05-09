#include "GameObject.h"
#include "ObjectTask.h"

GameObject::GameObject(ObjectTask& task):
task(task)
{

}

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