#include "Mouse.h"

using namespace ci;
using namespace ci::app;



namespace input
{

void Mouse::flush()
{
	mouse_push.clear();
	mouse_pull.clear();
}

void Mouse::setMouseDown(const MouseEvent& event)
{
	mouse_press.clear();
	mouse_press.emplace(MouseCode::LEFT, event.isLeftDown());
	mouse_press.emplace(MouseCode::RIGHT, event.isRightDown());
	mouse_press.emplace(MouseCode::MIDDLE, event.isMiddleDown());

	mouse_push.emplace(MouseCode::LEFT, event.isLeftDown());
	mouse_push.emplace(MouseCode::RIGHT, event.isRightDown());
	mouse_push.emplace(MouseCode::MIDDLE, event.isMiddleDown());
}
void Mouse::setMouseUp(const MouseEvent& event)
{
	if(!event.isLeftDown())
	{
		mouse_press.erase(mouse_press.find(MouseCode::LEFT));
	}
	if (!event.isRightDown())
	{
		mouse_press.erase(mouse_press.find(MouseCode::RIGHT));
	}
	if (!event.isMiddleDown())
	{
		mouse_press.erase(mouse_press.find(MouseCode::MIDDLE));
	}
	mouse_pull.emplace(MouseCode::LEFT, !event.isLeftDown());
	mouse_pull.emplace(MouseCode::RIGHT, !event.isRightDown());
	mouse_pull.emplace(MouseCode::MIDDLE, !event.isMiddleDown());
}
}