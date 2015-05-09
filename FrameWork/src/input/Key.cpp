#include "Key.h"
#include "Mouse.h"

namespace input{

void Key::flush()
{
	key_push.clear();
	key_pull.clear();
}

void Key::setKeyDown(const int key_code)
{
	if (key_press.find(key_code) == key_press.cend())
	{
		key_push.emplace(key_code);
	}
	key_press.emplace(key_code);
}


void Key::setKeyUp(const int key_code)
{
	key_pull.emplace(key_code);
	key_press.erase(key_code);
}
}