
#include "object.h"

void	*new_object(enum e_element type, void *raw)
{
    static const t_new_object	functions[MAX_ELEMENT_TYPE] = {
	[AmbientLight] = new_sphere,
	[Camera] = new_sphere,
	[Light] = new_sphere,
	[Plane] = new_sphere,
	[Sphere] = new_sphere,
	[Cylinder] = new_sphere};

    if (raw == NULL)
        return (NULL);
    return (functions[type](raw));
}

void	destory_object(void *object)
{
    static const t_destroy_object	functions[MAX_ELEMENT_TYPE] = {
	[AmbientLight] = destroy_sphere,
	[Camera] = destroy_sphere,
	[Light] = destroy_sphere,
	[Plane] = destroy_sphere,
	[Sphere] = destroy_sphere,
	[Cylinder] = destroy_sphere};
    t_obj *const   					obj = object;

    if (obj == NULL)
        return ;
    return (functions[obj->type](obj));
}

int	hit(void *object, t_ray *ray)
{
    static const t_hit	functions[MAX_ELEMENT_TYPE] = {
	[AmbientLight] = hit_sphere,
	[Camera] = hit_sphere,
	[Light] = hit_sphere,
	[Plane] = hit_sphere,
	[Sphere] = hit_sphere,
	[Cylinder] = hit_sphere};
    t_obj *const   		obj = object;

    return (functions[obj->type](obj, ray));
}
