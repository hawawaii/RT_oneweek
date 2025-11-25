#ifndef QUAD_H
#define QUAD_H

#include "hittable.h"
#include "vec3.h"

class quad : public hittable {
  public:
    quad(const point3& _Q, const vec3& _u, const vec3& _v, shared_ptr<material> _mat)
      : Q(_Q), u(_u), v(_v), mat(_mat)
    {
        auto n = cross(u, v);
        normal = unit_vector(n);
        D = dot(normal, Q);
        w = n / dot(n, n);
    }

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        auto denom = dot(normal, r.direction());

        // 광선이 평면과 평행한 경우
        if (fabs(denom) < 1e-8)
            return false;

        // 평면 교차점 t 계산
        auto t = (D - dot(normal, r.origin())) / denom;
        if (!ray_t.contains(t))
            return false;

        // 교차점 P 구하기
        auto intersection = r.at(t);
        vec3 planar_hitpt_vector = intersection - Q;
        
        // 평면 좌표계(alpha, beta) 계산
        auto alpha = dot(w, cross(planar_hitpt_vector, v));
        auto beta = dot(w, cross(u, planar_hitpt_vector));

        // 사각형 내부인지 확인
        if (!is_interior(alpha, beta, rec))
            return false;

        // 히트 레코드 기록
        rec.t = t;
        rec.p = intersection;
        rec.mat = mat;
        rec.set_face_normal(r, normal);

        return true;
    }

    virtual bool is_interior(double a, double b, hit_record& rec) const {
        // [0, 1] 범위를 벗어나면 사각형 밖임
        if ((a < 0) || (1 < a) || (b < 0) || (1 < b))
            return false;
        return true;
    }

  private:
    point3 Q;
    vec3 u, v;
    shared_ptr<material> mat;
    vec3 w;
    vec3 normal;
    double D;
};

#endif