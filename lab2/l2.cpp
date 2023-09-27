#include <iostream>


class Fraction {
public:
    Fraction (int numerator) {
        m_numerator = numerator;
    }
    Fraction(int numerator, int denominator) {
        m_numerator = numerator;
        if (denominator != 0) {
            m_denominator = denominator;
        }
        else {
            throw "znam = 0?";
        }
    }
    Fraction() {

    }
    ~Fraction() {

    }

    int Numerator() {
        return (m_numerator);
    }


    int Denominator() {
        return (m_denominator);
    }


    Fraction Revers() {
        Fraction a(m_denominator, m_numerator);
        return (a);
    }

    void Print() {
        std::cout << m_numerator << "/" << m_denominator;
    }

     double Decimal() {
        return ((double)m_numerator / (double)m_denominator);
      }


     void Reduction() {
         int a;
         if (m_numerator == m_denominator) {
             m_numerator = 1;
             m_denominator = 1;
         }
         else {
             if (m_numerator > m_denominator) {
                 a = m_denominator;
             }
             else {
                 a = m_numerator;
             }
             for (int i = 2; i <= a; i++) {
                 if (m_numerator % i == 0 && m_denominator % i == 0) {
                     m_numerator = m_numerator / i;
                     m_denominator = m_denominator / i;
                     a = a / i;
                     i = 1;
                 }
             }
         }

     }

private:
    int m_numerator = 0;
    int m_denominator = 1;

};


Fraction operator +(Fraction a, Fraction b) {
    int ch = a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator();
    int zn = a.Denominator() * b.Denominator();
    Fraction c(ch, zn);
    return (c);
}

Fraction operator -(Fraction a, Fraction b) {
    int ch = a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator();
    int zn = a.Denominator() * b.Denominator();
    Fraction c(ch, zn);
    return (c);
}

Fraction operator *(Fraction a, Fraction b) {
    int ch = a.Numerator() * b.Numerator() ;
    int zn = a.Denominator() * b.Denominator();
    Fraction c(ch, zn);
    return (c);
}

Fraction operator /(Fraction a, Fraction b) {
    int ch = a.Numerator() * b.Denominator();
    int zn = a.Denominator() * b.Numerator();
    Fraction c(ch, zn);
    return (c);
}




int main()
{
    setlocale(LC_ALL, "Russian");
  
    Fraction three;
    bool tmp = 0;

    while (1) {
        int a, b;
        Fraction one;
        if (tmp == 0) {
            std::cout << "Введите первую дробь (1 2; 3 6; 3)" << std::endl;
            std::cin >> a >> b;
            Fraction dop(a, b);
           one = dop;
            
        }
        else {
            std::cout << "Первая дробь: " ;
            one = three;
            one.Print();
            std::cout << std::endl;
        }
        std::cout << "Введите вторую дробь (1 2; 3 6; 3)" << std::endl;
        std::cin >> a >> b;
        Fraction two(a, b);
        std::cout << "Выберети операцию:" << std::endl << "1. +" << std::endl << "2. -" << std::endl<< "3. *" << std::endl<<"4. /" << std::endl;
  
        while (1) {
            char c;
            std::cin >> c;
            if (c == '1' || c == '+') {
                three = one + two;

                three.Print();
                break;
            }
            else if ( c == '2' || c == '-') {
                three = one - two;

                three.Print();
                break;
            }
            else if ( c == '3' || c == '*') {
                three = one * two;

                three.Print();
                break;
            }
            else if ( c == '4' || c == '/') {
                three = one / two;

                three.Print();
                break;
            }
            else  {
                std::cout << "Такой операции нет" << std::endl;
                
            }
        }

        std::cout <<std::endl<< "1. Сократить результат" << std::endl << "2. Перевести в десятичную дробь" << std::endl;
        while (true)
        {
           char c;
            std::cin >> c;
            if (c == '1') {
                three.Reduction();
                three.Print();
                break;
            }
            else if (c == '2') {

                std::cout << three.Decimal();
              
                break;
            }
            else {
                std::cout << "Такой операции нет" << std::endl;
            }
        }


        std::cout <<std::endl<< "1. Продолжить вычисления с текущим числом" << std::endl << "2. Заново" << std::endl;

        while (1) {
            char c;
            std::cin >> c;
            if (c == '1') {
                tmp = 1;
                break;
            }
            else if (c == '2') {
                tmp = 0;
                break;
            }
        }
    }

    return 0;
}
