#include <iostream>
#include <string>  // Додано для включення заголовкового файлу для функції to_string

// Клас Logger відповідає за логування повідомлень.
class Logger {
public:
    // Метод log приймає рядок повідомлення та виводить його на консоль.
    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

// Клас Calculator відповідає за виконання обчислень та використання Logger для логування.
class Calculator {
private:
    Logger& logger;  // Посилання на об'єкт Logger для логування.

public:
    // Конструктор приймає посилання на Logger і ініціалізує його відповідним членом класу.
    Calculator(Logger& logger) : logger(logger) {}

    // Метод add виконує додавання двох чисел, логує операцію та повертає результат.
    int add(int a, int b) {
        int result = a + b;

        // Викликаємо метод log об'єкта Logger для запису результату операції.
        logger.log("Adding: " + std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(result));

        return result;
    }
};

// Точка входу в програму.
int main() {
    // Створюємо об'єкт Logger для логування.
    Logger logger;

    // Створюємо об'єкт Calculator, передаючи йому створений об'єкт Logger для логування.
    Calculator calculator(logger);

    // Викликаємо метод add для додавання чисел та логування результату.
    calculator.add(5, 3);

    return 0;
}
