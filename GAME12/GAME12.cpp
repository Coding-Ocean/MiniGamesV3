#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME12.h"

namespace GAME12
{
	int GAME::create()
	{
		//ここでは主に画像と音データを読み込む

		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。
		//シンプルなゲームなら次のように、ここで行ってもよい。
		/*Px = width / 2;
		Py = height / 2;
		Radius = 200;*/
       
		return 0;
	}

	void GAME::destroy()
	{
		//create()でnewした場合はここでdeleteすること
	}

    void GAME::proc()
    {

        //シーン切り替え
        if (State == TITLE)title();
        else if (State == INIT)init();
        else if (State == PLAY)play();
        else if (State == OVER)over();
    }
    int bonus = 0;
    int Score = 0;
    //ブロックパターンオフセット
    int Offsets[7][3][2] = {
        //■□■■...0
        -1,0,   1,0,  2,0,
        //■
        //■□■....1
        -1,-1, -1,0,  1,0,
        //  　■
        //■□■....2
        -1,0,   1,-1, 1,0,
        //■□
        //　■■....3
        -1,0,   0,1,  1,1,
        //　□■
        //■■  ....4
         1,0,   0,1, -1,1,
         //　■
         //■□■....5
         -1,0,   0,-1, 1,0,
         //□■
         //■■......6
          1,0,   0,1,  1,1,
    };

