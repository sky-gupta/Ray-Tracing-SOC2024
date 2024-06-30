#ifndef MATERIAL_H
#define MATERIAL_H

#include <common_header.h>
#include<hittable.h>

class hit_record;

class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const {
        return false;
    }
};

class lambertian : public material {
  private:
    color albedo;
    double p;

  public:
    lambertian(const color &a, double p = 1.00) : albedo(a), p{p} {}

    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation,ray &scattered) const override {
        if (random_double() > p)
            return false;
        vec3 scatter_direction = rec.normal + random_unit_vector();

        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = {rec.p, scatter_direction};
        attenuation = albedo / p;
        return true;
    }
};

class metal : public material {
  public:
    metal(const color& albedo, double fuzz) : albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1) {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        reflected = unit_vector(reflected) + (fuzz * random_unit_vector());
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

  private:
    color albedo;
    double fuzz;
};
#endif