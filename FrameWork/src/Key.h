#pragma once
#include "cinder\app\KeyEvent.h"
#include <set>
#include <array>

namespace input{

	//�@�L�[����
class Key : private boost::noncopyable
{
	std::set<int>key_press;
	std::set<int>key_pull;
	std::set<int>key_push;
	Key() = default;
public:
	static Key& GetInstance();

	//�@set�ɃX�^�b�N����Ă���L�[�𗬂�(�폜)
	void flush();

	//�@�X�^�b�N
	void setKeyDown(const int key_code);
	void setKeyUp(const int key_code);

	//�@����
	//�@FixMe�F�������Ŕ���
	bool isPress(const int key_code);
	bool isPush(const int key_code);
	bool isPull(const int key_code);

	bool isPress(const unsigned char key_char);
	bool isPush(const unsigned char key_char);
	bool isPull(const unsigned char key_char);
};
}
