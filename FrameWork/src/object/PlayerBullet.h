#pragma once
#include "GameObject.h"
#include "Player.h"
#include <functional>
#include <unordered_map>


class PlayerBullet : public GameObject
{

	std::function<void()>collider;

	ci::Vec3f direction;
public:
	PlayerBullet(const ci::Vec3f& pos, const ci::Vec3f& direction, const ci::ColorA& color,const Player::Type type);
	void update();
	void draw();
	void start(){
		int a = 0;
	}
};