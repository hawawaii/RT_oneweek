#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"
#include "quad.h"

int main() {
    hittable_list world;

    // 난반사
    //auto material_lamb_01 = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    //auto material_lamb_02 = make_shared<lambertian>(color(0.1, 0.2, 0.5));

    // 유전체
    //auto material_diel_01   = make_shared<dielectric>(1.50); 
    //auto material_dielbub_01 = make_shared<dielectric>(1.00 / 1.50);

    // 금속
    //auto material_metal_01  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0); 

    // 구체
    //world.add(make_shared<sphere>(point3( 0.0, 0.0, 0.0), 100.0, material_));

    // 사각평면
    //world.add(make_shared<quad>(point3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0), material_));
    

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 50;
    cam.lookfrom = point3(2,2,1);
    cam.lookat   = point3(0,0,-1);
    // 머리위
    cam.vup      = vec3(0,1,0);

    cam.render(world);
}