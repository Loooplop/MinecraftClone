#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "ImageLoader.h"
/*
 * No description
 */
class TextureManager
{
	// private section
	public:
		// class constructor
		TextureManager();
		// class destructor
		~TextureManager();
		void AddTexture();
	//protected:
	GLuint TextureId;
};

#endif // TEXTUREMANAGER_H

