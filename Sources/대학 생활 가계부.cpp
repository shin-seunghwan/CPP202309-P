#include <iostream>
#include <vector>
#include <string>
using namespace std;

//�� ������ ������ ���� ���� ����
vector<string> types;
vector<double> amounts;
vector<string> descriptions;
vector<string> dates;

void addEntry();
void viewEntry();
void viewMonthTotal();
void editEntry();
void deleteEntry();
void printMonthTable();


// ���� �޴� ��� �� ����� ����
int mainMenu() {
    int choice;
    cout << "1. ���� �߰�\n";
    cout << "2. ���� ��ȸ\n";
    cout << "3. ���� �հ� ��ȸ\n";
    cout << "4. ���� ����\n";
    cout << "5. ���� ����\n";
    cout << "6. ���� ����\n";
    cout << "7. ����\n";
    cout << "����: ";
    cin >> choice;
    return choice;
}

// ���� �Լ� �ݺ���
int main() {
    int choice;
    do {
        choice = mainMenu();
        switch (choice) {
            // �� ��ɿ� ���� �Լ� ȣ��
        case 1:
            addEntry();
            break;
        case 2:
            viewEntry();
            break;
        case 3:
            viewMonthTotal();
            break;
        case 4:
            editEntry();
            break;
        case 5:
            deleteEntry();
            break;
        case 6:
            printMonthTable();
            break;
        case 7:
            cout << "���α׷��� �����մϴ�." << std::endl;
            break;
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << std::endl;
        }
    } while (choice != 7); // 7���� �����ϸ� ���α׷� ����

    return 0;
}

void addEntry() {
    string type;
    double amount;
    string description;
    string date;

    //�Է� ���� �Ϳ� ���� �ش��ϴ� vector�� �߰��Ѵ�.
    //���� ��ȸ, ����, ���� � ������ �� ���ȴ�.
    
    cout << "1. ���� �Ǵ� ����: ";
    cin >> type;
    types.push_back(type);

    cout << "2. �ݾ�: ";
    cin >> amount;
    amounts.push_back(amount);

    // �Է� ���� Ŭ����
    getchar();

    cout << "3. ����: ";
    getline(cin, description);
    descriptions.push_back(description);

    cout << "4. ��¥ (YYYY-MM-DD): ";
    cin >> date;
    dates.push_back(date);

    cout << "������ �߰��Ǿ����ϴ�.\n";
}
