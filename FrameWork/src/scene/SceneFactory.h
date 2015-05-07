#pragma once
#include "boost\noncopyable.hpp"
#include <memory>
class Scene;
enum class SceneType;

class SceneFactory : private boost::noncopyable
{
	SceneFactory() = default;
public:
	inline static SceneFactory& getInstance()
	{
		static SceneFactory instance;
		return instance;
	}
	std::unique_ptr<Scene> create(const SceneType type)const;
};