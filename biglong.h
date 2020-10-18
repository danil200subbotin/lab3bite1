//
// Created by Данил Морозов on 06/10/2020.
//

#ifndef LAB3BYTE1_BIGLONG_H
#define LAB3BYTE1_BIGLONG_H
#include <iostream>
#include <stdexcept>

namespace laba3bit1 {


    class Biglong {
    private:
        static const int MAX_LENGTH = 10;
        int length;
        char value[MAX_LENGTH + 1]{};             //+ 1 для знака
    public:
        //конструктры
        Biglong();    //пустой конструктор    //дописать
        explicit Biglong(long parameter);  //инициализайия через длинное целое
        Biglong(const char *char_value);  //инициализация по строки
        Biglong(const Biglong &biglong);        //копирующий конструктор
        //геттеры
        int get_length() const { return length; };
        char get_one_char(int i) const { return value[i]; };
        int get_max_value() const { return MAX_LENGTH; };
        //сеттеры
        void set_one_char(int number, int value);    //переделать назначение строки
        void set_length(int new_length) { Biglong::length = new_length; };
        void div10();    //выполнение операции “уменьшения числа в десять раз” (деление на 10 нацело)ы
        void multi10();  //выполнение операции “увеличения числа в десять раз”
        //часть с перегрузками
        friend std::ostream &operator<<(std::ostream &ostream, const Biglong &biglong); //выввод в входной поток
        friend std::istream &operator>>(std::istream &istream, Biglong &biglong); //ввод из входного потока
        const Biglong operator~() const;
        Biglong& operator ++();//получение дополнительного кода числа ((*) с помощью перегруженного оператора ~ )
        const Biglong operator+(const Biglong &argumnet) const;    //выполнение операций сложения
        const Biglong operator-(const Biglong &argument) const;
        const Biglong operator=(const Biglong &argument);
    };

    char *readln(void);
    char num_to_char(int);
    int char_to_num(char a);

    template<class T>
    double getNum(T &a) {                //проверочка ввода соответствующего типа данных
        int i = 1;
        while (i == 1) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> a;
            if (!std::cin.good())
                i = 1;
            else
                i = 0;
            if (i != 0) std::cout << "Вы ввели неприемлимое значение, повторите ввод" << std::endl;
        }
        return 0;
    }
}

#endif //LAB3BYTE1_BIGLONG_H
