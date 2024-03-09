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
        // ここはメインループから呼び出されている
        if (State == TITLE)Title();
        else if (State == OPERATION)Operation();
        else if (State == PLAY)Play();
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
        print("Enterでメニューに戻る");

        // シーン切り替え
        if (isTrigger(MOUSE_LBUTTON)) {
            State = OPERATION;
            return;
        }

        // メニューに戻る
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::Operation()
    {
        // 画面描画
        clear(255, 255, 255);

        // テキスト情報
        fill(0);
        print("Aでグー");
        print("Sでチョキ");
        print("Dでパー");
        print("");

        State = PLAY;
    }

    void GAME::Play()
    {
        // プレイヤーの入力を受け取る
        playerHand = NONE;
        if (isTrigger(KEY_A)) {
            playerHand = ROCK;
        }
        else if (isTrigger(KEY_S)) {
            playerHand = SCISSORS;
        }
        else if (isTrigger(KEY_D)) {
            playerHand = PAPER;
        }

        //プレイヤーの入力があったら以下の処理へ
        if (playerHand != NONE) {
            Operation();
            determineWinner();
        }

        // メニューに戻る
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::determineWinner()
    {
        // コンピュータの手をランダムに選択
        computerHand = static_cast<Hand>(rand() % 3);

        // プレイヤーの手とコンピュータの手を表示
        print("あなたの手");
        if (playerHand == ROCK)
            print("　グー");
        else if (playerHand == PAPER)
            print("　パー");
        else
            print("　チョキ");

        print("コンピュータの手");
        if (computerHand == ROCK)
            print("　グー");
        else if (computerHand == PAPER)
            print("　パー");
        else
            print("　チョキ");

        // 勝敗判定と結果表示
        print("");
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
        }

        print("");
        print("Enterでメニューに戻る");
    }

}; // namespace GAME13