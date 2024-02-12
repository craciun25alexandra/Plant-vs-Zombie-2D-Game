#include "components/simple_scene.h"
#include <string>

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

namespace m1 {

	class Star
	{
	public:
		float x, y;
		float translateX, translateY;
		bool is_alive;
		Mesh* mesh;
		int mode;
		Star(float x, float y) {
			this->x = x;
			this->y = y;
			this->mesh = object2D::CreateStar("star", glm::vec3(x, y, 36), 20, glm::vec3(1, 0.5, 0.8), true);
			this->is_alive = true;
		}
		~Star() {
			delete this->mesh;
		}
		bool IsInStar(float x, float y) {

			if (x >= this->translateX-35 && x <= this->translateX +35 && 720 - y >= this->translateY-30 && 720 - y <= this->translateY + 35) {
				return true;
			}
			return false;
		}
	};
}