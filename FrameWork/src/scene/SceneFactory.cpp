#include "SceneFactory.h"
#include "Scene.h"
#include "Title.h"
#include "Stage.h"
#include <functional>
#include <unordered_map>

std::unique_ptr<Scene> SceneFactory::create(const SceneType type)const
{
	static std::unordered_map<SceneType,std::function<std::unique_ptr<Scene>()>> scene_list = 
	{
		{ SceneType::TITLE, []{return std::make_unique<Title>(); } },
		{ SceneType::STAGE, []{return std::make_unique<Stage>(); } },
	};

	return std::move((scene_list.find(type)->second)());
}