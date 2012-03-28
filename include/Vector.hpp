/* 
 * File:   Vector.hpp
 * Author: nick
 *
 * Created on March 28, 2012, 7:11 AM
 */

#ifndef VECTOR_HPP
#define	VECTOR_HPP

class Vector
{
public:
    float x, y; //X and Y components
    Vector(float x, float y);
    Vector(Vector* vector);
    
    Vector operator + (Vector vector2);
    Vector operator - (Vector vector2);
    Vector operator * (float scale);
    Vector operator / (float scale);
    
    float dot(Vector vector2);
    float lengthSquared();
    float length();
    Vector normalized();
    float distanceSquared(Vector vector2);
    float distance(Vector vector2);
};

#endif	/* VECTOR_HPP */

