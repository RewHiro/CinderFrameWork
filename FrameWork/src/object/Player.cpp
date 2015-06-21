#include "Player.h"
#include "cinder\app\App.h"
#include "cinder\Vector.h"
#include "input\Key.h"
#include "Graphics.h"
#include "MainCamera.h"
#include "PlayerBullet.h"
#include "Collision.h"
#include "PlayerFoot.h"
#include "input\UtilityGamePad.h"
#include "cinder\params\Params.h"
#include "cinder\Rand.h"


using namespace ci;
using namespace ci::app;
using namespace input;


Player::Player(const Vec3f& pos, const Quatf& rotate, game::Camera& camera, const Type player_num, const ColorA& color) :
_camera(camera)
{

	//param = cinder::params::InterfaceGl("camera", Vec2i::one() * 255);
	//param.addParam("alpha_speed", &alpha_speed);

	theta = static_cast<float>(M_PI + rotate.getAngle());
	this->pos = pos;
	scale = Vec3f::one() * 0.1f;
	this->rotate = rotate;
	this->color = color;
	type = player_num;

	direction = rotate * Vec3f::zAxis();

	camera_offset = Vec3f::zAxis() * -10;

	auto tmp_direction = _camera.getPos() - pos;
	tmp_direction.normalize();

	_camera.lookAt(pos + camera_offset, tmp_direction, Vec3f::yAxis());
	_camera.setPos(Vec3f::zero());

	switch (player_num)
	{
		case Type::ONE:
			attack_collision = [this]()
			{

				for(auto& player: getVector())
				{
					if (player->getType() == Type::ONE)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if(player->getState() != State::DOWN){
						if(!player->isHit()){
							if (isHitSphereAndSphere(this->pos, 0.8f, player->getPos(), 0.8f))
							{
								player->hit();
							}
						}
					}
				}
			};
			drain_collision = [this]()
			{
				for(auto& player : getVector())
				{
					if (player->getType() == Type::ONE)continue;
					if (player->getState() != State::DOWN)continue;
					if (player->getState() == State::DRAINED)continue;
					if (player->getState() == State::DRAINING)continue;
					if (isHitSphereAndSphere(this->pos + this->direction * 3, 2.0f, player->getPos(), 0.8f))
					{
						this->state = State::DRAINING;
						getObjectType<PlayerFoot>(player->getName() + std::string("foot") + std::to_string(player->death_count))->setDrain(this->getName());
						player->drained();
					}
				}
			};
			break;
		case Type::TWO:
			attack_collision = [this]()
			{

				for (auto& player : getVector())
				{
					if (player->getType() == Type::TWO)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if (player->getState() != State::DOWN){
						if (!player->isHit()){
							if (isHitSphereAndSphere(this->pos, 0.8f, player->getPos(), 0.8f))
							{
								player->hit();
							}
						}
					}
				}
			};
			drain_collision = [this]()
			{
				for (auto& player : getVector())
				{
					if (player->getType() == Type::TWO)continue;
					if (player->getState() != State::DOWN)continue;
					if (player->getState() == State::DRAINED)continue;
					if (player->getState() == State::DRAINING)continue;
					if (isHitSphereAndSphere(this->pos + this->direction * 3, 2.0f, player->getPos(), 0.8f))
					{
						this->state = State::DRAINING;
						getObjectType<PlayerFoot>(player->getName() + std::string("foot") + std::to_string(player->death_count))->setDrain(this->getName());
						player->drained();
					}
				}
			};
			break;
		case Type::THREE:
			attack_collision = [this]()
			{

				for (auto& player : getVector())
				{
					if (player->getType() == Type::THREE)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if (player->getState() != State::DOWN){
						if (!player->isHit()){
							if (isHitSphereAndSphere(this->pos, 0.8f, player->getPos(), 0.8f))
							{
								player->hit();
							}
						}
					}
				}
			};
			drain_collision = [this]()
			{
				for (auto& player : getVector())
				{
					if (player->getType() == Type::THREE)continue;
					if (player->getState() != State::DOWN)continue;
					if (player->getState() == State::DRAINED)continue;
					if (player->getState() == State::DRAINING)continue;
					if (isHitSphereAndSphere(this->pos + this->direction * 3, 2.0f, player->getPos(), 0.8f))
					{
						this->state = State::DRAINING;
						getObjectType<PlayerFoot>(player->getName() + std::string("foot") + std::to_string(player->death_count))->setDrain(this->getName());
						player->drained();
					}
				}
			};
			break;
		case Type::FOUR:
			attack_collision = [this]()
			{

				for (auto& player : getVector())
				{
					if (player->getType() == Type::FOUR)continue;
					if (player->getState() == Player::State::DRAINED)continue;
					if (player->getState() == Player::State::DRAINING)continue;
					if (player->getState() != State::DOWN){
						if (!player->isHit()){
							if (isHitSphereAndSphere(this->pos, 0.8f, player->getPos(), 0.8f))
							{
								player->hit();
							}
						}
					}
				}
			};
			drain_collision = [this]()
			{
				for (auto& player : getVector())
				{
					if (player->getType() == Type::FOUR)continue;
					if (player->getState() != State::DOWN)continue;
					if (player->getState() == State::DRAINED)continue;
					if (player->getState() == State::DRAINING)continue;
					if (isHitSphereAndSphere(this->pos + this->direction * 3, 2.0f, player->getPos(), 0.8f))
					{
						this->state = State::DRAINING;
						getObjectType<PlayerFoot>(player->getName() + std::string("foot") + std::to_string(player->death_count))->setDrain(this->getName());
						player->drained();
					}
				}
			};
			break;
	}

}


