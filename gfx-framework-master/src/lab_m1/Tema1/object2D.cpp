#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
    {
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, width, 0), color),
		VertexFormat(corner + glm::vec3(0, width, 0), color)
	};

	Mesh* rectangle = new Mesh(name);
	std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
		rectangle->SetDrawMode(GL_LINE_LOOP);
	}
    else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	rectangle->InitFromData(vertices, indices);
	return rectangle;
}   

Mesh* object2D::CreatePlant(const std::string& name, glm::vec3 leftBottomCorner, float rhombside, float length, float width, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
    {
		VertexFormat(corner + glm::vec3(0, 2 * rhombside, 0), color), //0
		VertexFormat(corner + glm::vec3(rhombside, 0, 0), color), //1
		VertexFormat(corner + glm::vec3(0, -2 * rhombside, 0), color), //2
		VertexFormat(corner + glm::vec3(-rhombside, 0, 0), color), //3

		VertexFormat(corner + glm::vec3(0,-rhombside/2,0), color), //4
		VertexFormat(corner + glm::vec3(length, -rhombside/2, 0), color), //5
		VertexFormat(corner + glm::vec3(length, rhombside/2, 0), color), //6
		VertexFormat(corner + glm::vec3(0, rhombside/2, 0), color) //7
	};
	

	Mesh* plant = new Mesh(name);
	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0,
		4,5,6,
		6,7,4};

    if (!fill) {
		plant->SetDrawMode(GL_LINE_LOOP);
	}
    else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	plant->InitFromData(vertices, indices);
	return plant;
}

Mesh* object2D::CreateStar(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
	VertexFormat(corner + glm::vec3(0,length + length / 2+length/4, 0), color), // 0
	VertexFormat(corner + glm::vec3(length / 2, length / 2 , 0), color), // 1
	VertexFormat(corner + glm::vec3(length + length/2 +length / 4, length/2, 0), color), // 2
	VertexFormat(corner + glm::vec3(length / 2+ length/4, -length / 4, 0), color), // 3
	VertexFormat(corner + glm::vec3(length + length/4 , -length - length/2, 0), color), // 4
	VertexFormat(corner + glm::vec3(0, -length/2 - length/4, 0), color), // 5
	VertexFormat(corner + glm::vec3(-length - length/4 ,-length - length / 2, 0), color), // 6
	VertexFormat(corner + glm::vec3(-length / 2-length/4, -length / 4, 0), color), // 7
	VertexFormat(corner + glm::vec3( - length - length / 2- length / 4, length / 2, 0), color), // 8
	VertexFormat(corner + glm::vec3(-length / 2, length / 2, 0), color) // 9
	};

		Mesh* star = new Mesh(name);
		std::vector<unsigned int> indices = {
			0,1,9,
			1,2,3,
			3,4,5,
			5,6,7,
			7,8,9,
			7,9,3,
			5,7,3,
			3,9,1
		};


		if (!fill) {
			star->SetDrawMode(GL_LINE_LOOP);
		}
		else {
			// Draw 2 triangles. Add the remaining 2 indices
			indices.push_back(0);
			indices.push_back(2);
		}

		star->InitFromData(vertices, indices);
		return star;
		

}

Mesh* object2D::CreateHex(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, glm::vec3 color2, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	float length2 = length / 1.5;
	glm::vec3 center = corner + glm::vec3(length2/8, length2 / 4, 0);

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner + glm::vec3(-length / 2, 0, 0), color), // 0
		VertexFormat(corner + glm::vec3(-length / 4, length / 2, 0), color), // 1
		VertexFormat(corner + glm::vec3(length / 4, length / 2, 0), color), // 2
		VertexFormat(corner + glm::vec3(length / 2, 0, 0), color), // 3
		VertexFormat(corner + glm::vec3(length / 4, -length / 2, 0), color), // 4
		VertexFormat(corner + glm::vec3(-length / 4, -length / 2, 0), color), // 5
		VertexFormat(corner + glm::vec3(-length2 / 2, 0, 10), color2), // 0
		VertexFormat(corner + glm::vec3(-length2 / 4, length2 / 2, 10), color2), // 1
		VertexFormat(corner + glm::vec3(length2 / 4, length2 / 2, 10), color2), // 2
		VertexFormat(corner + glm::vec3(length2 / 2, 0, 10), color2), // 3
		VertexFormat(corner + glm::vec3(length2 / 4, -length2 / 2, 10), color2), // 4
		VertexFormat(corner + glm::vec3(-length2 / 4, -length2 / 2, 10), color2), // 5
	};

	Mesh* hex = new Mesh(name);
	std::vector<unsigned int> indices = {
		0,1,2,
		0,2,3,
		0,3,5,
		5,3,4,

		6,7,8,
		6,8,9,
		6,9,11,
		11,9,10,


	};
	if (!fill) {
		hex->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	hex->InitFromData(vertices, indices);
	return hex;
}

Mesh* object2D::CreateHeart(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;


	std::vector<VertexFormat> vertices =
	{
		
		
		VertexFormat(corner, color), // 0
		VertexFormat(corner + glm::vec3(length / 4, length / 4, 0), color), // 1
		VertexFormat(corner + glm::vec3(length / 2 + length / 8, 0, 0), color), // 2
		VertexFormat(corner + glm::vec3(0, -length, 0), color), // 3
		VertexFormat(corner + glm::vec3(-length / 2 - length / 8, 0, 0), color), // 4
		VertexFormat(corner + glm::vec3(-length / 4, length / 4, 0), color), // 5
		VertexFormat(corner + glm::vec3(length / 4, 0, 0), color), //6
		VertexFormat(corner + glm::vec3(-length / 4, 0, 0), color), //7
		
	};

	Mesh* heart = new Mesh(name);
	std::vector<unsigned int> indices = {
		0,1,6,
		6,1,2,
		4,5,7,
		7,5,0,
		4,0,3,
		0,2,3,


	};
	if (!fill) {
		heart->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	heart->InitFromData(vertices, indices);
	return heart;
}