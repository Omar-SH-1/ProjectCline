#include <iostream>
#include <list>

class Logger {
private:
    inline static int counter = 0;

    const int id;

public:
    Logger(Logger&& other): id(++counter) {
        std::cout << "Logger(&&): " << id << "\n";
    }

    Logger& operator = (Logger&& other) {
        std::cout << "=&&;" << id<< "\n";
        return *this;
    }
    Logger(): id(++counter) {
        std::cout << "Logger(): " << id << "\n";
    }

    Logger(const Logger& other): id(++counter) {
        std::cout << "Logger(const Logger&): " << id << "\n";
    }

    Logger& operator = (const Logger& other) {

        std::cout << "Logger& operator = (const Logger&) " << id << "\n";
        return *this;
    }

    ~Logger() {
        std::cout << "~Logger() " << id << "\n";
    }
};
void f(const Logger& x) {
    std::cout << "void f\n";
}
void f(Logger&& x){
    std::cout << "void f temp\n";
}

int main() {
    Logger x1;
    Logger x2;
    x2=x1;
    x2=std::move(x1);
}