void Player::start()
{
	for (int i = 0; i < 6; ++i)
	{
		auto num_str = std::to_string(i);
		addObject(getName()+ std::string("foot") +num_str, std::make_shared<PlayerFoot>(getName(), i));
	}
}

void Player::update()
{
	if (state == State::DEATH)return;
	auto& gamepad = GamePad::getInstance();
	control();

	if (state != State::ATTACK && state != State::DRAINED && state != State::DRAINING)
	{
		if(gamepad.isPressButton(static_cast<int>(type),GamePad::ButtonID::LEFT))
		{
			state = State::DRAIN;
			effect_angle = Vec3f::zero();
			drain_collision();
		}
		else
		{
			if(state != State::HIT){
				state = State::LIVE;
			}
		}
	}

	if(state == State::DRAINING)
	{
		drain_radina += 0.5f;
		scale.y = std::sinf(drain_radina) * 0.03f + 0.1f;
		++draining_count;
		if(draining_count == 60 * 4)
		{
			state = State::LIVE;
			draining_count = 0;
		}
	}

	if(state == State::DRAINED)
	{
		drain_radina += 0.5f;
		scale.y = std::sinf(drain_radina) * 0.03f + 0.2f;
		scale.x = 0.05f;
		scale.z = 0.05f;

		++drained_count;
		if(drained_count == 60 * 3)
		{
			++death_count;
		}
		else if (drained_count == 60 * 4)
		{
			state = State::LIVE;
			hp = 3;
			hit_count = 0;
			color.a = 1;
			rip_color.a = 1;
			face_color.a = 1;
			eye_color.a = 1;
			drained_count = 0;
			scale = Vec3f::one() * 0.1f;
		}
		if(drained_count >= 60 * 3)
		{
			scale.y = 0.2f;
			rotate = rotate.lerp(0.1f, Quatf(Vec3f::yAxis(), 0));
		}
	}


	if (state == State::ATTACK)
	{
		right_attack_effect_rafian += 0.3f;
		left_attack_effect_rafian += 0.3f;
		attack_count++;
		pos = anim_pos.value();

		if (attack_count == 90)
		{
			attack_count = 0;
			state = State::LIVE;
			anim_state = AnimState::STOP;
		}
		attack_collision();
	}
	else
	{
		right_attack_effect_rafian = 0.0f;
		left_attack_effect_rafian = 0.0f;
	}

	rip_scale.y = (anim_state == AnimState::BULLET_ATTACK) ? 1.0f : 0.5f;

	if(state == State::HIT)
	{
		++hit_count;
		auto radian = hit_count * 0.8f;
		color.a = std::sinf(radian);
		rip_color.a = std::sinf(radian);
		face_color.a = std::sinf(radian);
		eye_color.a = std::sinf(radian);
		if(hit_count == 90)
		{
			state = State::LIVE;
			hit_count = 0;
			color.a = 1;
			rip_color.a = 1;
			face_color.a = 1;
			eye_color.a = 1;
		}
	}

	if(hp <= 0)
	{
		if(state != State::DRAINED){
			state = State::DOWN;
		}
	}


	if(state == State::DOWN)
	{
		if (down_count == 0)
		{
			color.a = 0.5f;
			rip_color.a = 0.5f;
			face_color.a = 0.5f;
			eye_color.a = 0.5f;
		}
		if (down_count >= 320)
		{
			rotate = rotate.lerp(0.1f, Quatf(Vec3f::yAxis(), 0));
		}
		else
		{
			auto cross = direction.cross(Vec3f::yAxis());
			cross.safeNormalize();
			console() << cross << direction << std::endl;
			rotate = rotate.lerp(0.1f, Quatf(cross, M_PI*0.5f));
		}

		down_count++;
		if (down_count == 320 + 60)
		{
			hp = 3;
			down_count = 0;
			color.a = 1;
			rip_color.a = 1;
			face_color.a = 1;
			eye_color.a = 1;
			pos.x += randFloat(-2.0f,2.0f);
			pos.z += randFloat(-2.0f, 2.0f);
			state = State::LIVE;
		}
	}
	

	if(state == State::DRAIN)
	{
		drain_radina += 0.5f;
		scale.y = std::sinf(drain_radina) * 0.01f + 0.1f;
	}
	else
	{
		if (state != State::DRAINING && state != State::DRAINED){
			scale.y = 0.1f;
		}
	}

	if(death_count == 6)
	{
		state = State::DEATH;
	}

	camera_offset = Vec3f(std::sinf(theta),0,std::cosf(theta)) * 4.0f;
	_camera.setPos(pos + camera_offset + Vec3f::yAxis()*2.0f);
	_camera.setCenterOfInterestPoint(pos);
}

