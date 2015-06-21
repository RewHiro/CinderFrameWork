#pragma once
#include "GameObject.h"
#include "cinder\params\Params.h"
#include "Camera.h"
#include "cinder\Timeline.h"

#include <functional>



class Player : public GameObject
{
public:
	enum class AnimState
	{
		STOP,
		RUN,
		ATTACK,
		BULLET_ATTACK,
		HIT,
		DOWN,
		DRAIN,
	};

	enum class Type
	{
		ONE,
		TWO,
		THREE,
		FOUR,
	};

	enum class State
	{
		LIVE,
		DEATH,
		ATTACK,
		HIT,
		DOWN,
		DRAIN,
		DRAINED,
		DRAINING,
		INV,
	};

private:

	State state = State::LIVE;

	std::function<void()>attack_collision;
	std::function<void()>drain_collision;


	AnimState anim_state = AnimState::STOP;

	ci::params::InterfaceGl param;
	ci::Vec3f camera_offset;
	ci::Vec3f foot_pos = ci::Vec3f::zero();
	ci::Vec3f foot_scale = ci::Vec3f(10, 10, 0.3f);
	ci::Vec3f hand_pos = ci::Vec3f::zero();
	ci::Vec3f hand_scale = ci::Vec3f(10, 10, 0.3f);
	ci::Vec3f rip_scale = ci::Vec3f(1, 0.5f, 1.5f);
	float left_attack_effect_rafian = 0.0f;
	float right_attack_effect_rafian = 0.0f;
	int attack_count = 0;
	int bullet_count = 0;
	ci::Vec3f effect_angle = ci::Vec3f::zero();
	ci::Vec3f direction = ci::Vec3f::zAxis();
	game::Camera& _camera;
	ci::Vec3f speed;
	float speed_value = 0.0f;
	float theta = 0.0f;
	int hp = 3;
	int hit_count = 0;
	int down_count = 0;
	Type type;
	float drain_radina = 0.0f;
	ci::Anim<ci::Vec3f>anim_pos;
	int drained_count = 0;
	int draining_count = 0;
	int death_count = 0;
	int inv_count = 0;

	ci::ColorA rip_color = ci::ColorA(1, 0, 0, 1);
	ci::ColorA eye_color = ci::ColorA(0, 0, 0, 1);
	ci::ColorA face_color = ci::ColorA(1, 1, 1, 1);

	void control();
public:

	Player(
		const ci::Vec3f& pos,
		const ci::Quatf& rotate,
		game::Camera& camera,
		const Type player_num,
		const ci::ColorA& color
		);

	void start();
	void update();
	void draw();

	AnimState getAnimState()const{ return anim_state; }
	bool isHit()const{ return state == State::HIT; }
	State getState()const{ return state; }
	Type getType()const{ return type; }
	int getDeathCount()const{ return death_count; }

	static std::vector<std::shared_ptr<Player>>& getVector()
	{ 
		static std::vector<std::shared_ptr<Player>>players; 
		return players;
	}

	void hit()
	{ 
		--hp;
		state = State::HIT; 
	}

	void drained()
	{
		state = State::DRAINED;
	}
};
