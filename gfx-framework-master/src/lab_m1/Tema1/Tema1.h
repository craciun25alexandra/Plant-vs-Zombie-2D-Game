#pragma once

#include "components/simple_scene.h"
#include "Square.h"
#include "Plant.h"
#include "Star.h"
#include "StarAttack.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;

        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void AddSquareList(Square* square);
        void AddPlantList(Plant* plant);


    protected:
        glm::mat3 modelMatrix;
        int resolutionx, resoltuiony;;
        float angularStep;
        std::unordered_map<std::string, Square*> squares;
        bool button_one_pressed;
        Plant* new_plant;
        std::unordered_map<std::string, Plant*> plants;
        std::list<Star*> stars;
        std::list<Hex*> hexagons;
        std::list<StarAttack*>starAttack;
        int lives;
        float rectangle_x;
        float time;
        float squareSide;
        int plantsAdded;
        int nr_stars;


    };
}   // namespace m1
