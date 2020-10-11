#include <iostream>
#include "biglong.h"


int main() {
    std::cout << "Добро пожаловать на лабу номер 3" << std::endl;
    long b;
    char massiv[] = "123456789";
    laba3bit1::Biglong atest(massiv);
    laba3bit1::Biglong a(atest);
    std::cout << a << std::endl;
    a.div10();
    std::cout << a << std::endl;
    a.multi10();
    std::cout << a << std::endl;
    a.multi10();
    std::cout << a << std::endl;
    std::cin >> a;
    std::cout << a << std::endl;
}
