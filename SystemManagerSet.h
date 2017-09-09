#ifndef SYSTEMMANAGERSET_H
#define SYSTEMMANAGERSET_H

#include "TextureManager.h"
#include "VertexBufferManager.h"

class SystemManagerSet
{
public:
    SystemManagerSet();
    TextureManager textureManager;
    VertexBufferManager vertexBufferManager;
};

#endif // SYSTEMMANAGERSET_H
