#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Key.h"
#include "Mouse.h"

using namespace ci;
using namespace ci::app;
using namespace input;


class FrameWorkApp : public AppNative {

  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void mouseUp(MouseEvent event);
	void mouseWheel(MouseEvent event);
	void mouseMove(MouseEvent event);
	void mouseDrag(MouseEvent event);
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};

void FrameWorkApp::setup()
{
	Key::GetInstance();
	Mouse::getInstance();
}

void FrameWorkApp::mouseDown( MouseEvent event )
{
	Mouse::getInstance().setMouseDown(event.getCode());
}
void FrameWorkApp::mouseUp(MouseEvent event)
{
	Mouse::getInstance().setMouseUp(event.getCode());
}
void FrameWorkApp::mouseWheel(MouseEvent event)
{
	Mouse::getInstance().setWheelValue(static_cast<int>(event.getWheelIncrement()));
}
void FrameWorkApp::mouseMove(MouseEvent event)
{
	Mouse::getInstance().setPosition(event.getPos());
}
void FrameWorkApp::mouseDrag(MouseEvent event)
{
}

void FrameWorkApp::keyDown(KeyEvent event)
{
	Key::GetInstance().setKeyDown(event.getCode());
}

void FrameWorkApp::keyUp(KeyEvent event)
{
	Key::GetInstance().setKeyUp(event.getCode());
}

void FrameWorkApp::update()
{
	auto& mouse = Mouse::getInstance();
	if(mouse.isPush(MouseEvent::LEFT_DOWN))
	{
		console() << "L" << std::endl;
	}
	if(mouse.isPress(MouseEvent::RIGHT_DOWN))
	{
		console() << "R" << std::endl;
	}
	if(mouse.isPull(MouseEvent::MIDDLE_DOWN))
	{
		console() << "M" << std::endl;
	}
	console() << mouse.getWheelValue() << std::endl;
}

void FrameWorkApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 

	Mouse::getInstance().flush();
	Key::GetInstance().flush();
}

CINDER_APP_NATIVE( FrameWorkApp, RendererGl )
