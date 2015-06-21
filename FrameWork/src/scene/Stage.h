#pragma once
#include "Scene.h"
#include "cinder\params\Params.h"
#include "cinder\gl\Light.h"
#include "Camera.h"
#include "cinder\audio\Voice.h"
#include <memory>

class Stage : public Scene
{
	ci::params::InterfaceGl param;
	ci::Quatf camera_rotate = ci::Quatf::identity();


	struct DivCameraData
	{
		game::Camera camera;
		ci::Area area;
	};

	std::vector<DivCameraData>div_cameras;

	std::unique_ptr<ci::gl::Light> light;

	float dis = 0.0f;


public:

	Stage();
	SceneType update();
	void draw();
	void resize();
};