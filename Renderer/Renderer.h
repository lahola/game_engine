#if defined _WIN32
	#include <EGL/egl.h>
	#include <GLES2/gl2.h>
#elif defined __APPLE__
	#include "TargetConditionals.h"
	#if TARGET_OS_IPHONE
		#include <opengles/es2/gl.h>
		#include <opengles/es2/glext.h>
	#endif
#endif

static const float RevolutionsPerSecond = 1;

// Physical orientation of a handheld device, equivalent to UIDeviceOrientation
enum DeviceOrientation {
    DeviceOrientationUnknown,
    DeviceOrientationPortrait,
    DeviceOrientationPortraitUpsideDown,
    DeviceOrientationLandscapeLeft,
    DeviceOrientationLandscapeRight,
    DeviceOrientationFaceUp,
    DeviceOrientationFaceDown,
};

class Renderer
{
public:
    static Renderer& getInstance()
    {
        static Renderer instance;
        return instance;
    }

    void Initialize(int width, int height);
    void Render() const;
    void UpdateAnimation(float timeStep);
    void OnRotate(DeviceOrientation newOrientation);
private:
    Renderer();
    float RotationDirection() const;
    GLuint BuildShader(const char* source, GLenum shaderType) const;
    GLuint BuildProgram(const char* vShader, const char* fShader) const;
    void ApplyOrtho(float maxX, float maxY) const;
    void ApplyRotation(float degrees) const;
    float m_desiredAngle;
    float m_currentAngle;
    GLuint m_simpleProgram;
    GLuint m_framebuffer;
    GLuint m_renderbuffer;
};