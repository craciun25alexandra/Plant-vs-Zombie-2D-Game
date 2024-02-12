#include "components/simple_scene.h"
#include <string>

#include <vector>
#include <iostream>

#include "Hex.h"


#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

namespace m1 {

	class Plant
	{
	public:
		float x, y,z;
		int mode;
		int stars; // nr se stele necesare pentru a fi creata planta
		float SquareSide2, SquareSide1; //lungimile
		bool is_alive;
		Hex* is_attacking = NULL; // hexul pe care il ataca
		std::string square_name;
		float scale = 1;
		float timer = 0;
		float last_shot = 0;
		std::string name;
		Mesh* mesh;
		Plant(int mode, float x, float y, float SquareSide1, float SquareSide2, std::string name) {
			this->mode = mode;
			this->SquareSide1 = SquareSide1;
			this->SquareSide2 = SquareSide2;
			this->name = name;
			if (mode == 1) {
				this->mesh = object2D::CreatePlant(name, glm::vec3(x, y, 25), SquareSide1, SquareSide2, SquareSide1, glm::vec3(1, 0.6, 0), true);
				this->stars = 1;
			}
			else if (mode == 2) {
				this->mesh = object2D::CreatePlant(name, glm::vec3(x, y, 25), SquareSide1, SquareSide2, SquareSide1, glm::vec3(0, 0, 1), true);
				this->stars = 2;

			}
			else if (mode == 3) {
				this->mesh = object2D::CreatePlant(name, glm::vec3(x, y, 25), SquareSide1, SquareSide2, SquareSide1, glm::vec3(1, 1, 0), true);
				this->stars = 2;
			}
			else {
				this->mesh = object2D::CreatePlant(name, glm::vec3(x, y, 25), SquareSide1, SquareSide2, SquareSide1, glm::vec3(0.5, 0, 0.5), true);
				this->stars = 3;
			}
		}

		void UpdatePosition(float x, float y) {

			this->x = x;
			this->y = y;
		
		}

		bool IsInPlant(float x, float y) {
			if (x == this->x + SquareSide1 / 2  && y == this->y + SquareSide2 / 2) {
				return true;
			}
			return false;
		}
		
	};

}