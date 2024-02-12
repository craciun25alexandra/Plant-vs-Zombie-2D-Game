#include "components/simple_scene.h"
#include <string>

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

namespace m1 {

	class Hex {
	public:
		int mode;
		int mode2; //pentru a si schimba culoarea circular la hit uri
		float x, y;
		std::string name;
		float scale = 1;
		Mesh* mesh;
		bool is_alive;
		float translateX, translateY;
		int hits;
		Hex(int mode, float x, float y)
		{
			this->mode = mode;
			this->is_alive = true;
			this->x = x;
			this->y = y;
			this->hits = 3;
			if (mode == 1) {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(1, 0.6, 0), glm::vec3(0, 0, 1), true);
				this->mode2 = 2;
			}
			else if (mode == 2) {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(0, 0, 1), glm::vec3(1, 1, 0), true);
				this->mode2 = 3;
			}
			else if (mode == 3) {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(1, 1, 0), glm::vec3(0.5, 0, 0.5), true);
				this->mode2 = 4;	
			}
			else {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(0.5, 0, 0.5), glm::vec3(1, 0.6, 0), true);
				this->mode2 = 1;
			}
		}
		~Hex() {
			delete this->mesh;
		}
		void UpdateColor() {
			//se creeaza meshuri cu mode2 colors si se da swich la moduri
			if (this->mode2 == 1) {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(1, 0.6, 0), glm::vec3(0, 0, 1), true);
				this->mode2 = 2;
				this->mode = 1;
			}
			else if (this->mode2 == 2) {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(0, 0, 1), glm::vec3(1, 1, 0), true);
				this->mode2 = 3;
				this->mode = 2;
			}
			else if (this->mode2 == 3) {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(1, 1, 0), glm::vec3(0.5, 0, 0.5), true);
				this->mode2 = 4;
				this->mode = 3;
			}
			else if (this->mode2 == 4) {
				this->mesh = object2D::CreateHex(name, glm::vec3(x, y, 26), 100, glm::vec3(0.5, 0, 0.5), glm::vec3(1, 0.6, 0), true);
				this->mode2 = 1;
				this->mode = 4;
			}
		}
    };
}