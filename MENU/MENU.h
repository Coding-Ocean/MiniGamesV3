#pragma once
#include <string>
#include "../MAIN/LEVEL.h"
class MENU :
    public LEVEL
{
public:
    MENU(class MAIN* main) :LEVEL(main) {};
    ~MENU() {};
    void create();
    void proc();
    void destroy();
private:
    //�C���f�b�N�X���}�E�X�ŕ��ѕς��邽�߂̕ϐ�
    char* Indices;
    int NumIndices;
    int IndexMouseHolding;
    std::string* Titles;

    int Rows, Cols;
    float TileH, TileW;
    float OfstX, OfstY;
    float DivHue;
    float SizeText;
};

