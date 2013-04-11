#include "texturemanager.h" // class's header file
#include <GL/glut.h>

// class constructor
TextureManager::TextureManager()
{

}

// class destructor
TextureManager::~TextureManager()
{
	// insert your code here
}
void TextureManager::AddTexture()
{
	TextureId=loadTexture("Hello.bmp");
};

