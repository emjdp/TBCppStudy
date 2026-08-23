// Chapter20_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm> // std::min

// Reference : http://thbecker.net/articles/auto_and_decltype/section_01.html

using namespace std;

class Examples
{
public:

	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr : vect)
			cout << itr;
	}

	void ex2()
	{
		int x = int();
		auto auto_x = x;

		const int& crx = x;
		auto auto_crx1 = crx;
		const auto& auto_crx2 = crx;

		volatile int vx = 1024;
		auto avx = vx;
		volatile auto vavx = vx;
	}

	template<class T>
	void ex3_func1(T t)
	{}

	template<class T>
	void ex3_func2(T& t)
	{}

	template<class T>
	void ex3_func3(const T& t)
	{}

	void ex3()
	{
		const int& crx = 123;
		ex3_func1(crx);
		ex3_func2(crx);
		ex3_func3(crx);
	}

	void ex4()
	{
		const int c = 0;
		auto& rc = c;
		// rc = 123; // error
	}

	void ex5()
	{
		int i = 40;
		auto&& ri_1 = i; // ri_1 is int&
		auto&& ri_2 = 42; // ri_2 is int&&
		auto&& ri_3 = std::move(i); // ri_3 is int&&
	}

	void ex6()
	{
		int i = 40;
		const int* pi = &i;
		auto p = pi; // p is const int*
	}

	void ex7()
	{
		// generic lambda
		auto func = [](auto x, auto y) { return x + y; };
		cout << func(1.1, 5) << "  " << func(3.7, 23.1) << '\n';
	}

	template<typename T1, typename T2>
	void ex8_func(T1 lvar, T2 rvar)
	{
		auto prod1 = lvar * rvar;

		typedef decltype(lvar * rvar) product_type; // not calculated, only deduced!
		product_type prod2 = lvar * rvar;

		decltype(lvar * rvar) prod3 = lvar * rvar;
	}

	void ex8()
	{
		ex8_func(1.1, 2);
	}

	template<typename T1, typename T2>
	auto ex9_func(T1 lvar, T2 rvar) -> decltype(lvar * rvar)
	{
		return lvar * rvar;
	}

	void ex9()
	{
		cout << ex9_func(1.1, 2) << endl;
	}

	struct S
	{
		int m_x;
		S()
		{
			m_x = 42;
		}
	};

	const S foo() { return S(); }
	const int& foobar() { static int x = 123; return x; }

	void ex10()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S* p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		auto d = p;
		auto e = p->m_x;

		typedef decltype(x) x_type;
		typedef decltype(cx) cx_type;
		typedef decltype(crx) crx_type;
		typedef decltype(p->m_x) m_x_type;

		typedef decltype((x)) x_with_parens_type; // int&
		typedef decltype((cx)) cx_with_parens_type; // const int&
		typedef decltype((crx)) crx_with_parens_type; // const int&
		typedef decltype((p->m_x)) m_x_with_parens_type; // const int&
	}

	void ex11()
	{
		std::vector<int> vec = { 10, 20 };

		auto a = foo();
		typedef decltype(foo()) foo_type;

		auto b = foobar();
		typedef decltype(foobar()) foobar_type;

		auto itr = vec.begin();
		typedef decltype(vec.begin()) iterator_type;

		auto firstElement = vec[0];
		decltype(vec[0]) secondElement = vec[0];
	}

	void ex12()
	{
		int x = 0;
		int y = 0;
		const int cx = 40;
		const int cy = 50;
		double d1 = 3.14;
		double d2 = 9.8;

		typedef decltype(x * y) prod_xy_type;
		auto a = x * y;

		typedef decltype(cx * cy) prod_cxcy_type;
		auto b = cx * cy;

		typedef decltype(d1 < d2 ? d1 : d2) cond_type; // double&
		auto c = d1 < d2 ? d1 : d2;

		typedef decltype(x < d2 ? x : d2) cond_type_mixed; // double
		auto d = x < d2 ? x : d2;
	}

	template<typename T1, typename T2>
	auto fpmin_wrong(T1 x, T2 y) -> decltype(x < y ? x : y)
	{
		return x < y ? x : y;
	}

	template<typename T1, typename T2>
	auto fpmin(T1 x, T2 y) -> typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}

	void ex13()
	{
		int i = 42;
		double d = 45.1;
		auto a = std::min(static_cast<double>(i), d);

		int& j = i;

		typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1; // double&
		typedef decltype(fpmin_wrong(i, d)) fpmin_return_type2; // double
		typedef decltype(fpmin_wrong(j, d)) fpmin_return_type3; // double
		typedef decltype(fpmin(d, d)) fpmin_return_type4; // double
	}

	void ex14()
	{
		std::vector<int> vec;
		typedef decltype(vec[0]) integer;
	}

	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor()
		{}

		result_type operator() ()
		{
			return R();
		}
	};

	void ex15()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type integer;
	}

	void ex16()
	{
		auto func = []() { return 42; };
		decltype(func) func2(func);
		decltype((func)) func3(func);

		cout << "func 주소 = " << &func << "\tfunc 값 = " << func() << '\n';
		cout << "func2 주소 = " << &func2 << "\tfunc2 값 = " << func2() << '\n';
		cout << "func3 주소 = " << &func3 << "\tfunc3 값 = " << func3() << '\n';
	}
};

int main()
{
	Examples examples;

	examples.ex1();
	examples.ex2();
	examples.ex3();
	examples.ex4();
	examples.ex5();
	examples.ex6();
	examples.ex7();
	examples.ex8();
	examples.ex9();
	examples.ex10();
	examples.ex11();
	examples.ex12();
	examples.ex13();
	examples.ex14();
	examples.ex15();
	examples.ex16();

	return 0;
}
