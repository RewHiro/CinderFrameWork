#pragma once
#include "cinder\Vector.h"
#include "cinder\app\MouseEvent.h"
#include "boost\noncopyable.hpp"
#include <set>

class FrameWorkApp;

namespace input{
class Mouse : private boost::noncopyable
{

	friend class FrameWorkApp;
	std::set<int>mouse_push;
	std::set<int>mouse_press;
	std::set<int>mouse_pull;
	Mouse() = default;
	ci::Vec2i pos = ci::Vec2i::zero();
	//　マウスコードの合計値を保存するための変数
	int mouse_code_sum = 0;
	int wheel_value = 0;

public:
	inline static Mouse& getInstance()
	{
		static Mouse instance;
		return instance;
	}

	void flush();
	bool isPush(const int button)const;
	bool isPress(const int button)const;
	bool isPull(const int button)const;
	ci::Vec2i getPosition()const{ return pos; }
	int getWheelValue()const{ return wheel_value; }
private:
	void setMouseDown(const int button);
	void setMouseUp(const int button);
	void setPosition(const ci::Vec2i& pos){ this->pos = pos; }
	void setWheelValue(const int value){ wheel_value += value; }
};
}