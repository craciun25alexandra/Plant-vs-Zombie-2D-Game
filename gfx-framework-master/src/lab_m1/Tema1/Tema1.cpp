#include "lab_m1/Tema1/Tema1.h"
#include<chrono>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;

Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::AddSquareList(Square* square) {
	squares[square->name] = square;
}

void Tema1::AddPlantList(Plant* plant) {
	plants[plant->name] = plant;
}


void Tema1::Init()
{
    angularStep = 0; //init pentru rotate
    time = 0; //init pentru timp pentru generare random
    lives = 3;
    glm::vec2 resolution = window->GetResolution();
    resolutionx = (int)resolution.x;
    resoltuiony = (int)resolution.y;
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = resolution.x/10;
    nr_stars = 8;
    corner += 10;
    angularStep = 0;
    new_plant = NULL;
    button_one_pressed = false;
    plantsAdded = 1;

    Mesh* rectangle = object2D::CreateRectangle("rectangle", corner, squareSide/2, squareSide*3.5, glm::vec3(1, 0, 0), true);
    AddMeshToList(rectangle);
    rectangle_x = corner.x + squareSide/2;

    glm::vec3 color1= glm::vec3(0.2, 0.8, 0.2);
    glm::vec3 color2 = glm::vec3(0, 0, 0);

    Square* square1 = new Square("square1", corner, squareSide, color1, true);
    AddMeshToList(square1->mesh);
    square1->corner = glm::vec2(0.7 * squareSide, 0);
    square1->corner += 10;
    AddSquareList(square1);

    Square* square2 = new Square("square2", corner, squareSide, color1, true);
    square2->corner = glm::vec2(square1->corner + glm::vec2(squareSide * 1.25,0));
    AddSquareList(square2);

    Square* square3 = new Square("square3", corner, squareSide, color1, true);
    square3->corner = glm::vec2(square2->corner + glm::vec2(squareSide * 1.25, 0));
    AddSquareList(square3);

    Square* square4 = new Square("square4", corner, squareSide, color1, true);
    square4->corner = glm::vec2(squareSide * 0.7, squareSide * 1.25);
    square4->corner += 10;
    AddSquareList(square4);

    Square* square5 = new Square("square5", corner, squareSide, color1, true);
    square5->corner = glm::vec2(square4->corner + glm::vec2(squareSide * 1.25, 0));
    AddSquareList(square5);

    Square* square6 = new Square("square6", corner, squareSide, color1, true);
    square6->corner = glm::vec2(square5->corner + glm::vec2(squareSide * 1.25, 0));
    AddSquareList(square6);
    

    Square* square7 = new Square("square7", corner, squareSide, color1, true);
    square7->corner = glm::vec2(squareSide * 0.7, squareSide * 2.5);
    square7->corner += 10;
    AddSquareList(square7);

    Square* square8 = new Square("square8", corner, squareSide, color1, true);
    square8->corner = glm::vec2(square7->corner + glm::vec2(squareSide * 1.25, 0));
    AddSquareList(square8);

    Square* square9 = new Square("square9", corner, squareSide, color1, true);
    square9->corner = glm::vec2(square8->corner + glm::vec2(squareSide * 1.25, 0));
    AddSquareList(square9);

    Mesh* heart = object2D::CreateHeart("heart", corner, squareSide/1.5, glm::vec3(1, 0, 0), true);
    AddMeshToList(heart);

    Square* square_bar1 = new Square("square_bar1", corner, squareSide, color2, false);
    AddMeshToList(square_bar1->mesh);
    square_bar1->corner = glm::vec2(squareSide * 0.3, resolution.y - squareSide * 1.25);
    AddSquareList(square_bar1);

    Square * square_bar2 = new Square("square_bar2", corner, squareSide, color2, false);
    square_bar2->corner = glm::vec2(square_bar1->corner + glm::vec2(squareSide * 1.4, 0));
    AddSquareList(square_bar2);

    Square* square_bar3 = new Square("square_bar3", corner, squareSide, color2, false);
    square_bar3->corner = glm::vec2(square_bar2->corner + glm::vec2(squareSide * 1.4, 0));
    AddSquareList(square_bar3);

    Square* square_bar4 = new Square("square_bar4", corner, squareSide, color2, false);
    square_bar4->corner = glm::vec2(square_bar3->corner + glm::vec2(squareSide * 1.4, 0));
    AddSquareList(square_bar4);

    Mesh* plant1 = object2D::CreatePlant("plant1", corner, squareSide/4, squareSide/2, squareSide/4, glm::vec3(1, 0.6, 0), true);
    AddMeshToList(plant1);

    Mesh* plant2 = object2D::CreatePlant("plant2", corner, squareSide/4, squareSide/2, squareSide/4, glm::vec3(0, 0, 1), true);
    AddMeshToList(plant2);

    Mesh* plant3 = object2D::CreatePlant("plant3", corner, squareSide/4, squareSide/2, squareSide/4, glm::vec3(1, 1, 0), true);
    AddMeshToList(plant3);

    Mesh* plant4 = object2D::CreatePlant("plant4", corner, squareSide/4, squareSide/2, squareSide/4, glm::vec3(0.5, 0, 0.5), true);
    AddMeshToList(plant4);

    Mesh*star = object2D::CreateStar("star", corner, squareSide/10, glm::vec3(0.5, 0.5, 0.5));
    AddMeshToList(star);
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Gri neutru
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
    time += deltaTimeSeconds;
    if (time >= rand() % 4 + 3) { //timp random intre 3 si 7 secunde
        time = 0;
        if (stars.size() < 12) { //maxim 12 stele pe ecran deodata

            Star* newStar = new Star(0,0);
            newStar->translateX = rand() % (resolutionx-100) + 70; //coordonate random
            newStar->translateY = rand() % (resoltuiony-100) + 50; //+lungime pt a incapea integral
            stars.push_back(newStar);
        }
        if (hexagons.size() < 2) {
            int nr = rand() % 9 + 1; //square ales random
            std::string square_name = "square" + std::to_string(nr);
            Hex* newHex = new Hex(nr % 4 + 1, 0, 0); //culoare aleasa random
            newHex->translateX = resolutionx - 100; //de la capatul drept al imaginii
            //inaltimea patratului ales
            newHex->translateY = squares[square_name]->corner.y + squares[square_name]->squareSide / 2;
            hexagons.push_back(newHex);
        }
    }

    modelMatrix = glm::mat3(1);
    glm::ivec2 resolution = window->GetResolution();
    squareSide = resolution.x / 10;
    //desenare gui joc
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(0.7 * squareSide, 0);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(1.25 * squareSide, 0);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(1.25 * squareSide, 0);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide * 0.7, squareSide * 1.25);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.25, 0);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.25, 0);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide * 0.7, squareSide * 2.50);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.25, 0);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.25, 0);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide * 0.3, resolution.y - squareSide * 1.25);
    RenderMesh2D(squares["square_bar1"]->mesh, shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.4, 0);
    RenderMesh2D(squares["square_bar1"]->mesh, shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.4, 0);
    RenderMesh2D(squares["square_bar1"]->mesh, shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.4, 0);
    RenderMesh2D(squares["square_bar1"]->mesh, shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide * 0.15, 0);
    modelMatrix *= transform2D::Translate(squareSide * 0.3, resolution.y - squareSide * 1.25 - squareSide / 5);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.4, 0);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide / 3 + 5, 0);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(-squareSide / 3 - 5 + squareSide * 1.4, 0);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide / 3 + 5, 0);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(-squareSide / 3 - 5 + squareSide * 1.4, 0);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide / 3 + 5, 0);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide / 3 + 5, 0);
    RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide * 0.7, resolution.y - squareSide / 1.3);
    RenderMesh2D(meshes["plant1"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.4, 0);
    RenderMesh2D(meshes["plant2"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.4, 0);
    RenderMesh2D(meshes["plant3"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transform2D::Translate(squareSide * 1.4, 0);
    RenderMesh2D(meshes["plant4"], shaders["VertexColor"], modelMatrix);


    modelMatrix = glm::mat3(1);
    //randare vieti
    if (lives >= 1) {
        modelMatrix *= transform2D::Translate(squareSide * 6.8, resolution.y - squareSide/2);
        RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
    }  

    for (int i = 2; i <= lives; i++) {
        modelMatrix *= transform2D::Translate(squareSide, 0);
        RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
    }

    modelMatrix = glm::mat3(1);
    //drag and drop; plimbarea plantei dupa cursor pana e pusa
    if (button_one_pressed == true && new_plant != NULL) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(new_plant->x, new_plant->y);
        RenderMesh2D(new_plant->mesh, shaders["VertexColor"], modelMatrix);
    }

    //randarea stelelor random
    for (auto star : stars)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(star->translateX, star->translateY);
        RenderMesh2D(star->mesh, shaders["VertexColor"], modelMatrix);

    }

    modelMatrix = glm::mat3(1);
    for (auto plant = plants.begin(); plant != plants.end(); plant++) {
        if (plant->second->is_alive == true) {
            //fiecare planta pusa si in viata e randata
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(plant->second->x, plant->second->y);
            RenderMesh2D(plant->second->mesh, shaders["VertexColor"], modelMatrix);
        }
        else if (plant->second->scale >= 0) {
            //daca nu e in viata, trebuie scalata pana dispare
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(plant->second->x, plant->second->y);
            modelMatrix *= transform2D::Scale(plant->second->scale, plant->second->scale);
            plant->second->scale -= deltaTimeSeconds * 3;
			RenderMesh2D(plant->second->mesh, shaders["VertexColor"], modelMatrix);
            //patratul devine disponibil
            squares[plant->second->square_name]->occupied = false;
	    }
    }
    modelMatrix = glm::mat3(1);
    for (auto starAt : starAttack) {
        modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(starAt->translateX, starAt->translateY);
        modelMatrix *= transform2D::Rotate(starAt->angularStep);
        RenderMesh2D(starAt->mesh, shaders["VertexColor"], modelMatrix);
        starAt->angularStep -= deltaTimeSeconds; //rotatie
        starAt->translateX += deltaTimeSeconds * 100; //miscare
        for (auto hex : hexagons) {
            if (hex->is_alive == true) {
                float r1 = 50; //raza hexa
				float r2 = 35; //raza glont
				//coleziune hexagon-glont
                if (r1 + r2 > glm::distance(glm::vec2(starAt->translateX, starAt->translateY),
                    glm::vec2(hex->translateX, hex->translateY)) && hex->mode == starAt->mode) {
                    if (hex->hits > 1) {
                        hex->hits--;
                        hex->~Hex(); //detele meshul curent
                        hex->UpdateColor(); //pentru bonus; hex schimba culoarea la hit
                    }
					else
                        hex->is_alive = false;
                    starAt->is_alive = false;
					break;
				}
            }
        }
    }
    for (auto hex : hexagons) {
        if (hex->is_alive) {
            for (auto plant : plants) {
                if (plant.second->is_attacking == hex)
                    plant.second->timer+= 0.5 * deltaTimeSeconds; //viteza se mareste doar in functie de hex ul atacat
                 if (plant.second->y == hex->translateY && plant.second->is_alive == true && plant.second->mode == hex->mode
            && (plant.second->is_attacking == NULL || plant.second->timer - plant.second->last_shot > 0)) {
                    if (plant.second->is_attacking == NULL) { //nu ataca niciuna
                        plant.second->is_attacking = hex;
                        if (plant.second->last_shot) //daca planta nu mai atacase, trebuie sa atace
                            break;                   //iar daca da, trebuie sa astepte sa fie diferenta de timp
                    }
                    plant.second->last_shot = 1; //planta a atacat
                    plant.second->timer = 0; //resetare timer
                    StarAttack* newStar = new StarAttack(hex->mode); //atac
                    newStar->translateX = squares[plant.second->square_name]->corner.x +
                        squares[plant.second->square_name]->squareSide / 2;
                    newStar->translateY = hex->translateY;
                    newStar->angularStep = 0;
                    starAttack.push_back(newStar);
                 }
                if (plant.second->is_alive == true) {
                    float r1 = squareSide / 2;
                    float r2 = 50;
                    //coleziune planta-hexagon
                    if (r1 + r2 > glm::distance(glm::vec2(hex->translateX, hex->translateY), glm::vec2(plant.second->x, plant.second->y))) {
                        plant.second->is_alive = false;
                        break;
                    }
                }
            }
            //randare hexagoane in viata
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(hex->translateX, hex->translateY);
            RenderMesh2D(hex->mesh, shaders["VertexColor"], modelMatrix);
            hex->translateX -= deltaTimeSeconds * 40;
            //verificare daca a ajuns la inceputul bazei
            if (hex->translateX <= rectangle_x+ squareSide / 4+10) {
                lives--;
                hex->is_alive = false;
            }
        }
        //cele !alive trebuie scalate pana dispar
        else if (hex->scale >= 0) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(hex->translateX, hex->translateY);
            modelMatrix *= transform2D::Scale(hex->scale, hex->scale);
            hex->scale -= deltaTimeSeconds * 3;
            RenderMesh2D(hex->mesh, shaders["VertexColor"], modelMatrix);
        }

    }

    //stergere stele care au atacat si lovit hexagonul
    for (auto starAt : starAttack) {
        if (starAt->is_alive == false) {
            starAt->~StarAttack();
			starAttack.remove(starAt);
			break;
		}
	}
    
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(squareSide * 6.3 + 10, resolution.y - squareSide * 1.3 - 10);
    //randare stele disponibile de consumat
    for (int i = 1; i <= nr_stars; i++) {
        RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
        modelMatrix *= transform2D::Translate(squareSide / 3+5, 0);
    }

    for (auto hex : hexagons) {
        if (!hex->is_alive && hex->scale < 0) { //daca hexagonul a disparut
            for(auto plant : plants)
                if (plant.second->is_attacking == hex) { //daca planta ataca hexagonul, nu mai are ce ataca
                    plant.second->is_attacking = NULL;
                }
            hexagons.remove(hex); //stergere hexagon
            break;
        }
    }
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    //drag & drop, actualizarea coord dupa cursor
    if (button_one_pressed == true && new_plant!=NULL) {
        new_plant->UpdatePosition(mouseX, 720 - mouseY);
    }
   
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    Square* square_bar1 = squares["square_bar1"];
    Square* square_bar2 = squares["square_bar2"];
    Square* square_bar3 = squares["square_bar3"];
    Square* square_bar4 = squares["square_bar4"];

    if (button == 1 && button_one_pressed==false) {
        bool ok = 0; //in cazul unor suprapuneri de pozitii, pentru ce a fost utilizat clickul

        for (auto star : stars) {
            if (star->IsInStar(mouseX, mouseY) == true) {
                nr_stars++; //a fost culesa o stea
                star->~Star(); //stergere mesh
                stars.remove(star); //trebuie stearsa si din lista
                ok = 1; //clickul a fost luat steaua
                break;
            }
        }
        if (!ok) { //daca nu a fost pentru stea
            button_one_pressed = true;
            string name = "plant" + std::to_string(plantsAdded);
            //primul patrat, plant de tip 1
            if (nr_stars >= 1 && mouseX >= square_bar1->corner.x && mouseX <= square_bar1->corner.x + squareSide
                && 720 - mouseY >= square_bar1->corner.y && 720 - mouseY <= square_bar1->corner.y + squareSide) {
                plantsAdded++;
                //creare planta alaturi de coord
                Plant* newPl = new Plant(1, 0, 0, squareSide / 4, squareSide / 2, name);
                newPl->x = mouseX;
                newPl->y = 720 - mouseY;
                new_plant = newPl;

            }
            //al doilea patrat, plant de tip 2
            else if (nr_stars >= 2 && mouseX >= square_bar2->corner.x && mouseX <= square_bar2->corner.x + squareSide &&
                720 - mouseY >= square_bar2->corner.y && 720 - mouseY <= square_bar2->corner.y + squareSide) {
                plantsAdded++;
                Plant* newPl = new Plant(2, 0, 0, squareSide / 4, squareSide / 2, name);
                newPl->x = mouseX;
                newPl->y = 720 - mouseY;
                new_plant = newPl;
            }
            else if (nr_stars >= 2 && mouseX >= square_bar3->corner.x && mouseX <= square_bar3->corner.x + squareSide &&
                720 - mouseY >= square_bar3->corner.y && 720 - mouseY <= square_bar3->corner.y + squareSide) {
                plantsAdded++;
                Plant* newPl = new Plant(3, 0, 0, squareSide / 4, squareSide / 2, name);
                newPl->x = mouseX;
                newPl->y = 720 - mouseY;
                new_plant = newPl;
            }
            else if (nr_stars >= 3 && mouseX >= square_bar4->corner.x && mouseX <= square_bar4->corner.x + squareSide &&
                720 - mouseY >= square_bar4->corner.y && 720 - mouseY <= square_bar4->corner.y + squareSide) {
                plantsAdded++;
                Plant* newPl = new Plant(4, 0, 0, squareSide / 4, squareSide / 2, name);
                newPl->x = mouseX;
                newPl->y = 720 - mouseY;
                new_plant = newPl;
            }
        }
	}
    else if (button == 2) {
            for (int i = 1; i <= 9; i++) {
                Square* square = squares["square" + std::to_string(i)];
                if (square->IsInSquare(mouseX, mouseY) == true && square->occupied == true) {
                    plants[square->plant_name]->is_alive = false; //planta trebuie sa moara
                    square->occupied = false; //patratul devine disponibil

                }
            }
    }
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    if(button == 1) {
		button_one_pressed = false; //clickul a fost eliberat, nu mai trebuie urmarit cursorul
        for (int i = 1; i <= 9 && new_plant != NULL; i++) {
            Square* square = squares["square" + std::to_string(i)];
            //daca ai nr de stele necesare, iar cursorul e pe un patrat disponibil, se pune planta
            if ( nr_stars >= new_plant->stars && square->occupied == false && square->IsInSquare(mouseX, mouseY) == true) {
				square->occupied = true;
                square->plant_name = new_plant->name;
                new_plant->square_name = square->name;
                new_plant->is_alive = true;
                new_plant->UpdatePosition(square->corner.x + squareSide / 2 - 10, square->corner.y +squareSide/2);
                AddPlantList(new_plant);
                nr_stars -= new_plant->stars;
                break;
			}
        }
        new_plant = NULL;
	}
}

