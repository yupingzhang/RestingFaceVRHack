//
//  expression.cpp
//  mySketch
//
//  Created by Yuping on 10/18/14.
//
//

#include "expression.h"

using namespace std;


void Expression::init(string patternName, vector<Shape> v) {
    pattern = make_pair(patternName, v);
    
//    for(int i=0; i<shapeNames.size(); i++) {
//        blendShapes[shapeNames[i]] = i;
//    }
    
//    printf("%d \n", shapeNames.size());
//    printf("%s \n", shapeNames[0].c_str());
    
}

void Expression::createBaseline(vector<vec3> vertices) {
    //only call once
    // from neutralMesh.getVertices()
    baseline.resize(7366);
    int n = vertices.size();
//    baseline(&vertices[0]);      //? for
    
}


vector<Shape> Expression::getPatternConfig() {
    return pattern.second;
}


void Expression::setPatternWeightThreshold(string name, float min, float max) {
    
}

//check if match one certain pattern, return the scale (pain scaling)
    
float Expression::xpatternDetection(vector<float> streamingWeights)  {
    float scale = 0;
    vector<Shape> shapes = pattern.second;
 
    for (int i=0; i<shapes.size(); i++) {
        string shapename = shapes[i].first;
        float baseValue = shapes[i].second;
        int index = blendShapes[shapename];
        scale += streamingWeights[index];
    }
    
    return scale;
}

    
float Expression::xpatternScale(vector<vec3> streamingVertices) {
        
    float scale = 0;
    float offset_sum = 0;
    //get the blend shapes for the pattern
    vector<Shape> shapes = pattern.second;
    
    for (int i=0; i<keypointsIndex.size(); i++) {
        vec3 basepoint = baseline[i];
        offset_sum = basepoint.distanceTo(streamingVertices[i]);
    }
    scale = offset_sum/100.0;    // just a factor to clamp
    
    return scale;
}


//symmetricalAnalysis
vector<string> Expression::symmetricalAnalysis() {
    
}


// detect eye movement delay?

//vertical (spinning)

// add bitch resting face!!

