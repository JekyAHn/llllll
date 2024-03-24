#include <iostream>
using namespace std;

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

void drawBlock(int colorCode) {
    switch (colorCode) {
    case 1:
        cout << "\x1b[48;5;" << 15 << "m  \x1b[0m"; // 흰색 블록 출력
        break;
    case 2:
        cout << "\x1b[48;5;" << 1 << "m  \x1b[0m"; // 빨간색 블록 출력
        break;
    case 4:
        cout << "\x1b[48;5;" << 10 << "m  \x1b[0m"; // 녹색 블록 출력
        break;
    case 8:
        cout << "\x1b[48;5;" << 11 << "m  \x1b[0m"; // 노란색 블록 출력
        break;
    case 16:
        cout << "\x1b[48;5;" << 14 << "m  \x1b[0m"; // 청록색 블록 출력
        break;
    case 32:
        cout << "\x1b[48;5;" << 13 << "m  \x1b[0m"; // 마젠타색 블록 출력
        break;
    default:
        cout << "\x1b[48;5;" << colorCode << "m  \x1b[0m"; // ANSI 이스케이프 코드를 사용하여 색상 블록 출력
        break;
    }
}

int main() {
    cout << "화면에 그림을 그리는 프로그램입니다." << endl;
    cout << "학번: 202327057" << endl; // 여기에 본인의 학번을 적으세요.
    cout << "이름: 안제철" << endl; // 여기에 본인의 이름을 적으세요.

    int input;
    do {
        cout << "화면에 그릴 물체코드를 입력하세요 (프로그램 종료: 64): ";
        cin >> input;

        // 입력된 키코드가 주어진 키코드와 완전히 일치하지 않는 경우
        if (input & (input - 1)) {
            int san = input;
            bool isFirst = true;
            // 입력된 키코드를 2진수로 변환하여 가장 가까운 작은 두 개의 키코드에 해당하는 블록 출력
            while (san > 0) {
                int bit = san & -san; // 가장 오른쪽에 있는 비트만 남기고 나머지는 0으로 만듭니다.
                drawBlock(bit);
                san -= bit;
                if (isFirst) {
                    isFirst = false;
                }
            }
            cout << endl;
        }
        else {
            // 주어진 키코드에 맞게 블록 출력
            drawBlock(input);
            cout << endl;
        }
    } while (input != 64); // 사용자가 프로그램 종료를 선택할 때까지 반복

    return 0;
}
