#pragma once
#include <string>
#include "../MAIN/LEVEL.h"
class MENU :
    public LEVEL
{
public:
    MENU(class MAIN* main) :LEVEL(main) {};
    ~MENU() {};
    int create();
    void proc();
    void destroy();
private:
    //���x���C���f�b�N�X�̈ʒu���}�E�X�ŕς���
    void ChangePosition();
    char* Indices;
    int NumIndices;
    int IndexMouseHolding;
    int IndexMouseOver;
    std::string* Titles;
    void Draw();
    int Rows, Cols;
    float TileH, TileW;
    float OfstX, OfstY;
    float DivHue;
    float SizeText;
};

