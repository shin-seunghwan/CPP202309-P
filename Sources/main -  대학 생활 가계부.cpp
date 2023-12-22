#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Entry ����ü ����
struct Entry 
{
    string type;
    double amount;
    string description;
    string date;
};

//Entry ����ü�� ����
vector<Entry> entries;

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
    Entry newEntry;

    //�Է� ���� �Ϳ� ���� �ش��ϴ� vector�� �߰��Ѵ�.
    //���� ��ȸ, ����, ���� � ������ �� ���ȴ�.

    cout << "1. ���� �Ǵ� ����: ";
    cin >> newEntry.type;

    cout << "2. �ݾ�: ";
    cin >> newEntry.amount;

    // �Է� ���� Ŭ����
    getchar();

    cout << "3. ����: ";
    getline(cin, newEntry.description);
    

    cout << "4. ��¥ (YYYY-MM-DD): ";
    cin >> newEntry.date;

    //���ο� �׸��� ���Ϳ� �߰�
    entries.push_back(newEntry);

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
    for (const auto& entry : entries) {
        if (entry.date.substr(0, 4) == year && entry.date.substr(5, 2) == month && entry.date.substr(8, 2) == day) {
            cout << entry.date << ": " << entry.type << " " << entry.amount << " " << entry.description << endl;
        }
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
    for (const auto& entry : entries) {
        if (entry.date.substr(0, 4) == year && entry.date.substr(5, 2) == month) {
            if (entry.type == "����") {
                incomeTotal += entry.amount;
            }
            else if (entry.type == "����") {
                expenseTotal += entry.amount;
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
    for (auto& entry : entries) {
        if (entry.date == date) {
            // ��ġ�ϴ� �׸��� ã���� �� ������ �׸� ����
            cout << "������ �׸��� �����ϼ��� (1. ����/���� 2. �ݾ� 3. ����): ";
            int choice;
            cin >> choice;

            // �� �� ���� ���� ����
            cin.ignore();

            // ���õ� �׸� ���� �ش� ������ ����
            switch (choice) {
            case 1:
                cout << "���ο� ����/���� (���� �Ǵ� ����): ";
                getline(cin, entry.type);
                break;
            case 2:
                cout << "���ο� �ݾ�: ";
                cin >> entry.amount;
                cin.ignore();
                break;
            case 3:
                cout << "���ο� ����: ";
                getline(cin, entry.description);
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

void deleteEntry() {
    string date;
    // ����ڿ��� ������ ������ ��¥�� �Է¹���
    cout << "������ ������ ��¥�� �Է��ϼ��� (YYYY-MM-DD): ";
    cin >> date;

    // dates ���͸� ��ȸ�ϸ� ����ڰ� �Է��� ��¥�� ��ġ�ϴ� �׸� ã��
    for (size_t i = 0; i < entries.size(); ++i) {
        if (entries[i].date == date) {
            entries.erase(entries.begin() + i);
            cout << "������ �����Ǿ����ϴ�." << endl;
            return;
        }
    }

    // ��ġ�ϴ� ��¥�� �׸��� ã�� ���� ���
    cout << "�ش� ��¥�� ������ �����ϴ�." << endl;
}


void printMonthTable() {
    string year, month;
    // ����ڿ��� ����� �� ���̺��� �⵵�� ���� �Է¹���
    cout << "�⵵�� �Է��ϼ��� (YYYY): ";
    cin >> year;
    cout << "���� �Է��ϼ��� (MM): ";
    cin >> month;

    cout << "��¥\t\tŸ��\t�ݾ�\t����\n";
    cout << "--------------------------------------------\n";

    // dates ���͸� ��ȸ�ϸ� �ش� �⵵�� ���� �´� �׸��� ã�� ���
    for (const auto& entry : entries) {
        if (entry.date.substr(0, 4) == year && entry.date.substr(5, 2) == month) {
            cout << entry.date << "\t" << entry.type << "\t" << entry.amount << "\t" << entry.description << endl;
        }
    }
}