#pragma once 
#include "cinder\Vector.h"

bool isHitSphereAndSphere(
	const ci::Vec3f& a_pos,
	const float& a_radius,
	const ci::Vec3f& b_pos,
	const float& b_radius
	);

bool isHitSphereAndSphereBack(
	const ci::Vec3f& a_pos,
	const float& a_radius,
	const ci::Vec3f& b_pos,
	const float& b_radius
	);