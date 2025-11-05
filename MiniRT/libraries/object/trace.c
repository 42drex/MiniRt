#include "object.h"

void	trace_nearest(const t_scene *scene, const t_point origin,
            const t_vector dir, t_hit *hit)
{
    int	i;

    hit->found = 0;
    hit->t = 0.0f;
    hit->object = NULL;
    if (scene->num_obj <= 0 || !scene->object)
        return ;
    i = 0;
    while (i < scene->num_obj)
    {
        t_intersect	cross;

        cross = sphere_cross(origin, dir, scene->object[i]);
        if (cross.touch)
        {
            float    t_candidate;

            t_candidate = 0.0f;
            if (cross.t[0] > EPSILON)
                t_candidate = cross.t[0];
            else if (cross.t[1] > EPSILON)
                t_candidate = cross.t[1];
            if (t_candidate > EPSILON)
            {
                if (!hit->found || t_candidate < hit->t)
                {
                    t_vector    offset;

                    hit->found = 1;
                    hit->t = t_candidate;
                    offset = dir;
                    offset.x *= t_candidate;
                    offset.y *= t_candidate;
                    offset.z *= t_candidate;
                    offset.w = 0.0f;
                    hit->point = new_point_forward(origin, offset);
                    hit->object = &scene->object[i];
                    hit->normal = vector_from_points(hit->point,
                            hit->object->origin);
                }
            }
        }
        i++;
    }
    if (hit->found)
        hit->normal = normalize(hit->normal);
}