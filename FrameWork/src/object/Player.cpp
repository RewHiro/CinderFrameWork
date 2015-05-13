#include "Player.h"
#include "cinder\app\App.h"
#include "cinder\Vector.h"
#include "input\Mouse.h"
#include "Graphics.h"

using namespace ci;
using namespace ci::app;
using namespace input;

Player::Player(ObjectTask& task):
GameObject(task)
{
	
}


void Player::update()
{
}
void Player::draw()
{
	g3d::drawCube(Vec3f::zero(), Vec3f::one() * 10);
}