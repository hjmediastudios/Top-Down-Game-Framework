/* 
 * File:   Transform.hpp
 * Author: nick
 *
 * Created on March 28, 2012, 7:25 AM
 */

#ifndef TRANSFORM_HPP
#define	TRANSFORM_HPP

#include "main.hpp"

class Transform
{
public:
    Vector position;
    float rotation;
    float scale;
    
    Transform(float posX, float posY, float rotation, float scale);
    Transform(Vector position, float rotation, float scale);
    
    void translate(Vector vector2);
    void translate(float x, float y);
    void rotate(float theta);
};


#endif	/* TRANSFORM_HPP */

