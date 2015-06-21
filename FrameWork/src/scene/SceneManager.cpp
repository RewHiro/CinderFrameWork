#include "SceneManager.h"
#include "SceneFactory.h"
#include "object\ObjectTask.h"
#include "MainCamera.h"
#include "input\Mouse.h"
#include "input\Key.h"
#include "input\UtilityGamePad.h"

using namespace input;

SceneManager::SceneManager():
type(SceneType::TITLE),
scene(SceneFactory::getInstance().create(type))
{
	scene->setSceneType(type);
	ObjectTask::getInstance();
	MainCamera::getInstance();
}

void SceneManager::resize()
{
	scene->resize();
}

void SceneManager::update()
{
	const auto tmp_scene_type = scene->update();
	if (type == tmp_scene_type)return;
	ObjectTask::getInstance().clear();
	Mouse::getInstance().clear();
	Key::getInstance().clear();
	GamePad::getInstance().clear();
	scene = SceneFactory::getInstance().create(tmp_scene_type);
	scene->setSceneType(tmp_scene_type);
	type = tmp_scene_type;

}

void SceneManager::draw()
{
	scene->draw();
}
