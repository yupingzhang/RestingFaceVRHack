//
//  expression.h
//  mySketch
//
//  Created by Yuping on 10/18/14.
//
//

#ifndef __mySketch__expression__
#define __mySketch__expression__

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "vec3.h"

using namespace std;

typedef pair<string, float> Shape;

class Expression
{
public:
    
    pair<string, vector<Shape> > pattern;
    
    vector<int> keypointsIndex;  // selected key points
    
    vector<vec3> baseline;  // neutual vertices
    
    map<string, int> blendShapes;  //52 built-in shapes and their indices
    
    //vector<float>  avgWeights;   //compute the averege weight frame
public:

    Expression() {};
    
    void init(string patternName, vector<string> shapeNames); // load pattern
    
    // using neatral as baseline for numerical measurement
    void createBaseline(vector<vec3> vertices);
    
    void computeAvgWeight();
    
    vector<Shape> getPatternConfig();
    
    
    void setPatternWeightThreshold(string name, float min, float max);
    
    //check if match one certain pattern
    float xpatternDetection(vector<float> streamingWeights);

    float xpatternScale(vector<vec3> streamingVertices);
    
    
    vector<string> symmetricalAnalysis();
    
};

#endif /* defined(__mySketch__expression__) */
