#pragma once
#include "boost\noncopyable.hpp"
#include <set>
#include <array>

class FrameWorkApp;

namespace input{

	//�@�L�[����
class Key : private boost::noncopyable
{
	friend class FrameWorkApp;
	std::set<int>key_press;
	std::set<int>key_pull;
	std::set<int>key_push;
	Key() = default;
public:
	inline static Key& getInstance()
	{
		static Key key;
		return key;
	}

	//�@set�ɃX�^�b�N����Ă���L�[�𗬂�(�폜)
	void flush();

	//�@����
	//�@FixMe�F�������Ŕ���
	bool isPress(const int key_code);
	bool isPush(const int key_code);
	bool isPull(const int key_code);

	bool isPress(const unsigned char key_char);
	bool isPush(const unsigned char key_char);
	bool isPull(const unsigned char key_char);

private:
	//�@�X�^�b�N
	void setKeyDown(const int key_code);
	void setKeyUp(const int key_code);
};
}
