#include "PlayerFoot.h"
#include "cinder\gl\gl.h"
#include "cinder\app\App.h"

using namespace ci;
using namespace ci::app;

PlayerFoot::PlayerFoot(const std::string& name,const int number):
player(getObjectType<Player>(name)),
number(number)
{
	pos = Vec3f(0, -8, 3 + -number * 1.0f);
	scale = ci::Vec3f(9, 10, 0.3f);
}

void PlayerFoot::update()
{
	if(player.lock()->getAnimState() == Player::AnimState::STOP)
	{
		effect_angle.x = 0.0f;
	}
	else if (player.lock()->getAnimState() == Player::AnimState::RUN)
	{
		effect_angle.x += 0.1f;
	}

	if(player.lock()->getState() == Player::State::ATTACK)
	{
		effect_angle.x = 3.14f;
	}
	else if(player.lock()->getState() == Player::State::DRAIN)
	{
		effect_angle.x = 3.14f;
	}
	parent_pos = player.lock()->getPos();

	if(is_drain)
	{
		parent_pos = anim_pos.value();
		scale = anim_scale.value();
		++count;
		if(count == 60 * 4)
		{
			destory();
		}
	}
}

void PlayerFoot::draw()
{
	gl::enableAlphaBlending();

	gl::color(player.lock()->getColor());
	gl::pushModelView();

	gl::translate(parent_pos);
	glMultMatrixf(player.lock()->getRotate().toMatrix44());
	gl::scale(player.lock()->getScale());
	
	if(!is_drain){
		gl::translate(pos);
	}	
	auto quatf = Quatd(Vec3f::xAxis(), -M_PI / 6 + (M_PI / 12) * number + std::sinf(effect_angle.x - number * 0.1f) * M_PI / 12);
	gl::translate(Vec3f(0, 5, 0));
	gl::rotate(quatf);
	gl::translate(Vec3f(0, -5, 0));
	gl::scale(scale);
	gl::drawCube(Vec3f::zero(), Vec3f::one());
	gl::popModelView();

	gl::disableAlphaBlending();

}

void PlayerFoot::setDrain(const std::string& name)
{
	anim_scale.value() = scale;
	timeline().apply(&anim_scale, Vec3f::zero(), 3.0f, easeInQuint);
	timeline().apply(&anim_pos, parent_pos, findObject(name)->getPos(), 3.0f, easeInQuint);
	is_drain = true;
}