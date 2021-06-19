#include <iostream>
#include "String.h"
#include "IdString.h"
#include "DecString.h"


using namespace std;

int String::countCopyConstructor = 0;//определение статического счётчика
int main() {
    char menuSelector, classObjectSelector, inputStringToClass[255], classMethodSelector;
    int countOfArrayPointers = 0, countOfObject = 0, currentObjectNumber = 0;
    String **charStringPtrArray = nullptr;
    String tempCharStr;

    while (countOfArrayPointers <= 0) {
        cout << "Введите число указателей на класс <<Строка>>" << endl;
        cin >> countOfArrayPointers;

    }
    charStringPtrArray = new String *[countOfArrayPointers];//динамическое создание массива указателей

    while (countOfObject < countOfArrayPointers)//вводим все значения в массив
    {
        cout << "Выберите создаваемый объекта класса из списка: " << endl;
        cout << "1. <<Строка>>" << endl;
        cout << "2. <<Строка-Идентефикатор>>" << endl;
        cout << "3. <<Десятичная Строка>>" << endl;
        cin >> classObjectSelector;
        cout << "Введите значение строки:" << endl;
        cin >> inputStringToClass;
        switch (classObjectSelector)//в зависимости от пункта меню  создаём новый объект класса
        {
            case '1': {
                charStringPtrArray[countOfObject] = new String(
                        inputStringToClass);//динамическое создание объектов класса
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
                cout << "Введенный объект класса отсутствует в списке. Повторите попытку" << endl;
                break;
        }
        countOfObject++;
    }
    do {
        system("cls");
        cout << "Число элементов в массиве указателей на базовый класс:" << countOfArrayPointers << endl;
        cout << "Текущий указатель на объект класса: " << currentObjectNumber << endl;
        cout << "Выберите пункт меню из перечисленных:" << endl;
        cout << "1. Перейти к предыдущему указателю <-" << endl;
        cout << "2. Перейти к следующему указателю ->" << endl;
        cout << "3. Тестирование текущего объекта класса" << endl;
        cout << "q. Выход" << endl;
        cin >> menuSelector;
        switch (menuSelector) {
            case '1': {
                currentObjectNumber--;
                if (currentObjectNumber < 0) {
                    currentObjectNumber = countOfArrayPointers -
                                          1;//если мы выходим за рамки массива, присваиваем последнее значение, дабы не выйти за рамки массива
                }

                break;
            }
            case '2': // если мы выходим за рамки массива, присваиваем 0, дабы не выйти за рамки массива.
            {
                currentObjectNumber++;
                if (currentObjectNumber >= countOfArrayPointers) {
                    currentObjectNumber = 0;
                }
                break;
            }
            case '3':
                system("cls");
                switch (charStringPtrArray[currentObjectNumber]->getType())//определяем тип объекта и демонстрируем методы класса
                {
                    case '1': {
                        cout << "Демонстрация методов класса <<Строка>>:" << endl;
                        String *charStr = charStringPtrArray[currentObjectNumber];
                        cout << *charStr << endl;
                        do {
                            cout << "1. Задать новое значение для <<Строка>> " << endl;
                            cout << "q. Выйти" << endl;
                            cin >> classMethodSelector;
                            switch (classMethodSelector) {
                                case '1':
                                    cout << "Введите новое значение строки:" << endl;
                                    cin >> inputStringToClass;
                                    *charStr = inputStringToClass;
                                    break;
                                case 'q':
                                    break;
                                default:
                                    cout << "Данный пункт меню отсутствует в списке, повторите попытку" << endl;
                                    break;
                            }
                        } while (classMethodSelector != 'q');
                        break;
                    }
                    case '2': {
                        do {
                            system("cls");
                            cout << "Демонстрация методов класса <<Строка-Идентефикатор>>" << endl;
                            IdString *idString = static_cast<IdString *>(charStringPtrArray[currentObjectNumber]);//приводим указатель на базовый класс к классу IdString
                            cout << *idString << endl;
                            cout << "1. Задать новое значение для <<Строка-Идентефикатор> " << endl;
                            cout << "2. Поиск последнего вхождения символа в строку" << endl;
                            cout << "3. Сравнение строк операции '>'" << endl;
                            cout << "4. Сравнение строк операции '<'" << endl;
                            cout << "q. Выйти" << endl;
                            cin >> classMethodSelector;
                            switch (classMethodSelector) {
                                case '1': {
                                    cout << "Введите новое значение строки:" << endl;
                                    cin >> inputStringToClass;
                                    *idString = inputStringToClass;
                                    break;
                                }
                                case '2': {
                                    char find;
                                    cout << "Введите символ для поиска последнего вхождения: " << endl;
                                    cin >> find;
                                    idString->lastOccurrence(find);
                                    getchar();
                                    getchar();
                                    break;
                                }
                                case '3': {
                                    cout << "Введите строку для Сравнения" << endl;
                                    cin >> inputStringToClass;
                                    IdString idTempString(inputStringToClass);
                                    IdString idStringCopy(*idString);
                                    *idString = idTempString > idStringCopy;
                                }
                                case '4': {
                                    cout << "Введите строку для Сравнения" << endl;
                                    cin >> inputStringToClass;
                                    IdString idTempString(inputStringToClass);
                                    IdString idStringCopy(*idString);
                                    //*idString = idTempString < idStringCopy;
                                }
                                case 'q':
                                    break;
                                default:
                                    cout << "Данный пункт меню отсутствует в списке, повторите попытку" << endl;
                                    break;
                            }
                        } while (classMethodSelector != 'q');
                        break;
                    }
                    case '3': {
                        do {
                            system("cls");
                            cout << "Демонстрация методов класса <<Десятичная строка>>" << endl;
                            DecString *dec_str = static_cast<DecString *>(charStringPtrArray[currentObjectNumber]);//приводим указатель на базовый класс к классу Dec_string
                            cout << *dec_str << endl;
                            cout << "1. Задать новое значение для <<Десятичная строка>> " << endl;
                            cout << "2. Вычитание одного <<Десятичного числа>> из другого" << endl;
                            cout << "3. Сравнение одного <<Десятичного числа>> с другим" << endl;
                            cout << "q. Выйти" << endl;
                            cin >> classMethodSelector;
                            switch (classMethodSelector) {
                                case '1': {
                                    cout << "Введите новое значение строки:" << endl;
                                    cin >> inputStringToClass;
                                    *dec_str = inputStringToClass;
                                    break;
                                }
                                case '2': {
                                    cout << "Введите строку в десятичном формате для вычитания от заданной:" << endl;
                                    cin >> inputStringToClass;
                                    DecString decTempString(inputStringToClass);
                                    DecString decString(*dec_str);
                                    *dec_str = decString - decTempString;
                                    break;
                                }
                                case '3': {
                                    cout << "Введите строку в десятичном формате для сравнения с заданной:" << endl;
                                    cin >> inputStringToClass;
                                    DecString decTempString(inputStringToClass);
                                    DecString decString(*dec_str);
                                    (decString > decTempString) ? (*dec_str = decString) : (*dec_str = decTempString);
                                    break;
                                }
                                case 'q':
                                    break;
                                default: {
                                    cout << "Данный пункт меню отсутствует в списке, повторите попытку" << endl;
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
                cout << "Данный пункт меню отсутствует в списке, повторите попытку" << endl;
                break;
        }
        system("pause");
    } while (menuSelector != 'q');
    //автоматически определять, что перед нами за объект класса
    return 0;
}