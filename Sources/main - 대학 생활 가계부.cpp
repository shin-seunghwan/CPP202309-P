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

void viewEntry() {
    string year;
    string month;
    string day;

    cout << "�⵵ �Է�: ";
    cin >> year;
    cout << "�� �Է�: ";
    cin >> month;
    cout << "�� �Է�: ";
    cin >> day;

    //���Ϳ� ���� �ݺ����� �ϱ⿡ size_t, dates.size()�� ��� ���
    //��¥ ���ڿ����� substr�� �̿��ؼ� �ش��ϴ� �ڸ����� �����Ͽ� ��,��,���� �˾Ƴ���.
    for (size_t i = 0; i < dates.size(); ++i) {
        if (dates[i].substr(0, 4) == year && dates[i].substr(5, 2) == month && dates[i].substr(8, 2) == day);
        cout << dates[i] << ": " << types[i] << " " << amounts[i] << " " << descriptions[i] << endl;
    }
}

void viewMonthTotal() {
    string year, month;
    double incomeTotal = 0, expenseTotal = 0;

    cout << "�⵵ �Է�: ";
    cin >> year;
    cout << "�� �Է�: ";
    cin >> month;

    //�ݺ����� �̿��ؼ� �� �׸��� ��¥�� ����ڰ� �Է��� �⵵�� ���� �ش��ϴ� �� Ȯ���Ѵ�.
    //���ǹ��� �̿��ؼ� �׸��� ��¥�� ����ڰ� �Է��� �⵵�� ���� �ش��ϸ�, �ش� �׸��� type�� Ȯ���Ͽ� �߰�
    for (size_t i = 0; i < dates.size(); ++i) {
        if (dates[i].substr(0, 4) == year && dates[i].substr(5, 2) == month) {
            if (types[i] == "����") {
                incomeTotal += amounts[i];
            }
            else if (types[i] == "����") {
                expenseTotal += amounts[i];
            }
        }
    }
    cout << month << "�� ���� �հ�: " << incomeTotal << endl;
    cout << month << "�� ���� �հ�: " << expenseTotal << endl;
}

void editEntry() {
    string date;
    // ����ڿ��� ������ ������ ��¥�� �Է¹���
    cout << "������ ������ ��¥�� �Է��ϼ��� (YYYY-MM-DD): ";
    cin >> date;

    // �ݺ����� �̿��ؼ� dates ���͸� ����ڰ� �Է��� ��¥�� ��ġ�ϴ� �׸� ã��
    for (size_t i = 0; i < dates.size(); ++i) {
        if (dates[i] == date) {
            // ��ġ�ϴ� �׸��� ã���� �� ������ �׸� ����
            cout << "������ �׸��� �����ϼ��� (1. ����/���� 2. �ݾ� 3. ����): ";
            int choice;
            cin >> choice;

            // �� �� ���� ���� ����
            cin.ignore(); 

            // ���õ� �׸� ���� �ش� ������ ����
            switch (choice) {
            case 1: // ����/���� Ÿ�� ����
                cout << "���ο� ����/���� (���� �Ǵ� ����): ";
                getline(cin, types[i]);
                break;
            case 2: // �ݾ� ����
                cout << "���ο� �ݾ�: ";
                cin >> amounts[i];
                cin.ignore(); 
                break;
            case 3: // ���� ����
                cout << "���ο� ����: ";
                getline(cin, descriptions[i]);
                break;
            default:
                cout << "�߸��� �����Դϴ�." << endl;
                break;
            }
            // ������ �Ϸ�Ǿ����� �˸�
            cout << "������ �����Ǿ����ϴ�." << endl;
            return;
        }
    }

    // ��ġ�ϴ� ��¥�� �׸��� ã�� ���� ���
    cout << "�ش� ��¥�� ������ �����ϴ�." << endl;
}