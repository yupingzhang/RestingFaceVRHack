//
//  CatchCandy.h
//  mySketch
//
//  Created by Yuping on 10/19/14.
//
//

#ifndef __mySketch__CatchCandy__
#define __mySketch__CatchCandy__

#include <iostream>
#include <cstdlib>
#include "vec3.h"

class CatchCandy
{
public:
    int width, height;
    vec3 pos;
    float rotate; //rotate(t)  in degree
    
public:
    CatchCandy(int w, int h);
    void update(float timedelta, vec3 p1, vec3 p2,  bool openMouth);  // everytime candy disappear on the buttom of the screen of catch by mouth, it starts fall from the top again

};

#endif /* defined(__mySketch__CatchCandy__) */
