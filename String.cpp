//
// Created by Renat Kabirov on 2021-06-16.
//
#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

String::String() {
    objectType = '1';
    stringPtr = 0;
    stringLength = 0;
}

String::String(const String& copyStr) //����������� �����������
{
    objectType = '1';
    stringPtr = copyStr.stringPtr;
    stringLength = copyStr.stringLength;
    countCopyConstructor++;
    cout << "���������� ������� ������������ �����������: " << countCopyConstructor << endl;
}

String::String(const char* charStringPtr) //�����������, ����������� ��-������
{
    objectType = '1';
    stringLength = strlen(charStringPtr);
    stringPtr = new char[stringLength + 1];
    for (int i = 0; i < stringLength; i++) {
        stringPtr[i] = charStringPtr[i];
    }
    stringPtr[stringLength] = '\0';
}

String::String(char symbol) //�����������, ����������� 1 ������ ��-������
{
    objectType = '1';
    //����� ������ = 2, ���� ��� ������ � ������ ��� ����� ������ \0
    stringLength = 2;
    stringPtr = new char[stringLength];
    stringPtr[0] = symbol;
    stringPtr[1] = '\0';
}

String::~String() {
}



String& String::operator=(const String& str)//���������� ��������� ���������
{
    stringPtr = str.stringPtr;
    stringLength = str.stringLength;
    return *this;//����������� ��������� �� ������� ������
    str.~String();//�������� ������ �����
}

ostream& operator<<(ostream& out, const String& str) //���������� ��������� ��������� ������
{
    //������������ ���������� ������
    out << "����� ������: ";
    for (int i = 0; i < str.stringLength; i++) {
        cout << str.stringPtr[i];
    }
    out << "\n����� ������: " << str.stringLength << endl;
    return out;
}
