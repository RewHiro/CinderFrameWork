#include "Mouse.h"

namespace input
{

void Mouse::flush()
{
	mouse_push.clear();
	mouse_pull.clear();
}

void Mouse::setMouseDown(const int button)
{
	//　マウスのクリックを同時押しするとその合計が得られるため何がクリックされたかマウスのコードを計算する
	auto mouse_code = button - mouse_code_sum;
	if (mouse_press.find(mouse_code) == mouse_press.cend())
	{
		mouse_push.emplace(mouse_code);
	}
	mouse_press.emplace(mouse_code);
	mouse_code_sum = button;
}
void Mouse::setMouseUp(const int button)
{
	//　マウスのクリックを同時押しするとその合計が得られるため何がクリックされたかマウスのコードを計算する
	auto mouse_code = mouse_code_sum - button;
	mouse_pull.emplace(mouse_code);
	mouse_press.erase(mouse_code);
	mouse_code_sum = button;
}


bool Mouse::isPush(const int button)const
{
	return mouse_push.find(button) != mouse_push.cend();
}
bool Mouse::isPress(const int button)const
{
	return mouse_press.find(button) != mouse_press.cend();
}
bool Mouse::isPull(const int button)const
{
	return mouse_pull.find(button) != mouse_pull.cend();
}
}