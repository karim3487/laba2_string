#include <iostream>
#include "String.h"
#include "IdString.h"
#include "DecString.h"


using namespace std;

int String::countCopyConstructor = 0;//����������� ������������ ��������
int main() {
    setlocale(LC_ALL, "Russian");
    char menuSelector, classObjectSelector, inputStringToClass[255], classMethodSelector;
    int countOfArrayPointers = 0, countOfObject = 0, currentObjectNumber = 0;
    String **charStringPtrArray = nullptr;
    String tempCharStr;

    while (countOfArrayPointers <= 0) {
        cout << "������� ����� ���������� �� ����� <<������>>" << endl;
        cin >> countOfArrayPointers;

    }
    charStringPtrArray = new String *[countOfArrayPointers];//������������ �������� ������� ����������

    while (countOfObject < countOfArrayPointers)//������ ��� �������� � ������
    {
        cout << "�������� ����������� ������� ������ �� ������: " << endl;
        cout << "1. <<������>>" << endl;
        cout << "2. <<������-�������������>>" << endl;
        cout << "3. <<���������� ������>>" << endl;
        cin >> classObjectSelector;
        cout << "������� �������� ������:" << endl;
        cin >> inputStringToClass;
        switch (classObjectSelector)//� ����������� �� ������ ����  ������ ����� ������ ������
        {
            case '1': {
                charStringPtrArray[countOfObject] = new String(
                        inputStringToClass);//������������ �������� �������� ������
                break;
            }
            case '2': {
                charStringPtrArray[countOfObject] = new IdString(inputStringToClass);
                break;
            }
            case '3': {
                charStringPtrArray[countOfObject] = new DecString(inputStringToClass);
                break;
            }
            default:
                cout << "��������� ������ ������ ����������� � ������. ��������� �������" << endl;
                break;
        }
        countOfObject++;
    }
    do {
        system("cls");
        cout << "����� ��������� � ������� ���������� �� ������� �����:" << countOfArrayPointers << endl;
        cout << "������� ��������� �� ������ ������: " << currentObjectNumber << endl;
        cout << "�������� ����� ���� �� �������������:" << endl;
        cout << "1. ������� � ����������� ��������� <-" << endl;
        cout << "2. ������� � ���������� ��������� ->" << endl;
        cout << "3. ������������ �������� ������� ������" << endl;
        cout << "q. �����" << endl;
        cin >> menuSelector;
        switch (menuSelector) {
            case '1': {
                currentObjectNumber--;
                if (currentObjectNumber < 0) {
                    currentObjectNumber = countOfArrayPointers -
                                          1;//���� �� ������� �� ����� �������, ����������� ��������� ��������, ���� �� ����� �� ����� �������
                }

                break;
            }
            case '2': // ���� �� ������� �� ����� �������, ����������� 0, ���� �� ����� �� ����� �������.
            {
                currentObjectNumber++;
                if (currentObjectNumber >= countOfArrayPointers) {
                    currentObjectNumber = 0;
                }
                break;
            }
            case '3':
                system("cls");
                switch (charStringPtrArray[currentObjectNumber]->getType())//���������� ��� ������� � ������������� ������ ������
                {
                    case '1': {
                        cout << "������������ ������� ������ <<������>>:" << endl;
                        String *charStr = charStringPtrArray[currentObjectNumber];
                        cout << *charStr << endl;
                        do {
                            cout << "1. ������ ����� �������� ��� <<������>> " << endl;
                            cout << "q. �����" << endl;
                            cin >> classMethodSelector;
                            switch (classMethodSelector) {
                                case '1':
                                    cout << "������� ����� �������� ������:" << endl;
                                    cin >> inputStringToClass;
                                    *charStr = inputStringToClass;
                                    break;
                                case 'q':
                                    break;
                                default:
                                    cout << "������ ����� ���� ����������� � ������, ��������� �������" << endl;
                                    break;
                            }
                        } while (classMethodSelector != 'q');
                        break;
                    }
                    case '2': {
                        do {
                            system("cls");
                            cout << "������������ ������� ������ <<������-�������������>>" << endl;
                            IdString *idString = static_cast<IdString *>(charStringPtrArray[currentObjectNumber]);//�������� ��������� �� ������� ����� � ������ IdString
                            cout << *idString << endl;
                            cout << "1. ������ ����� �������� ��� <<������-�������������> " << endl;
                            cout << "2. ����� ���������� ��������� ������� � ������" << endl;
                            cout << "3. ��������� ����� �������� '>'" << endl;
                            cout << "4. ��������� ����� �������� '<'" << endl;
                            cout << "q. �����" << endl;
                            cin >> classMethodSelector;
                            switch (classMethodSelector) {
                                case '1': {
                                    cout << "������� ����� �������� ������:" << endl;
                                    cin >> inputStringToClass;
                                    *idString = inputStringToClass;
                                    break;
                                }
                                case '2': {
                                    char find;
                                    cout << "������� ������ ��� ������ ���������� ���������: " << endl;
                                    cin >> find;
                                    idString->lastOccurrence(find);
                                    getchar();
                                    getchar();
                                    break;
                                }
                                case '3': {
                                    cout << "������� ������ ��� ���������" << endl;
                                    cin >> inputStringToClass;
                                    IdString idTempString(inputStringToClass);
                                    IdString idStringCopy(*idString);
                                    *idString = idTempString > idStringCopy;
                                }
                                case '4': {
                                    cout << "������� ������ ��� ���������" << endl;
                                    cin >> inputStringToClass;
                                    IdString idTempString(inputStringToClass);
                                    IdString idStringCopy(*idString);
                                    //*idString = idTempString < idStringCopy;
                                }
                                case 'q':
                                    break;
                                default:
                                    cout << "������ ����� ���� ����������� � ������, ��������� �������" << endl;
                                    break;
                            }
                        } while (classMethodSelector != 'q');
                        break;
                    }
                    case '3': {
                        do {
                            system("cls");
                            cout << "������������ ������� ������ <<���������� ������>>" << endl;
                            DecString *dec_str = static_cast<DecString *>(charStringPtrArray[currentObjectNumber]);//�������� ��������� �� ������� ����� � ������ Dec_string
                            cout << *dec_str << endl;
                            cout << "1. ������ ����� �������� ��� <<���������� ������>> " << endl;
                            cout << "2. ��������� ������ <<����������� �����>> �� �������" << endl;
                            cout << "3. ��������� ������ <<����������� �����>> � ������" << endl;
                            cout << "q. �����" << endl;
                            cin >> classMethodSelector;
                            switch (classMethodSelector) {
                                case '1': {
                                    cout << "������� ����� �������� ������:" << endl;
                                    cin >> inputStringToClass;
                                    *dec_str = inputStringToClass;
                                    break;
                                }
                                case '2': {
                                    cout << "������� ������ � ���������� ������� ��� ��������� �� ��������:" << endl;
                                    cin >> inputStringToClass;
                                    DecString decTempString(inputStringToClass);
                                    DecString decString(*dec_str);
                                    *dec_str = decString - decTempString;
                                    break;
                                }
                                case '3': {
                                    cout << "������� ������ � ���������� ������� ��� ��������� � ��������:" << endl;
                                    cin >> inputStringToClass;
                                    DecString decTempString(inputStringToClass);
                                    DecString decString(*dec_str);
                                    (decString > decTempString) ? (*dec_str = decString) : (*dec_str = decTempString);
                                    break;
                                }
                                case 'q':
                                    break;
                                default: {
                                    cout << "������ ����� ���� ����������� � ������, ��������� �������" << endl;
                                    break;
                                }
                            }
                        } while (classMethodSelector != 'q');
                        break;
                    }
                    default: {
                        break;
                    }
                }
            case 'q':
                break;
            default:
                cout << "������ ����� ���� ����������� � ������, ��������� �������" << endl;
                break;
        }
        system("pause");
    } while (menuSelector != 'q');
    //������������� ����������, ��� ����� ���� �� ������ ������
    return 0;
}