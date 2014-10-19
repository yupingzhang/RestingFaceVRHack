//
//  vec3.h
//  mySketch
//
//  Created by Yuping on 10/18/14.
//
//

#ifndef mySketch_vec3_h
#define mySketch_vec3_h

#include <cmath>

class vec3
{
public:
    float x;
    float y;
    float z;
    
public:
    vec3(vec3 const &vector)
    {
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }
    
    vec3(float x1=0.0, float y1=0.0, float z1=0.0)
    {
        x = x1;
        y = y1;
        z = z1;
    }
    
    float distanceTo(vec3 a)
    {
        float temp = (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y)+(z-a.z)*(z-a.z);
        return sqrt(temp);
    }
};



#endif
