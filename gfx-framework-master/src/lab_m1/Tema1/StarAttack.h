#include "components/simple_scene.h"
#include <string>

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

namespace m1 {

	class StarAttack
	{
	public:
		float x, y;
		bool is_alive;
		Mesh* mesh;
		int mode;
		float angularStep;
		float translateX, translateY;
		float timer;
		
		StarAttack(int mode) {
			if (mode == 1) {
				this->mesh = object2D::CreateStar("starAttack", glm::vec3(0, 0, 36), 12, glm::vec3(1, 0.6, 0), true);
			}
			else if (mode == 2) {
				this->mesh = object2D::CreateStar("starAttack", glm::vec3(0,0 , 36), 12, glm::vec3(0, 0, 1), true);
			}
			else if (mode == 3) {
				this->mesh = object2D::CreateStar("starAttack", glm::vec3(0, 0, 36), 12, glm::vec3(1, 1, 0), true);
			}
			else {
				this->mesh = object2D::CreateStar("starAttack", glm::vec3(0, 0, 36), 12, glm::vec3(0.5, 0, 0.5), true);
			}
			this->is_alive = true;
			this->mode = mode;
		}
		~StarAttack() {
			delete this->mesh;
		}
		bool IsInStar(float x, float y) {

			if (x >= this->x && x <= this->x + 85 && 720 - y >= this->y && 720 - y <= this->y + 85) {
				return true;
			}
			return false;
		}
	};
}