//
//  ofxIldaPoint.h
//  ofxIlda
//
//  Created by Memo Akten on 09/05/2013.
//
//

#pragma once

namespace ofxIlda {
    
#define kIldaMinPoint -32768
#define kIldaMaxPoint 32767
#define kIldaDimension (kIldaMaxPoint - kIldaMinPoint)
#define kIldaMaxIntensity 65535
    
    class Point {
    public:
        Point() : x(0), y(0), r(0), g(0), b(0), a(0) {}
        Point(int16_t x, int16_t y, int16_t r=0, int16_t g=0, int16_t b=0, int16_t a=0): x(x), y(y), r(r), g(g), b(b), a(a) {}
        Point(glm::vec3 p, ofFloatColor c, glm::vec3 pmin = {0,0,0}, glm::vec3 pmax = {1,1,1}) { set(p, c, pmin, pmax); }
        Point(glm::vec3 p, glm::vec3 pmin = {0,0,0}, glm::vec3 pmax = {1,1,1}) { setPosition(p, pmin, pmax); }
        
        int16_t x;
        int16_t y;
        uint16_t r;
        uint16_t g;
        uint16_t b;
        uint16_t a;
        uint16_t u1;  // what are these for? standard ILDA or just etherdream?
        uint16_t u2;
        
        //--------------------------------------------------------------
        void set(int16_t x, int16_t y) {
            this->x = x;
            this->y = y;
        }
        
        //--------------------------------------------------------------
        void set(int16_t x, int16_t y, int16_t r, int16_t g, int16_t b, int16_t a) {
            this->x = x;
            this->y = y;
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
        
        
        //--------------------------------------------------------------
        // set color and position mapped from custom range (defaults to normalized)
        void set(const glm::vec3& p, ofFloatColor c, const glm::vec3& pmin = {0,0,0}, const glm::vec3& pmax = {1,1,1}) {
            set(
                ofMap(p.x, pmin.x, pmax.x, kIldaMinPoint, kIldaMaxPoint),
                ofMap(p.y, pmin.y, pmax.y, kIldaMinPoint, kIldaMaxPoint),
                c.r * kIldaMaxIntensity,
                c.g * kIldaMaxIntensity,
                c.b * kIldaMaxIntensity,
                c.a * kIldaMaxIntensity
                );
        }
        
        //--------------------------------------------------------------
        // set position mapped from custom range (defaults to normalized)
        void setPosition(glm::vec3 p, glm::vec3 pmin = {0,0,0}, glm::vec3 pmax = {1,1,1}) {
            set(
                ofMap(p.x, pmin.x, pmax.x, kIldaMinPoint, kIldaMaxPoint),
                ofMap(p.y, pmin.y, pmax.y, kIldaMinPoint, kIldaMaxPoint)
                );
        }
        
        
        //--------------------------------------------------------------
        // gets position of point mapped to desired range (defaults to normalized)
        glm::vec3 getPosition(glm::vec3 pmin = {0,0,0}, glm::vec3 pmax = {1,1,1}) {
            return glm::vec3(
                           ofMap(x, kIldaMinPoint, kIldaMaxPoint, pmin.x, pmax.x),
                           ofMap(y, kIldaMinPoint, kIldaMaxPoint, pmin.y, pmax.y),0
                           );
        }
        
    };
}
