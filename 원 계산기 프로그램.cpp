#include <iostream>
using namespace std;

// �� Ŭ����
class Circle {
private:
    double radius; // ������

public:
    Circle(double r) : radius(r) {
        cout << endl << endl << "***�� ���� ����***" << endl << endl;
    }

    ~Circle() {
        cout << endl << endl << "�� ���� ����...." << endl << endl;
    }

    // ���� ����
    double calculate����() {
        return 3.14 * radius * radius;
    }

    // ���� �ѷ�
    double calculate�ѷ�() {
        return 2 * 3.14 * radius;
    }
};

// ����� Ŭ����
class Cylinder {
private:
    double radius; // ������
    double height; // ����

public:
    Cylinder(double r, double h) : radius(r), height(h) {
        cout << endl << endl << "***����� ���� ����***" << endl << endl;
    }

    ~Cylinder() {
        cout << endl << endl << "����� ���� ����...." << endl << endl;
    }

    // ������� ����
    double calculate����() {
        return 3.14 * radius * radius * height;
    }

    // ������� �ѳ���
    double calculate�ѳ���() {
        return 2 * 3.14 * radius * (radius + height);
    }
};

// �� Ŭ����
class Sphere {
private:
    double radius; // ������

public:
    Sphere(double r) : radius(r) {
        cout << endl << endl << "***�� ���� ����***" << endl << endl;
    }

    ~Sphere() {
        cout << endl << endl << "�� ���� ����...." << endl << endl;
    }

    // ���� ����
    double calculate����() {
        return (4.0 / 3) * 3.14 * radius * radius * radius;
    }

    // ���� �ѳ���
    double calculate�ѳ���() {
        return 4 * 3.14 * radius * radius;
    }
};

// ���� Ŭ����
class Cone {
private:
    double radius; // ������
    double height; // ����

public:
    Cone(double r, double h) : radius(r), height(h) {
        cout << endl << endl << "***���� ���� ����***" << endl << endl;
    }

    ~Cone() {
        cout << endl << endl << "���� ���� ����...." << endl << endl;
    }

    // ������ ����
    double calculate����() {
        return (1.0 / 3) * 3.14 * radius * radius * height;
    }
};

int main() {
    int choice;
    double radius, height;

    while (true) {
        cout << endl << endl;
        cout << "���ϴ� ����� �����ϼ���" << endl;
        cout << "1. ���� ���� ���" << endl;
        cout << "2. ���� �ѷ� ���" << endl;
        cout << "3. ������� ���� ���" << endl;
        cout << "4. ������� �ѳ��� ���" << endl;
        cout << "5. ������ ���� ���" << endl;
        cout << "6. ���� ���� ���" << endl;
        cout << "7. ���� �ѳ��� ���" << endl;
        cout << "8. ����" << endl;
        cout << "����: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            cout << "������ �Է�: ";
            cin >> radius;
            Circle circle(radius);
            cout << endl << endl << "���� ����: " << circle.calculate����() << endl << endl;
            break;
        }
        case 2: {
            cout << "������ �Է�: ";
            cin >> radius;
            Circle circle(radius);
            cout << endl << endl << "���� �ѷ�: " << circle.calculate�ѷ�() << endl << endl;
            break;
        }
        case 3: {
            cout << "������ �Է�: ";
            cin >> radius;
            cout << "���� �Է�: ";
            cin >> height;
            Cylinder cylinder(radius, height);
            cout << endl << endl << "������� ����: " << cylinder.calculate����() << endl << endl;
            break;
        }
        case 4: {
            cout << "������ �Է�: ";
            cin >> radius;
            cout << "���� �Է�: ";
            cin >> height;
            Cylinder cylinder(radius, height);
            cout << endl << endl << "������� �ѳ���: " << cylinder.calculate�ѳ���() << endl << endl;
            break;
        }
        case 5: {
            cout << "������ �Է�: ";
            cin >> radius;
            cout << "���� �Է�: ";
            cin >> height;
            Cone cone(radius, height);
            cout << endl << endl << "������ ����: " << cone.calculate����() << endl << endl;
            break;
        }
        case 6: {
            cout << "������ �Է�: ";
            cin >> radius;
            Sphere sphere(radius);
            cout << endl << endl << "���� ����: " << sphere.calculate����() << endl << endl;
            break;
        }
        case 7: {
            cout << "������ �Է�: ";
            cin >> radius;
            Sphere sphere(radius);
            cout << endl << endl << "���� �ѳ���: " << sphere.calculate�ѳ���() << endl << endl;
            break;
        }
        case 8:
            return 0;
        default:
            cout << "�ٽ� �����ϼ���." << endl << endl;
        }
    }

    return 0;
}