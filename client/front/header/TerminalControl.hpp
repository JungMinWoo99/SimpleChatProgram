#ifndef TERMINALCONTROL_HPP
#define TERMINALCONTROL_HPP

#include <string>
#include <vector>

#include "BearLibTerminal.h"

typedef std::pair<int, int> Point;

namespace TerminalControl
{
    // 입력 박스

    class InputTextBox
    {
    private:
        int max_len;
        Point location;
        std::string buf;

    public:
        InputTextBox(Point coordinate, int max_len);

        Point GetBoxCoordinate();

        std::string GetStr();

        void DrawInputBox();

        void ReadStr();
        
        void ClearStr();
    };

    // 커서

    class Cursor
    {
    private:
        int current_idx = 0;
        int location_num;
        std::vector<Point> location_arr;

    public:
        Cursor(std::vector<Point> &coordinate_arr);

        Point GetCoordinateFromIndex(int idx);

        Point MoveUp();

        Point MoveDown();

        Point CurrentCoordinate();

        int CurrentIndex();

        void SetBegin();
    };

    // 키 확인

    class KeyChecker
    {
        public:
        static bool isArrow(int input);

        static bool isUp(int input);

        static bool isDown(int input);

        static bool isRight(int input);

        static bool isLeft(int input);

        static bool isEnter(int input);

        static bool isESC(int input);

        static bool isF5(int input);

        static bool isPageUp(int input);

        static bool isPageDown(int input);

        static bool isAlphanumeric(int input);

        static bool isBackspace(int input);
    };

    // 터미널 입출력 관련

    class TerminalIO
    {
        public:
        // 화면 새로 고침

        static void RefreshTerminal();

        // 문자열 출력

        static void PrintStr(Point coordinate, const std::string &str);

        // 출력 색상 변경

        static void ChangeStrColor(const std::string &color);

        // 화면 지우기

        static void ClearWholeArea();

        static void ClearArea(Point coordinate, int w, int h);

        // 터미널에 사각형 출력

        static void DrawFrame(Point coordinate, int w, int h);

    };

    // 키보드 입력 하나 확인

    int ReadKey();

    int PeekKey();

    // 아스크 코드로 변환

    char TransformReadToANSI();

    // 화면 출력을 위한 기본적인 설정 세팅

    void StartTerminal(int w=80, int h=24);

    // 프로그램 종료

    void EndTerminal();
};
#endif /* TERMINALCONTROL_HPP */