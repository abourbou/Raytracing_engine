
#include "Sphere.hpp"

float Sphere::intersect(const Ray& ray) {

    float t0, t1;

    // Find the geometric solution
    Eigen::Vector3f L = this->Center - ray.Origin;
    float tca = L.dot(ray.Direction);

    if (tca < 0)
        return -1.;
    float d2 = L.dot(L) - tca * tca;
    if (d2 > this->Radius * this->Radius)
        return -1.;
    float thc = sqrtf(this->Radius * this->Radius - d2);
    t0 = tca - thc;
    t1 = tca + thc;

    // Return the smallest positive value if it exists
    if (t0 > t1)
        std::swap(t0, t1);
    return (t0 > 0. ? t0 : t1);
}
