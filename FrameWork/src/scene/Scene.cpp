#include "Scene.h"


void Scene::addObject(const std::string& name, const std::shared_ptr<GameObject>& object)
{
	object_task.add(name, object);
}
void Scene::updateObject()
{
	object_task.update();
	object_task.erase();
}