#pragma once
#include "cinder\Vector.h"
#include "cinder\app\MouseEvent.h"
#include "boost\noncopyable.hpp"
#include <unordered_map>

class FrameWorkApp;

namespace input{
class Mouse : private boost::noncopyable
{
public:
	enum class MouseCode{
		LEFT,
		RIGHT,
		MIDDLE,
	};

private:
	friend class FrameWorkApp;
	std::unordered_map<MouseCode,bool>mouse_push;
	std::unordered_map<MouseCode, bool>mouse_press;
	std::unordered_map<MouseCode, bool>mouse_pull;

	Mouse() = default;
	ci::Vec2i pos = ci::Vec2i::zero();
	//　マウスコードの合計値を保存するための変数
	int wheel_value = 0;

public:
	inline static Mouse& getInstance()
	{
		static Mouse instance;
		return instance;
	}

	void flush();
	void clear();
	bool isPush(MouseCode code)const{ 
		if (mouse_push.find(code) == mouse_push.cend())return false;
		return mouse_push.find(code)->second; 
	}
	bool isPress(MouseCode code)const{ 
		if (mouse_press.find(code) == mouse_press.cend())return false;
		return mouse_press.find(code)->second; 
	}
	bool isPull(MouseCode code)const{ 
		if (mouse_pull.find(code) == mouse_pull.cend())return false;
		return mouse_pull.find(code)->second; 
	}
	ci::Vec2i getPosition()const{ return pos; }
	int getWheelValue()const{ return wheel_value; }
private:
	void setMouseDown(const ci::app::MouseEvent& event);
	void setMouseUp(const ci::app::MouseEvent& event);
	void setPosition(const ci::Vec2i& pos){ this->pos = pos; }
	void setWheelValue(const int value){ wheel_value += value; }
};
using MouseCode = Mouse::MouseCode;
}