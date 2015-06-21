#pragma once
#include "GameObject.h"
#include "Player.h"

class PlayerFoot : public GameObject
{
	std::weak_ptr<Player>player;
	ci::Vec3f effect_angle;
	ci::Vec3f parent_pos;
	int number = 0;
	bool is_drain = false;
	ci::Anim<ci::Vec3f>anim_pos;
	ci::Anim<ci::Vec3f>anim_scale;
	int count = 0;
public:
	PlayerFoot(const std::string& name, const int number);
	void update();
	void draw();

	void setDrain(const std::string& name);
};