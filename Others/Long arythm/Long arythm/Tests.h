#ifndef _TESTS_H_
#define _TESTS_H_

#include <iostream>
#include <cstdio>
#include "BigInt.h"

class IOTest {
	BigInt __tested_BigInt;
	BigInt::uint64 __tested_number;
	FILE* _output_file;

public:
	IOTest(FILE* _output_file = stdin) : _output_file(_output_file) { }

	void start_test() { 
		/* Testing default constructor */
		__tested_BigInt = BigInt();

		std::cout << "Default constructor" << std::endl;
		std::cout << __tested_BigInt << std::endl;
		std::cout << std::endl;

		std::cout << "Number asignment" << std::endl;

		/* Testing positive number's assignment */
		_number_test(5);
		_number_test(100000);
		_number_test(100010);
		_number_test(1111111);
		_number_test(1234567);

		/* Testing zero assignment */
		_number_test(0);

		system("pause");
	}
private:
	void _number_test(BigInt::uint64 _number) {
		__tested_BigInt = _number;
		std::cout << _number << std::endl;
		std::cout << __tested_BigInt << std::endl;
		std::cout << std::endl;
	}
};

class AddTest {
	BigInt lhs, rhs;
	void addition_test(BigInt::uint64 a, BigInt::uint64 b) {
		lhs = a;
		rhs = b;
		std::cout << lhs << " + " << rhs << " = " << lhs + rhs << std::endl;
		assert(lhs + rhs == lhs + b);
	}

	void addition_assignment_test(BigInt::uint64 a, BigInt::uint64 b) {
		lhs = a;
		rhs = b;
		lhs += rhs;
		std::cout << a << " + " << b << " = " << lhs << std::endl;
		lhs = a;
		lhs += b;
		rhs = b;
		rhs += a;
		assert(lhs == rhs);
	}

public:
	void start_test() {
		addition_test(0, 1);
		addition_test(1, 10);
		addition_test(9999999, 999999);
		addition_test(9, 1);
		addition_test(9999, 1);
		addition_test(15, 14);
		addition_test(50, 50);
		system("pause");

		addition_assignment_test(0, 1);
		addition_assignment_test(1, 10);
		addition_assignment_test(1, 9);
		addition_assignment_test(9, 1);
		addition_assignment_test(99, 11);
		addition_assignment_test(15, 14);
		addition_assignment_test(50, 50);
		system("pause");
	}
};

#endif // _TESTS_H_