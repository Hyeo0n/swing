#include <iostream>
using namespace std;

int total(int* price, int* quantity) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += price[i] * quantity[i];
    }
    return sum;
}

int main(void)
{
    string menu[5] = { "일반 라면", "김치 라면", "치즈 라면", "떡 라면", "떡 만두 라면" }; // 라면 종류
    int price[5] = { 3500, 4000, 4200, 4300, 4500 }; // 라면 가격
    int choice = 0; // 선택한 라면 번호
    char decision; // 구매 여부
    int quantity[5] = { 0 }; // 라면 개수
    int total_price = 0; // 누적된 라면 가격

    while (true) {
        cout << endl << endl;
        cout << "***** 슈니의 라면가게에 오신 것을 환영합니다 *****";
        cout << endl << endl;
        cout << "1. 일반 라면 (3500원)" << endl;
        cout << "2. 김치 라면 (4000원)" << endl;
        cout << "3. 치즈 라면 (4200원)" << endl;
        cout << "4. 떡 라면 (4300원)" << endl;
        cout << "5. 떡 만두 라면 (4500원)" << endl;
        cout << endl << endl;
        cout << "구매하실 라면 번호를 입력해 주세요(종료는 0) : ";
        cin >> choice;

        if (choice == 0) {
            break; // 종료
        }
        else if (choice < 1 || choice > 5) {
            cout << "제대로 된 숫자를 입력해주세요." << endl;
            continue;
        }

        cout << endl << endl;
        cout << menu[choice - 1] << "을(를) 구매하시겠습니까? (Y/N) ";
        cin >> decision;

        if (decision == 'Y' || decision == 'y') {
            cout << endl << "구매하실 라면 개수를 입력해주세요: ";
            cin >> quantity[choice - 1];
            cout << endl << endl;
            cout << menu[choice - 1] << " " << quantity[choice - 1] << "개를 구매하셨습니다." << endl;

            cout << "가격은 " << price[choice - 1] * quantity[choice - 1] << "원 입니다." << endl << endl;
        }
        else if (decision == 'N' || decision == 'n') {
            continue;
        }
        else {
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
            continue;
        }
    }

    total_price = total(price, quantity);
    cout << "총 누적된 라면 가격은 " << total_price << "원 입니다." << endl;

    return 0;
}
