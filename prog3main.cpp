
#include "biglong.h"

const char* messages1_0[] = {"Что вы хотите сделать?",
                             "0) Завершить тестирование",
                             "1) Изменить/посмотреть имеющийся объект",
                             "2) Инициализировать второй объект и проводить операции с первым"};
const char* messages1_1[] = {"0) Завершить тестирование",
                             "1) Изменить один элемент объекта",
                             "2) Инициализировать новый объект новым значением long и присвоить его этому",
                             "3) Инициализировать новый объект строкой char* и присвоить его этому",
                             "4) Инициализировать новый объект старым объектом и присвоить его старому",
                             "5) Узнать состояние объекта"};
const char* messages1_2[] = {"0) Завершить тестирование",
                             "1) Прибавить этот объект первому",
                             "2) Отнять первый объект от этого",
                             "3) Отнять от первого объекта этот объект"};

const int c_messages1_0 = sizeof(messages1_0) / sizeof(messages1_0[0]);
const int c_messages1_1 = sizeof(messages1_1) / sizeof(messages1_0[0]);
const int c_messages1_2 = sizeof(messages1_2) / sizeof(messages1_0[0]);

int main() {
    int choice1_0 = -1;
    int choice1_1 = 0;
    int choice1_2 = 0;
    std::cout << "Добро пожаловать в диалоговую тестировочную программу класса BigLong" << std::endl;
    laba3bit1::Biglong main_tester;               //объект по умолчанию
    while (1) {
        choice1_0 = -1;
        choice1_1 = 0;
        choice1_2 = 0;
        std::cout << "Инициализорован 1 объект по умолчанию, вы можете корректировать его и/"
                     "или добавить еще 1 объект и проводить с ними операции" << std::endl;
        while (choice1_0 == -1) {
            for (int i = 0; i < c_messages1_0; ++i) {
                std::cout << messages1_0[i] << std::endl;
            }
            laba3bit1::getNum(choice1_0);
            if (choice1_0 == 0) return 0;
            if ((choice1_0 > c_messages1_0) || (choice1_0 < 1)) {
                choice1_0 = -1;
            }
        }
        if (choice1_0 == 0) return 0;
        if (choice1_0 == 1) {
            while (choice1_1 == 0) {
                for (int i = 0; i < c_messages1_1; ++i) {
                    std::cout << messages1_1[i] << std::endl;
                }
                laba3bit1::getNum(choice1_1);
                if ((choice1_0 > c_messages1_1) || (choice1_0 < 1)) {
                    choice1_1 = 0;
                    std::cout << "Попробуйте ввести еще раз" << std::endl;
                }
            }
            if (choice1_1 == 0) return 0;
            if (choice1_1 == 1) {
                int number = 0, value = 0;
                std::cout << "Введите позицию изменяемого элемента и значение, на которое вы хотите его поменять"
                          << std::endl;
                laba3bit1::getNum(number);
                laba3bit1::getNum(value);
                main_tester.set_one_char(number, value);
                continue;
            }
            if (choice1_1 == 2) {
                std::cout << "Введите число" << std::endl;
                long init = 0;
                laba3bit1::getNum(init);
                laba3bit1::Biglong newest(init);
                main_tester = newest;
                continue;
            }
            if (choice1_1 == 3) {
                char* stroka;
                std::cout << "Введите строку" << std::endl;
                stroka = laba3bit1::readln();
                if (strlen(stroka) > main_tester.get_max_value()) {
                    std::cout << "Вы ввели слишком длинную строку, возвращаюсь в начало меню" << std::endl;
                    continue;
                }
                laba3bit1::Biglong newest(stroka);
                main_tester = newest;
                continue;
            }
            if (choice1_1 == 4) {
                laba3bit1::Biglong newest(main_tester);
                main_tester = newest;
                continue;
            }
            if (choice1_1 == 5) {
                std::cout <<  "Вот текущее состояние рабочего объекта:" << main_tester << std::endl;
                continue;
            }
            continue;
        }
        if (choice1_0 == 2) {
            while (choice1_2 == 0) {
                for (int i = 0; i < c_messages1_2; ++i) {
                    std::cout << messages1_2[i] << std::endl;
                }
                laba3bit1::getNum(choice1_2);
                if ((choice1_0 > c_messages1_2) || (choice1_2 < 1)) {
                    choice1_2 = 0;
                    std::cout << "Попробуйте ввести еще раз" << std::endl;
                }
            }
            if (choice1_2 == 0) return 0;
            std::cout << "Введите строку, с помощью которой будет инициализирован второй объект" << std::endl;
            char* stroka;
            stroka = laba3bit1::readln();
            if (strlen(stroka) > main_tester.get_max_value()) {
                std::cout << "Вы ввели слишком длинную строку, возвращаюсь в начало меню" << std::endl;
                continue;
            }
            laba3bit1::Biglong newest(stroka);
            if (choice1_2 == 1) {
                newest = main_tester + newest;
            }
            if (choice1_2 == 2) {
                newest = newest - main_tester;
            }
            if (choice1_2 == 3) {
                newest = main_tester - newest;
            }
            std::cout << "Результат данных вычислений = " << newest << std::endl;
        }
    }

}
