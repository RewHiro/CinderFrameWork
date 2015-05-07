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
	//�@�}�E�X�̃N���b�N�𓯎���������Ƃ��̍��v�������邽�߉����N���b�N���ꂽ���}�E�X�̃R�[�h���v�Z����
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
	//�@�}�E�X�̃N���b�N�𓯎���������Ƃ��̍��v�������邽�߉����N���b�N���ꂽ���}�E�X�̃R�[�h���v�Z����
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