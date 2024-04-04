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
    string menu[5] = { "�Ϲ� ���", "��ġ ���", "ġ�� ���", "�� ���", "�� ���� ���" }; // ��� ����
    int price[5] = { 3500, 4000, 4200, 4300, 4500 }; // ��� ����
    int choice = 0; // ������ ��� ��ȣ
    char decision; // ���� ����
    int quantity[5] = { 0 }; // ��� ����
    int total_price = 0; // ������ ��� ����

    while (true) {
        cout << endl << endl;
        cout << "***** ������ ��鰡�Կ� ���� ���� ȯ���մϴ� *****";
        cout << endl << endl;
        cout << "1. �Ϲ� ��� (3500��)" << endl;
        cout << "2. ��ġ ��� (4000��)" << endl;
        cout << "3. ġ�� ��� (4200��)" << endl;
        cout << "4. �� ��� (4300��)" << endl;
        cout << "5. �� ���� ��� (4500��)" << endl;
        cout << endl << endl;
        cout << "�����Ͻ� ��� ��ȣ�� �Է��� �ּ���(����� 0) : ";
        cin >> choice;

        if (choice == 0) {
            break; // ����
        }
        else if (choice < 1 || choice > 5) {
            cout << "����� �� ���ڸ� �Է����ּ���." << endl;
            continue;
        }

        cout << endl << endl;
        cout << menu[choice - 1] << "��(��) �����Ͻðڽ��ϱ�? (Y/N) ";
        cin >> decision;

        if (decision == 'Y' || decision == 'y') {
            cout << endl << "�����Ͻ� ��� ������ �Է����ּ���: ";
            cin >> quantity[choice - 1];
            cout << endl << endl;
            cout << menu[choice - 1] << " " << quantity[choice - 1] << "���� �����ϼ̽��ϴ�." << endl;

            cout << "������ " << price[choice - 1] * quantity[choice - 1] << "�� �Դϴ�." << endl << endl;
        }
        else if (decision == 'N' || decision == 'n') {
            continue;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
            continue;
        }
    }

    total_price = total(price, quantity);
    cout << "�� ������ ��� ������ " << total_price << "�� �Դϴ�." << endl;

    return 0;
}
