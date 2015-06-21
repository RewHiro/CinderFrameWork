#pragma once
#include "Camera.h"


class MainCamera : public game::Camera
{
public:
	static MainCamera& getInstance()
	{
		static MainCamera instance;
		return instance;
	}
};