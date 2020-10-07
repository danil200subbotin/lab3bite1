//
// Created by Данил Морозов on 06/10/2020.
//

#include "biglong.h"
#include <cmath>
#include <iostream>
//#include <cstring>



laba3bit1::Biglong::Biglong(long parametr) {
    int counter = 0;
    long parametr_copy = parametr;
    if (parametr > 0)
        Biglong::value[0] = 0;
    else
        Biglong::value[0] = 1;
    parametr_copy = fabs(parametr_copy);
    while (parametr_copy > 0) {
        Biglong::value[MAX_LENGTH - counter] = char(parametr_copy % 10);
        parametr_copy = parametr_copy / 10;
        ++counter;
    }
    Biglong::length = counter;
    for (int i = 1; i <= MAX_LENGTH - counter; ++i) {
        Biglong::value[i]  = 0;
    }
}


laba3bit1::Biglong::Biglong(const char *char_value) {
    int i  = int(strlen(char_value)) - 1, j = 0;
    if (i > MAX_LENGTH)
        throw "попытка присвоить объекту слишком длинной строки";
    if (char_value[0] == '-') {
        value[0] = 1;
        j++;
        --i;
    }
    else {
        if (((int)char_value[0] < '0') || ((int)char_value[0] > '9')) {
            throw "Попытка инициализировать класс некорректной строкой";
        }
    }
    Biglong::length = i;
    while (char_value[j] != '\0') {
        if (((int)char_value[j] >= '0') & ((int)char_value[j] <= '9')) {
            value[MAX_LENGTH - i + 1] = char_value[j];
            --i;
            ++j;
        }
        else {
            std::cout << "В строке встретился не числовой символ" << std::endl;
            throw "В строке встретился не числовой символ";
        }
        ++i;
    }
    for (int i = 1; i <= MAX_LENGTH - Biglong::length; ++i) {
        Biglong::value[i]  = 0;
    }

}

void laba3bit1::Biglong::div10() {
    for (int i = MAX_LENGTH; i > 1; --i) {
        Biglong::value[i] = Biglong::value[i - 1];
    }
}

void laba3bit1::Biglong::multi10() {
    if (Biglong::value[1] == 0)
        for (int i = 1; i < MAX_LENGTH; --i) {
            Biglong::value[i] = Biglong::value[i + 1];
        }
    else
        throw "невозможно выполнить умножение из-за опасности переполнения стека";
}

laba3bit1::Biglong::Biglong(laba3bit1::Biglong &biglong) {
    Biglong::length = biglong.get_length();
    for (int i = 0; i <= MAX_LENGTH; ++i) {
        Biglong::value[i] = biglong.get_one_num(i);
    }
}



//const laba3bit1::Biglong operator~ () const {

//----------------------------------------------------------------------тут пошла часть с перегрузками-----------------


//вывод класса в поток
std::ostream & operator<< (std::ostream &stream, laba3bit1::Biglong &biglong) {
    int i = 1;
    if (biglong.get_one_num(0) == 1)
        std::cout << "-";
    while (i < biglong.get_length()) {
        std::cout << biglong.get_one_num(i);
        ++i;
    }
    std::cout << std::endl;
    return stream;
}




std::istream & operator>> (std::istream &istream, laba3bit1::Biglong &biglong) {
    char streamer[biglong.get_max_value() + 1];
    istream >> streamer;                                                //здесь может быть считывание нормальной строки
    int i  = int(strlen(streamer) - 1), j = 0;
    if (i > biglong.get_max_value())
        throw "попытка присвоить объекту слишком длинной строки";
    if (streamer[0] == '-') {
        biglong.set_one_num(0, 1);
        j++;
        --i;
    }
    else {
        biglong.set_one_num(0, 0);
        if (((int)streamer[0] < '0') || ((int)streamer[0] > '9')) {
            throw "Попытка инициализировать класс некорректной строкой";
        }
    }
    biglong.set_length(i);
    while (streamer[j] != '\0') {
        if (((int)streamer[j] >= '0') & ((int)streamer[j] <= '9')) {
            biglong.set_one_num(biglong.get_max_value() - i + 1, streamer[j]);
            --i;
            ++j;
        }
        else {
            std::cout << "В строке встретился не числовой символ" << std::endl;
            throw "В строке встретился не числовой символ";
        }
        ++i;
    }
    return istream;
}






