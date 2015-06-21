//#pragma once
//#include "boost\noncopyable.hpp"
//#include "object\GameObject.h"
//
//class Component : private boost::noncopyable
//{
//	enum class State
//	{
//		AWAKE,
//		START,
//		UPDATE,
//	};
//	State state;
//
//protected:
//	bool is_active;
//
//	//const std::shared_ptr<GameObject>&  objectFind(const std::string& name);
//
//	//const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& objectFinds(const std::string& name);
//
//	//template<class Type>
//	//const std::shared_ptr<Type>getComponent()const
//	//{
//	//	const std::string& name = typeid(Type).name();
//	//}
//
//public:
//	Component(GameObject& object);
//	virtual ~Component() = 0{};
//
//	virtual void awake(){}
//	virtual void start(){}
//	virtual void update(){}
//
//	virtual std::string name()const
//	{
//		const std::type_info& id = typeid(*this);
//		const std::string& name = id.name();
//		return name.substr(6);
//	}
//
//	State getState(){ return state; }
//
//	GameObject& object;
//};