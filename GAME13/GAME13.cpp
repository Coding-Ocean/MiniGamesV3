#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME13.h"

namespace GAME13
{
    

    int GAME::create()
    {
        // 画像や音声データの読み込みなどを行う

        // 初期化は Init() 関数などで行うのが良いが、シンプルなゲームならここで行ってもよい
        State = TITLE;

        return 0;
    }

    void GAME::destroy()
    {
        // create() で new した場合はここで delete する
    }

    void GAME::proc()
    {
        if (State == TITLE)Title();
        else if (State == PLAY)Play();
        else if (State == CLEAR)Clear();
        // ここはメインループから呼び出されている
    }

    void GAME::Title()
    {
        // 画面描画
        clear(255, 255, 255);

        // テキスト情報
        fill(0);
        textSize(100);
        print("じゃんけん");
        print("クリックでゲームスタート");
       

        // シーン切り替え
        if (isTrigger(MOUSE_LBUTTON)) {
            Init();
            State = PLAY;
            return;
        }

        // メニューに戻る
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::Init()
    {
        // 初期化処理（今回は特に何もしない）
    }

    void GAME::Play()
    {
        // 画面描画
        clear(255, 255, 255);

        // テキスト情報
        fill(0);
        print("Aでグー");
        print("Sでチョキ");
        print("Dでパー");
        print("タイトルに戻る");

        // プレイヤーの入力を受け取る
        if (isTrigger(KEY_A)) {
            playerHand = ROCK;
            determineWinner();
        }
        else if (isTrigger(KEY_S)) {
            playerHand = SCISSORS;
            determineWinner();
        }
        else if (isTrigger(KEY_D)) {
            playerHand = PAPER;
            determineWinner();
        }

        // シーン切り替え（例：クリアフラグが立った場合）
        if (ClearFlag) {
            State = CLEAR;
        }
    }

        


    void GAME::determineWinner()
    {
        // コンピュータの手をランダムに選択
        computerHand = static_cast<Hand>(rand() % 3);

        // プレイヤーの手とコンピュータの手を表示
        print("あなたの手: ");
        if (playerHand == ROCK)
            print("グー");
        else if (playerHand == PAPER)
            print("パー");
        else
            print("チョキ");

        print("コンピュータの手: ");
        if (computerHand == ROCK)
            print("グー");
        else if (computerHand == PAPER)
            print("パー");
        else
            print("チョキ");

        // 勝敗判定と結果表示
        if (playerHand == computerHand) {
            // 引き分け
            print("引き分け！");
        }
        else if ((playerHand == ROCK && computerHand == SCISSORS) ||
            (playerHand == SCISSORS && computerHand == PAPER) ||
            (playerHand == PAPER && computerHand == ROCK)) {
            // プレイヤーの勝利
            print("あなたの勝ち！");
        }
        else {
            // プレイヤーの負け
            print("あなたの負け！");
            State = CLEAR; // 負けた場合、Clear() 関数に遷移する
        }
    }

    void GAME::Clear()
    {
        // 画面描画
        clear(0, 0, 255);

        // テキスト情報
        fill(255, 255, 255);
        print("クリックでタイトルに戻る");

        // シーン切り替え（マウスクリックがあった場合）
        if (isTrigger(MOUSE_LBUTTON)) {
            State = TITLE;
        }
    }

}; // namespace GAME13