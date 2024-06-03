#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        double num1 = 0.0, num2 = 0.0, result = 0.0;
        int choice = 0;

        // �޴� ���
        cout << "=============================\n";
        cout << "  ���п� ���� ���α׷�\n";
        cout << "=============================\n";
        cout << "����� ����� �����ϼ���:\n";
        cout << "1. ���ϱ�\n";
        cout << "2. ����\n";
        cout << "3. ���ϱ�\n";
        cout << "4. ������\n";
        cout << "5. �ŵ�����\n";
        cout << "6. ������\n";
        cout << "7. ����\n";
        cout << "8. �ڻ���\n";
        cout << "9. ź��Ʈ\n";
        cout << "����: ";
        cin >> choice;

        // �߸��� ���� �Է� ó��
        if (choice < 1 || choice > 9) {
            cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �õ����ּ���.\n";
            continue;
        }

        // �Է°� �ޱ�
        if (choice >= 1 && choice <= 5) {
            cout << "ù ��° ���� �Է�: ";
            cin >> num1;
            cout << "�� ��° ���� �Է�: ";
            cin >> num2;
        }
        else {
            cout << "���� �Է�: ";
            cin >> num1;
        }

        // ������ ���� ����
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
                cout << "0���� ���� �� �����ϴ�.\n";
                continue;
            }
            result = num1 / num2;
            break;
        case 5:
            result = pow(num1, num2);
            break;
        case 6:
            if (num1 < 0) {
                cout << "������ �������� ����� �� �����ϴ�.\n";
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
            cout << "��ȿ���� ���� �����Դϴ�.\n";
            continue;
        }

        // ��� ���
        cout << "-----------------------------\n";
        cout << "���: " << result << endl;
        cout << "-----------------------------\n";

        // ������� ����
        char cont;
        cout << "��� �Ͻðڽ��ϱ�? (y/n): ";
        cin >> cont;
        if (cont == 'n' || cont == 'N') break;

        cout << "=============================\n\n";
    }
    return 0;
}
