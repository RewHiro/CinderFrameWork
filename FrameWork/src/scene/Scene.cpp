#include "Scene.h"
#include "input\Key.h"
#include "input\Mouse.h"
#include "input\UtilityGamePad.h"

using namespace input;

Scene::~Scene()
{
}

Scene::PlayerNum& Scene::playerNum()
{
	static PlayerNum player_num = PlayerNum::ONE;
	return player_num;
}

void Scene::addObject(const std::string& name, const std::shared_ptr<GameObject>& object)
{
	ObjectTask::getInstance().add(name, object);
}

void Scene::updateObject()
{
	ObjectTask::getInstance().update();
	ObjectTask::getInstance().erase();
}