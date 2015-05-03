#pragma once
#include "cinder\app\KeyEvent.h"
#include <set>
#include <array>

namespace input{

	//　キー入力
class Key : private boost::noncopyable
{
	std::set<int>key_press;
	std::set<int>key_pull;
	std::set<int>key_push;
	Key() = default;
public:
	static Key& GetInstance();

	//　setにスタックされているキーを流す(削除)
	void flush();

	//　スタック
	void setKeyDown(const int key_code);
	void setKeyUp(const int key_code);

	//　判定
	//　FixMe：小文字で反応
	bool isPress(const int key_code);
	bool isPush(const int key_code);
	bool isPull(const int key_code);

	bool isPress(const unsigned char key_char);
	bool isPush(const unsigned char key_char);
	bool isPull(const unsigned char key_char);
};
}