void Player::draw()
{
	gl::enableAlphaBlending();

	gl::pushModelView();
	gl::translate(pos);
	glMultMatrixf(rotate.toMatrix44());
	gl::scale(scale);

	g3d::drawCube(Vec3f::zero(), Vec3f::one() * 10, face_color);
	g3d::drawSphere(Vec3f(-2,2,5), 1.0f, eye_color);
	g3d::drawSphere(Vec3f(2, 2, 5), 1.0f, eye_color);

	gl::pushModelView();
	gl::color(rip_color);
	gl::translate(Vec3f(0, -2, 5));
	gl::scale(rip_scale);
	gl::drawTorus(2, 0.7f);
	gl::popModelView();

	gl::color(color);

	gl::pushModelView();
	gl::translate(Vec3f(5,-5,0));
	gl::translate(Vec3f(0, 2.5f, 0));
	gl::rotate(Quatd(Vec3f::xAxis(), (M_PI / 6) * std::sinf(effect_angle.x) + left_attack_effect_rafian));
	gl::rotate(Quatd(Vec3f::zAxis(), M_PI / 6 + (M_PI / 36) * std::sinf(effect_angle.z)));
	gl::translate(Vec3f(0, -2.5f, 0));
	gl::scale(Vec3f(1,5,1));
	gl::drawSphere(Vec3f::zero(), 1,30);
	gl::popModelView();

	gl::pushModelView();
	gl::translate(Vec3f(-5, -5, 0));
	gl::translate(Vec3f(0, 2.5f, 0));
	gl::rotate(Quatd(Vec3f::xAxis(), (-M_PI / 6) * std::sinf(effect_angle.x) + right_attack_effect_rafian));
	gl::rotate(Quatd(Vec3f::zAxis(), -M_PI / 6 - (M_PI / 36) * std::sinf(effect_angle.z)));
	gl::translate(Vec3f(0, -2.5f, 0));
	gl::scale(Vec3f(1, 5, 1));
	gl::drawSphere(Vec3f::zero(), 1,30);
	gl::popModelView();

	gl::popModelView();

	gl::disableAlphaBlending();


	//param.draw();
}

void Player::control()
{
	auto& gamepad = GamePad::getInstance();
	const auto& SPEED_Y = gamepad.getPressAxis(static_cast<int>(type), GamePad::AxisID::LEFT_Y);
	const auto& SPEED_X = gamepad.getPressAxis(static_cast<int>(type), GamePad::AxisID::LEFT_X);
	const auto& ROTATE_SPEED_X = gamepad.getPressAxis(static_cast<int>(type), GamePad::AxisID::RIGHT_X);

	theta += ROTATE_SPEED_X * 0.2f;

	if (state == State::ATTACK)return;
	if (state == State::DOWN)return;
	if (state == State::DRAIN)return;
	if (state == State::DRAINED)return;
	if (state == State::DRAINING)return;

	auto local_speed_z = Vec3f(_camera.getViewDirection().x, 0, _camera.getViewDirection().z);

	auto local_speed_x = Vec3f::zero();
	local_speed_x = -local_speed_z.cross(Vec3f::yAxis());

	local_speed_z *= SPEED_Y;
	local_speed_x *= SPEED_X;

	auto speed_dir = local_speed_z + local_speed_x;
	speed_dir.safeNormalize();

	if (speed_dir != Vec3f::zero())
	{
		direction = speed_dir;
	}
	if (SPEED_Y != 0.0f || SPEED_X != 0.0f)
	{
		rotate = Quatf(Vec3f::zAxis(), direction);

		anim_state = AnimState::RUN;

		auto speed_value = std::max(std::fabs(SPEED_X), std::fabs(SPEED_Y));

		pos += speed_dir * speed_value * 0.2f;

		console() << speed_dir * speed_value * 0.2f << std::endl;

		effect_angle.x += 0.1f;
		effect_angle.z = 0.f;
	}
	else
	{
		anim_state = AnimState::STOP;
		effect_angle.x = 0.0f;
		effect_angle.z += 0.08f;
	}

	if (gamepad.isPushButton(static_cast<int>(type), GamePad::ButtonID::RIGHT) || Key::getInstance().isPush(KeyEvent::KEY_w))
	{
		auto bullet_direction = direction + Vec3f::yAxis()*0.5f;
		addObject("bullet", std::make_shared<PlayerBullet>(pos - Vec3f::yAxis() * 0.1f, bullet_direction.safeNormalized(), color, type));
		anim_state = AnimState::BULLET_ATTACK;
	}

	if (gamepad.isPushButton(static_cast<int>(type), GamePad::ButtonID::UP))
	{
		state = State::ATTACK;
		left_attack_effect_rafian = static_cast<float>(M_PI);

		anim_pos.value() = pos;
		auto goal_pos = pos + direction * 8.0f;

		timeline().apply(&anim_pos, goal_pos, 1.0f, easeOutQuint);
		//pos += direction * 3.0f;
	}
}