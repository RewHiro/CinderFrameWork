#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class FrameWorkApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void FrameWorkApp::setup()
{
}

void FrameWorkApp::mouseDown( MouseEvent event )
{
}

void FrameWorkApp::update()
{
}

void FrameWorkApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( FrameWorkApp, RendererGl )
