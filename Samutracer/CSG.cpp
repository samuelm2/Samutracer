#include "pch.h"
#include "CSG.h"



bool CSG::hit(const Ray & r, double & min_t, HitInfo & hit_info) const
{
	HitInfo hit1 = HitInfo(hit_info);
	glm::vec2 hit_t1 = glm::vec2(-1, -1);
	glm::vec2 hit_t2 = glm::vec2(-1, -1);

	bool did_hit1 = o1->hit2(r, hit_t1, hit1);
	

	HitInfo hit2 = HitInfo(hit_info);
	bool did_hit2 = o2->hit2(r, hit_t2, hit2);

	if (did_hit1) {
		if (did_hit2) {
			if (op == INTERSECTION) {
				if (hit_t1.x < hit_t2.x) {
					min_t = hit_t1.x;
					hit_info = hit1;
				}
				else {
					min_t = hit_t2.x;
					hit_info = hit2;
				}
				return true;
			}
			else if (op == SUBTRACTION) {

				if (hit_t1.x < hit_t2.x || hit_t2.y < hit_t1.x) {
					min_t = hit_t1.x;
					hit_info = hit1;
					return true;
				}
				else if (hit_t2.x < hit_t1.x && hit_t1.y < hit_t2.y) {
					return false;
				}
				else if (hit_t2.x < hit_t1.x && hit_t1.x < hit_t2.y && hit_t2.y < hit_t1.y) {
					min_t = hit_t2.y;
					hit_info = hit2;
					hit_info.normal = -hit2.normal2;
				}
				//if (hit_t2.y < hit_t1.x) {
					//min_t = hit_t2.y;
					//hit_info = hit2;
					//hit_info.normal = -hit2.normal2;
					
				//}
				//else {
				//	min_t = hit_t1.x;
				//	hit_info = hit1;
				//}
				return true;
			}
		}
		else if (op == SUBTRACTION) {
			min_t = hit_t1.x;
			hit_info = hit1;
			return true;
		}
	}

	return false;
}

bool CSG::shadow_hit(const Ray & r, double & min_t) const
{
	return false;
}

BoundingBox CSG::getBBox() const
{
	return o2->getBBox().union_boxes(o1->getBBox());
}


CSG::CSG()
{
}


CSG::~CSG()
{
}
