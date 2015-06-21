#include "ObjectTask.h"

ObjectTask& ObjectTask::getInstance()
{
	static ObjectTask instance;
	return instance;
}

void ObjectTask::add(const std::string& name, const std::shared_ptr<GameObject>& object)
{
	std::string name__ = typeid(*object.get()).name();
	auto testu = name__.substr(6);
	object->name = name;
	list.emplace_back(object);
	map.emplace(name, object);
}

void ObjectTask::update()const
{
	for(const auto& object : list)
	{
		if(object->getUpdateState() == GameObject::UpdateState::UPDATE)
		{
			object->update();
		}
		else
		{
			object->start();
			object->update_state = GameObject::UpdateState::UPDATE;
		}
	}
}

void ObjectTask::draw()const
{
	for (const auto& object : list)
	{
		object->draw();
	}
}

void ObjectTask::clear()
{
	map.clear();
	list.clear();
	for (size_t i = 0; i < delete_list.size(); ++i)
	{
		delete_list.pop();
	}
}

void ObjectTask::erase()
{
	list.remove_if([](const std::weak_ptr<GameObject>& object){return object.lock()->isDelete(); });

	while (!delete_list.empty())
	{
		const auto& objects = map.equal_range(delete_list.top()->getName());
		auto itr = objects.first;
		while (itr != objects.second)
		{
			if (itr->second->isDelete())
			{
				itr = map.erase(itr);
			}
			else ++itr;
		}
		delete_list.pop();
	}
}

void ObjectTask::addDelete(const std::shared_ptr<GameObject>& object)
{
	delete_list.emplace(object);
}