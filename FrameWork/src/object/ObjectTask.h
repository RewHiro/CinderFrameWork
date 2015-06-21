#pragma once
#include "GameObject.h"
#include "boost\noncopyable.hpp"
#include <memory>
#include <forward_list>
#include <unordered_map>
#include <stack>

class ObjectTask : private boost::noncopyable
{
	std::unordered_multimap<std::string, std::shared_ptr<GameObject>>map;
	std::stack<std::shared_ptr<GameObject>>delete_list;
	std::list<std::shared_ptr<GameObject>>list;
	ObjectTask() = default;
public:
	static ObjectTask& getInstance();
	void add(const std::string& name, const std::shared_ptr<GameObject>& object);
	void update()const;
	void draw()const;
	std::shared_ptr<GameObject>& find(const std::string& name)
	{ 
		return map.find(name)->second; 
	}
	std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& finds(const std::string& name){ return map.equal_range(name); }
	void clear();
	void erase();
	void addDelete(const std::shared_ptr<GameObject>& object);
};