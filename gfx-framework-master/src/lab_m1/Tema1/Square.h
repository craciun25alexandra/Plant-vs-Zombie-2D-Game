#include "components/simple_scene.h"
#include <string>

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

namespace m1 {

	class Square{
	public:
		glm::vec3 color;
		bool occupied; 
		bool fill;
		std::string name;
		float squareSide;
		glm::vec2 corner;
		std::string plant_name;
		Mesh* mesh;
		Square(std::string name, glm::vec3 center, float squareSide, glm::vec3 color, bool fill) {
			this->name = name;
			this->squareSide = squareSide;
			this->mesh = object2D::CreateSquare(name, center, squareSide, color, fill);
			this->occupied = false;
			this->fill = fill;
		}
		bool IsInSquare(float x, float y) {

			if (x >= this->corner.x+10 && x <= this->corner.x + this->squareSide+10 && 720 - y >= this->corner.y+10 && 720-y <= this->corner.y +10+ this->squareSide) {
				return true;
			}
			return false;
		}

	};
}