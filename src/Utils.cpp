#include <GL/gl_mangle.h>

#include "../include/main.hpp"

float std::deg2rad(float deg)
{
    return deg * 0.0174532925;
}

float std::rad2deg(float rad)
{
    return rad * 57.2957795;
}

void std::glEnable2D()
{

}

void std::glDisable2D()
{

}

int std::glInit2DScene()
{
    //TODO check for NVIDIA support

}