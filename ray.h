#pragma once
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        ray() {}

        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        //접근자함수. private 읽기
        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        //광선 위 점 계산
        point3 at(double t) const {
            return orig + t * dir;
        }

    private:
        point3 orig; //광선 시작점
        vec3 dir; //광선 방향
};


#endif