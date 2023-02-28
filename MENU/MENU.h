#pragma once
#include <string>
#include <memory>
#include "../MAIN/LEVEL.h"
class MENU :
    public LEVEL
{
public:
    MENU(class MAIN* main) :LEVEL(main) {
    };
    ~MENU() {};
    int create();
    void proc();
    void destroy();
private:
    void LoadIndices();
    void LoadTitleNames();
    //���x���C���f�b�N�X�̈ʒu���}�E�X�ŕς���
    void ChangePosition();
    char* Indices; 
    int NumIndices;
    int IndexMouseHolding;
    int IndexMouseOver;
    //���j���[�`��
    void Draw();
    int Rows, Cols;
    float TileH, TileW;
    float OfstX, OfstY;
    float DivHue;
    float SizeText;
    std::string* Titles;
};

