#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        double num1 = 0.0, num2 = 0.0, result = 0.0;
        int choice = 0;

        // 메뉴 출력
        cout << "=============================\n";
        cout << "  공학용 계산기 프로그램\n";
        cout << "=============================\n";
        cout << "사용할 기능을 선택하세요:\n";
        cout << "1. 더하기\n";
        cout << "2. 빼기\n";
        cout << "3. 곱하기\n";
        cout << "4. 나누기\n";
        cout << "5. 거듭제곱\n";
        cout << "6. 제곱근\n";
        cout << "7. 사인\n";
        cout << "8. 코사인\n";
        cout << "9. 탄젠트\n";
        cout << "선택: ";
        cin >> choice;

        // 잘못된 선택 입력 처리
        if (choice < 1 || choice > 9) {
            cout << "유효하지 않은 선택입니다. 다시 시도해주세요.\n";
            continue;
        }

        // 입력값 받기
        if (choice >= 1 && choice <= 5) {
            cout << "첫 번째 숫자 입력: ";
            cin >> num1;
            cout << "두 번째 숫자 입력: ";
            cin >> num2;
        }
        else {
            cout << "숫자 입력: ";
            cin >> num1;
        }

        // 선택한 연산 수행
        switch (choice) {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 == 0) {
                cout << "0으로 나눌 수 없습니다.\n";
                continue;
            }
            result = num1 / num2;
            break;
        case 5:
            result = pow(num1, num2);
            break;
        case 6:
            if (num1 < 0) {
                cout << "음수의 제곱근은 계산할 수 없습니다.\n";
                continue;
            }
            result = sqrt(num1);
            break;
        case 7:
            result = sin(num1);
            break;
        case 8:
            result = cos(num1);
            break;
        case 9:
            result = tan(num1);
            break;
        default:
            cout << "유효하지 않은 선택입니다.\n";
            continue;
        }

        // 결과 출력
        cout << "-----------------------------\n";
        cout << "결과: " << result << endl;
        cout << "-----------------------------\n";

        // 계속할지 묻기
        char cont;
        cout << "계속 하시겠습니까? (y/n): ";
        cin >> cont;
        if (cont == 'n' || cont == 'N') break;

        cout << "=============================\n\n";
    }
    return 0;
}
