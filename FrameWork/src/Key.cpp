#include "Key.h"
#include "Mouse.h"

namespace input{

Key& Key::getInstance()
{
	static Key key;
	return key;
}

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


bool Key::isPress(const int key_code)
{
	return key_press.find(key_code) != key_press.cend();
}

bool Key::isPush(const int key_code)
{
	return key_push.find(key_code) != key_push.cend();
}

bool Key::isPull(const int key_code)
{
	return key_pull.find(key_code) != key_pull.cend();
}

bool Key::isPress(const unsigned char key_char)
{
	return key_press.find(static_cast<int>(key_char)) != key_press.cend();
}
bool Key::isPush(const unsigned char key_char)
{
	return key_push.find(static_cast<int>(key_char)) != key_push.cend();
}
bool Key::isPull(const unsigned char key_char)
{
	return key_pull.find(static_cast<int>(key_char)) != key_pull.cend();
}
}