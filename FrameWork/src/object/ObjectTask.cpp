#include "ObjectTask.h"

void ObjectTask::add(const std::string& name, const std::shared_ptr<GameObject>& object)
{
	list.emplace_front(object);
	map.emplace(name, object);
}

void ObjectTask::update()const
{
	for(const auto& object : list)
	{
		object->update();
	}
}

void ObjectTask::draw()const
{
	for (const auto& object : list)
	{
		object->draw();
	}
}

std::shared_ptr<GameObject>& ObjectTask::find(const std::string& name)
{
	return map.find(name)->second;
}

std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& ObjectTask::finds(const std::string& name)
{
	return map.equal_range(name);
}

void ObjectTask::clear()
{
	map.clear();
	list.clear();
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