#include <iostream>
#include <math.h>


class Integral {
public:


	Integral(double a, double b, double h) {
		m_a = a;// нижняя граница
		m_b = b;// верхняя граница
		m_h = h;//шаг интегрирования
		m_n = (b - a) / h;//число разбиений

	}

	virtual void Comp() {

	}
	~Integral() {

	}


protected:
	double m_a, m_b, m_h, m_n;
};

class Simpson : public Integral {
public:
	Simpson(double a, double b, double h) :Integral(a, b, h) {

	}
	~Simpson() {

	}


	void Comp(double (*func)(double))   {
		double res;
		res = m_h * (func(m_a) + func(m_b)) / 6.0;
		for (int i = 1; i <= m_n; i++)
			res = res + 4.0 / 6.0 * m_h * func(m_a + m_h * (i - 0.5));
		for (int i = 1; i <= m_n - 1; i++)
			res = res + 2.0 / 6.0 * m_h * func(m_a + m_h * i);
		m_res = res;
	}
	double Result() {
		return m_res;
	}
private:
	double m_res;
};



class Trapeze : public Integral {
public:
	Trapeze(double a, double b, double h) :Integral(a, b, h) {

	}
	~Trapeze() {

	}


	void Comp(double (*func)(double)){
		double res;
		res = m_h * (func(m_a) + func(m_b)) / 2.0;
		for (int i = 1; i <= m_n - 1; i++)
			res = res + m_h * func(m_a + m_h * i);
		m_res = res;
	}
	double Result() {
		return m_res;
	}
private:
	double m_res;
};


double func(double x)
{
	return (sin(x)) * (sin(x));
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double a = 2;
	double b = 6;
	double h = 1;
	Simpson Int(a, b, h);
	Int.Comp(&func);
	std::cout << "По формуле Симпсона: " << Int.Result() << std::endl << std::endl;

	Trapeze IntTwo(a, b, h);
	IntTwo.Comp(&func);
	std::cout << "По формуле трапеций: " << IntTwo.Result();


}
