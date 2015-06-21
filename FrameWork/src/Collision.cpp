#include "Collision.h"

bool isHitSphereAndSphere(
	const ci::Vec3f& a_pos,
	const float& a_radius,
	const ci::Vec3f& b_pos,
	const float& b_radius
	)
{
	auto dis = a_pos.distance(b_pos);
	if (dis > a_radius + b_radius)return false;
	return true;
}


bool isHitSphereAndSphereBack(
	const ci::Vec3f& a_pos,
	const float& a_radius,
	const ci::Vec3f& b_pos,
	const float& b_radius
	)
{
	auto dis = a_pos.distance(b_pos);
	if (dis < a_radius + b_radius)return false;
	return true;
}