   // HSBからRGBへの変換関数
   void GAME::hsbToRgb(float h, float s, float v, int& r, int& g, int& b) {
        if (s == 0) {
            r = g = b = static_cast<int>(v * 255);
        }
        else {
            float f = (h - static_cast<int>(h)) * 6.0f;
            float p = v * (1.0f - s);
            float q = v * (1.0f - s * f);
            float t = v * (1.0f - (s * (1.0f - f)));
            switch (static_cast<int>(h)) {
            case 0:
                r = static_cast<int>(v * 255);
                g = static_cast<int>(t * 255);
                b = static_cast<int>(p * 255);
                break;
            case 1:
                r = static_cast<int>(q * 255);
                g = static_cast<int>(v * 255);
                b = static_cast<int>(p * 255);
                break;
            case 2:
                r = static_cast<int>(p * 255);
                g = static_cast<int>(v * 255);
                b = static_cast<int>(t * 255);
                break;
            case 3:
                r = static_cast<int>(p * 255);
                g = static_cast<int>(q * 255);
                b = static_cast<int>(v * 255);
                break;
            case 4:
                r = static_cast<int>(t * 255);
                g = static_cast<int>(p * 255);
                b = static_cast<int>(v * 255);
                break;
            default:
                r = static_cast<int>(v * 255);
                g = static_cast<int>(p * 255);
                b = static_cast<int>(q * 255);
                break;
            }
        }
    }
    void GAME::title()
    {
        //描画--------------------------------------------------
        clear(60, 60, 60);
        //テキスト情報
        fill(0, 255, 0);
        textSize(100);
        text("ボーナステトリス", 600, 450);
        fill(0, 0, 0);
        textSize(40);
        text("クリックでゲームスタート", 750, 500);
        text("Enterでメニューに戻る", 750, 550);
        //シーン切り替え-----------------------------------------
        if (isTrigger(MOUSE_LBUTTON)) {
            //次のシーケンス
            State = INIT;
            return;
        }
        //メニューに戻る-----------------------------------------
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }
		//ここはメインループから呼び出されている!!!!!
        void GAME::init() {
            clear(60, 60, 60);
            fill(0, 0, 0);
            textSize(60);
            text("右へ１マス:D", 750, 500);
            text("左へ１マス:A", 750, 550);
            text("回転:W", 750, 600);
            text("落下:S", 750, 650);
            textSize(40);
            text("ピンクの四角いブロックが出現した後はボーナスタイム！", 750, 700);
            text("そのあとの一列だけ点数が10倍！", 750, 750);
            text("クリックで進む", 750, 900);
            //壁と背景の色番号をStage2次元配列にセット
            for (int y = 0; y < ROWS; y++) {
                Stage[y][0] = Stage[y][COLS - 1] = WALL;
                for (int x = 1; x < COLS - 1; x++) {
                    Stage[y][x] = BACK;
                    if (y == ROWS - 1) {
                        Stage[y][x] = WALL;
                    }
                }
            }
            //ブロック初期値
            X = 5;
            Y = 1;
            R = 0;
            PtnNo = random() % 7;
            setPtnPosition();
            if (isTrigger(MOUSE_LBUTTON)) {
                State = PLAY;
                return;
            }
        }
        void GAME::drawStage() {
            void complete();
            angleMode(DEGREES);
            colorMode(HSV);
            strokeWeight(20);
            rectMode(CENTER);
            for (int y = 0; y < ROWS; y++) {
                for (int x = 0; x < COLS; x++) {
                    int no = Stage[y][x];
                    //int r, g, b;
                    //hsbToRgb(Color[no].hue, Color[no].satu, Color[no].value, r, g, b);
                    stroke(Color[no].hue, Color[no].satu, Color[no].value);
                    //stroke(Color[no]);
                     
                    fill(0,0,100);
                    rect(Size / 2 + Size * x, Size / 2 + Size * y, Size / 2, Size / 2);
                    if (no == 6) {
                        bonus = 1;
                    }
                    if (bonus == 1) {
                        fill(255);
                        textSize(100);
                        text("ボーナスタイム！" ,1000,100);
                    }
                }
            }
            // スコアを表示
            fill(255);
            textSize(40);
            text((let)"Score:" + Score,0,100);
            //text("Score:",0,0);
            //text((let)Score,100,0);
        }
        void GAME::setPtnPosition() {
            //基準ブロック位置
            Px[0] = X;
            Py[0] = Y;
            //回転数
            int r = R % 4;

            for (int i = 0; i < 3; i++) {
                //現在のブロックパターンのオフセット値を取得
                int ofsX = Offsets[PtnNo][i][0];
                int ofsY = Offsets[PtnNo][i][1];
                //回転数に応じて９０度ずつ回転させる
                for (int j = 0; j < r; j++) {
                    int w = ofsX;
                    ofsX = -ofsY;
                    ofsY = w;
                }
                //位置決定
                Px[i + 1] = X + ofsX;
                Py[i + 1] = Y + ofsY;
            }
        }
        void GAME::setPtnNoToStage() {
            setPtnPosition();
            for (int i = 0; i < 4; i++) {
                int x = Px[i];
                int y = Py[i];
                Stage[y][x] = PtnNo;
            }
        }
        void GAME::delPtnNoFromStage() {
            for (int i = 0; i < 4; i++) {
                int x = Px[i];
                int y = Py[i];
                Stage[y][x] = BACK;
            }
        }
        int GAME::collision() {
            setPtnPosition();
            int flag = 0;
            for (int i = 0; i < 4; i++) {
                int x = Px[i];
                int y = Py[i];
                if (Stage[y][x] != BACK) {
                    flag = 1;
                }
            }
            return flag;
        }
        void GAME::complete() {
            for (int y = 1; y < ROWS - 1; y++) {
                int flag = 1;
                for (int x = 1; x < COLS - 1; x++) {
                    if (Stage[y][x] == BACK) {
                        flag = 0;
                    }
                }
                if (flag) {
                    if (bonus == 0) {
                        Score += 1000;
                    }
                    else if (bonus == 1) {
                        Score += 10000;
                        bonus = 0;
                    }
                    //そろったのでスライド
                    for (int upy = y - 1; upy >= 0; upy--) {
                        for (int x = 1; x < COLS - 1; x++) {
                            Stage[upy + 1][x] = Stage[upy][x];
                        }
                    }
                }
            }
        }
        void GAME::play() {
            //現在のパターン番号（色番号）をステージから消す
            delPtnNoFromStage();
            //移動、回転
            int dy = 0, dx = 0, dr = 0;;
            if ((++LoopCnt %= 15) == 0)dy = 1;
            if (isTrigger(KEY_D))dx = 1;
            if (isTrigger(KEY_A))dx = -1;
            if (isTrigger(KEY_W))dr = 1;
            if (isTrigger(KEY_S))FallFlag = 1;
            if (FallFlag)dy = 1;
            Y += dy;
            X += dx;
            R += dr;
            if (collision()) {
                //元の位置、回転に戻す
                Y -= dy;
                X -= dx;
                R -= dr;
                FallFlag = 0;
                if (dy == 1 && dx == 0 && dr == 0) {
                    //積もらせる
                    setPtnNoToStage();
                    //行がそろっていたらスライドさせる
                    complete();
                    //新しいブロック誕生
                    X = 5;
                    Y = 1;
                    R = 0;
                    PtnNo = random() % 7;
                    if (collision()) {
                        State = OVER;
                    }
                }
            }
            //パターン番号（色番号）をステージにセット
            setPtnNoToStage();

            //描画
            clear(0);
            drawStage();
        }

        void GAME::over() {
            clear(255,0,0);
            //ゲームオーバーテキスト           
            fill(0, 0, 255);
            textSize(80);
            text("ＧａｍｅＯｖｅｒ",650,450 );
            text("SPACEキーでタイトルに戻る", 500,550);
            if (isTrigger(KEY_SPACE)) {
                State = TITLE;
            }
        }

        void GAME::gmain() {
            window(Size * COLS*2, Size * ROWS,full);
        }

		/* //描画--------------------------------------------------
		clear(255, 255, 255);

		//テキスト情報
		fill(0);
		textSize(100);
		text("Enterでメニューに戻る", 0, height);
		print(12);
		//メニューに戻る------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}*/
	}



