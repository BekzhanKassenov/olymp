#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Big integers are unsigned
class BigInt {
public:
	typedef unsigned int uint32;
	typedef unsigned long long uint64;

	static const uint32 BASE        = 10000; // Assumed to be power of ten
	static const uint32 BASE_LENGTH = 4;     // Exponent of base
	
	static const BigInt ZERO;
	static const BigInt ONE;

private:
	std::vector <uint32> _digits; // Digits of number, stored in reverse order

public:
	/* Constructors */
	BigInt();
	BigInt(const std::vector <uint32>& _digits);	
	BigInt(uint64 _number);
	BigInt(const std::string& _number);

	/* Addition operators */
	friend BigInt operator + (BigInt _lhs, const BigInt& _rhs);
	friend BigInt& operator += (BigInt& _lhs, const BigInt& _rhs);

	/* Subtraction operators */
	friend BigInt operator - (BigInt _lhs, const BigInt& _rhs); // Not implemented
	friend BigInt& operator -= (BigInt& _lhs, const BigInt& _rhs); // Not implemented

	/* Multiplication opertors */
	friend BigInt operator * (const BigInt& _lhs, const BigInt& _rhs);
	friend BigInt operator * (BigInt _lhs, uint64 _number);
	
	friend BigInt& operator *= (BigInt& _lhs, uint64 _number);
	friend BigInt& operator *= (BigInt& _lhs, const BigInt& _rhs);

	/* Modulo operators */
	friend BigInt operator % (BigInt _lhs, uint64 _number);
	friend BigInt& operator %= (BigInt& _lhs, uint64 _number);

	/* Division operators */
	friend BigInt operator / (BigInt _lhs, uint64 _number); // Not implemented
	friend BigInt& operator /= (BigInt& _lhs, uint64 _number); // Not implemented

	/* Comparison operators */
	static bool less(const BigInt& _lhs, const BigInt& _rhs);

	friend bool operator < (const BigInt& _lhs, const BigInt& _rhs);
	friend bool operator > (const BigInt& _lhs, const BigInt& _rhs);
	friend bool operator <= (const BigInt& _lhs, const BigInt& _rhs);
	friend bool operator >= (const BigInt& _lhs, const BigInt& _rhs);
	friend bool operator == (const BigInt& _lhs, const BigInt& _rhs);
	friend bool operator != (const BigInt& _lhs, const BigInt& _rhs);

	/* Input-output streams */
	friend std::ostream& operator << (std::ostream& _output_stream, const BigInt& _number);
	friend std::istream& operator >> (std::istream& _input_stream, BigInt& _number); // Not implemented

	std::string to_string() const;
private:
	/* Some helper functions */
	// Initializtion helpers
	void __init_with_vector(const std::vector <uint32>& _number);
	void __init_with_number(uint64 _number);
	void __init_with_string(const std::string& _number);
	void __trim();

	void __sum_this(const BigInt& _rhs);
	void __sub_this(const BigInt& _rhs); // Not implemented
	void __mul_this(uint64 _number);
	void __mod_this(uint64 _number);
	void __div_this(uint64 _number);

	static BigInt __mul(const BigInt& _lhs, const BigInt& _rhs);
};

const BigInt BigInt::ONE  = 1;
const BigInt BigInt::ZERO = 0;

/*=================================================*
 *                                                 *
 *      Constructors and assignment operators      *
 *                                                 *
 *=================================================*/

/* Constructors */
BigInt::BigInt() { 
	_digits.push_back(0);
}

BigInt::BigInt(const std::vector <uint32>& _digits) { 
	__init_with_vector(_digits);
}

BigInt::BigInt(uint64 _number) {
	__init_with_number(_number);   
}

BigInt::BigInt(const std::string& _number) {
	__init_with_string(_number);
}

/* Initialization helpers */
void BigInt::__init_with_number(uint64 _number) {
	_digits.clear();

	while (_number > 0) {
		_digits.push_back(_number % BASE);
		_number /= BASE;
	}

	__trim();
}

// Initializtion with vector
// Works with assumption that every 
// element of _number is less that BigInt::BASE
void BigInt::__init_with_vector(const std::vector<BigInt::uint32>& _number) {
	if (&_digits != &_number) {
		_digits = _number;
	}

	__trim();
}

// Initialization with string
// Works with assumption that string consists only of digits
void BigInt::__init_with_string(const std::string& _number) {
	_digits.clear();

	if (_number.empty()) {
		_digits.push_back(0u);
		return;
	}

	_digits.reserve((_number.size() + BigInt::BASE - 1) / BigInt::BASE);
	for (int i = _number.size(); i > 0; i -= BigInt::BASE_LENGTH) {
		BigInt::uint32 _new_digit = 0;
		for (int j = std::max(i - (int)BigInt::BASE_LENGTH, 0); j < i; j++) {
			_new_digit = _new_digit * 10 + _number[j] - '0';
		}
		_digits.push_back(_new_digit);
	}

	__trim();
}

void BigInt::__trim() {
	while (!_digits.empty() && _digits.back() == 0u) {
		_digits.pop_back();
	}

	if (_digits.empty()) {
		_digits.push_back(0u);
	}
}

std::string BigInt::to_string() const {
	std::stringstream _result;
	std::vector <BigInt::uint32>::const_reverse_iterator _digit;
	_digit = _digits.rbegin();

	_result << *_digit;
	_digit++;

	for (; _digit != _digits.rend(); _digit++) {
		_result << std::setw(BigInt::BASE_LENGTH) << std::setfill('0');
		_result << *_digit;
	}

	return _result.str();
}

/*=================================================*
 *                                                 *
 *              Addition operators                 *
 *                                                 *
 *=================================================*/

BigInt operator + (BigInt _lhs, const BigInt& _rhs) {
	_lhs.__sum_this(_rhs);
	return _lhs;
}

BigInt& operator += (BigInt& _lhs, const BigInt& _rhs) {
	_lhs.__sum_this(_rhs);
	return _lhs;
}

// Main algorithm for addition operators
void BigInt::__sum_this(const BigInt& _rhs) {
	uint32 _carry = 0;
	std::size_t _digits_size = _digits.size();
	std::size_t  _other_size = _rhs._digits.size();
		
	for (std::size_t i = 0; i < _digits_size; i++) {
		_carry += _digits[i];

		if (i < _other_size)
			_carry += _rhs._digits[i];

		_digits[i] = _carry % BigInt::BASE;
		_carry /= BigInt::BASE;
	}
		
	for (std::size_t i = _digits_size; i < _other_size; i++) {
		_carry += _rhs._digits[i];

		_digits.push_back(_carry % BigInt::BASE);
		_carry /= BigInt::BASE;
	}

	while (_carry > 0) {
		_digits.push_back(_carry % BigInt::BASE);
		_carry /= BigInt::BASE;
	}
}

/*=================================================*
 *                                                 *
 *           Multiplication operators              *
 *                                                 *
 *=================================================*/

/* Multiplication */
BigInt operator * (const BigInt& _lhs, const BigInt& _rhs) {
	return BigInt::__mul(_lhs, _rhs);
}

BigInt operator * (BigInt _lhs, BigInt::uint64 _number) {
	if (_number < BigInt::BASE) {
		_lhs.__mul_this(_number);
		return _lhs;
	}

	return BigInt::__mul(_lhs, BigInt(_number));
}

BigInt& operator *= (BigInt& _lhs, const BigInt& _rhs) {
	_lhs = BigInt::__mul(_lhs, _rhs);
	return _lhs;
}

BigInt& operator *= (BigInt& _lhs, BigInt::uint64 _number) {
	if (_number < BigInt::BASE) {
		_lhs.__mul_this(_number);
	} else {
		_lhs = BigInt::__mul(_lhs, BigInt(_number));
	}

	return _lhs;
}

// Multiplication of long number by short number
// Works with assumpltion that _number < BASE
void BigInt::__mul_this(BigInt::uint64 _number) {
	BigInt::uint64 _carry = 0;

	for (std::size_t i = 0; i < _digits.size(); i++) {
		_carry += _digits[i] * _number;
		_digits[i] = _carry % BigInt::BASE;
		_carry /= BigInt::BASE;
	}

	while (_carry > 0) {
		_digits.push_back(_carry % BigInt::BASE);
		_carry /= BigInt::BASE;
	}
	
	__trim();
}


/* 
 * Uses O(n^2) algorithm for multiplication
 * Main idea: multiplication of i-th digit of first number  
 * and j-th digit of second number will be added to 
 * (i + j)-th digit of result.
 *
 * Proof: (a * (BASE ^ i)) is i-th digit of first number
 *        (b * (BASE ^ j)) is j-th digit of second number
 *        (a * (BASE ^ i)) * (b * (BASE ^ j)) = (a * b) * (BASE ^ (i + j))
*/
BigInt BigInt::__mul(const BigInt& _lhs, const BigInt& _rhs) {
	BigInt _result_BigInt;
	std::vector<BigInt::uint32>& _result = _result_BigInt._digits;
	_result.resize(_lhs._digits.size() + _rhs._digits.size());
	
	BigInt::uint64 _carry = 0;

	for (std::size_t i = 0; i < _lhs._digits.size(); i++) {
		for (std::size_t j = 0; j < _rhs._digits.size() || _carry; j++) {
			_carry += _result[i + j];

			if (j < _rhs._digits.size())
				_carry += BigInt::uint64(_lhs._digits[i]) * BigInt::uint64(_rhs._digits[j]);

			_result[i + j] = _carry % BigInt::BASE;
			_carry /= BigInt::BASE;
		}
	}

	_result_BigInt.__trim();

	return _result_BigInt;
}


/*=================================================*
 *                                                 *
 *                Modulo operators                 *
 *                                                 *
 *=================================================*/

BigInt operator % (BigInt _lhs, BigInt::uint64 _number) {
	_lhs.__mod_this(_number);
	return _lhs;
}

BigInt& operator %= (BigInt& _lhs, BigInt::uint64 _number) {
	_lhs.__mod_this(_number);
	return _lhs;
}

void BigInt::__mod_this(BigInt::uint64 _number) {
	BigInt::uint64 _carry = 0;

	for (std::vector <BigInt::uint32>::const_reverse_iterator it = _digits.rbegin(); 
		 it != _digits.rend();
		 it++) {

		_carry *= BigInt::BASE;
		_carry += *it;
		_carry %= _number;
	}
	
	__init_with_number(_carry);
}

/*=================================================*
 *                                                 *
 *               Division operators                *
 *                                                 *
 *=================================================*/

BigInt operator / (BigInt _lhs, BigInt::uint64 _number) {
	_lhs.__div_this(_number);
	return _lhs;
}

BigInt& operator /= (BigInt& _lhs, BigInt::uint64 _number) {
	_lhs.__div_this(_number);
	return _lhs;
}

void BigInt::__div_this(BigInt::uint64 _number) {
	BigInt::uint64 _carry = 0;

	for (std::vector <BigInt::uint32>::reverse_iterator it = _digits.rbegin();
		 it != _digits.rend();
		 it++) {
		
		_carry *= BigInt::BASE;
		_carry += *it;
		*it = _carry / _number;
		_carry %= _number;
	}

	__trim();
}

/*=================================================*
 *                                                 *
 *             Comparison operators                *
 *                                                 *
 *=================================================*/

// Main comparator
bool BigInt::less(const BigInt& _lhs, const BigInt& _rhs) {
	const std::vector <BigInt::uint32>& _l_digits = _lhs._digits;
	const std::vector <BigInt::uint32>& _r_digits = _rhs._digits;

	if (_l_digits.size() != _r_digits.size()) {
		return _l_digits.size() < _r_digits.size();
	}

	int _length = (int)_l_digits.size();
	for (int i = _length - 1; i >= 0; i--) {
		if (_l_digits[i] != _r_digits[i]) {
			return _l_digits[i] < _r_digits[i];
		}
	}

	return false;
}

bool operator < (const BigInt& _lhs, const BigInt& _rhs) {
	return BigInt::less(_lhs, _rhs);
}

bool operator > (const BigInt& _lhs, const BigInt& _rhs) {
	return BigInt::less(_rhs, _lhs);
}

bool operator <= (const BigInt& _lhs, const BigInt& _rhs) {
	return !BigInt::less(_rhs, _lhs);
}

bool operator >= (const BigInt& _lhs, const BigInt& _rhs) {
	return !BigInt::less(_lhs, _rhs);
}

bool operator == (const BigInt& _lhs, const BigInt& _rhs) {
	return !BigInt::less(_lhs, _rhs) && !BigInt::less(_rhs, _lhs);
}

bool operator != (const BigInt& _lhs, const BigInt& _rhs) {
	return BigInt::less(_lhs, _rhs) || BigInt::less(_rhs, _lhs);
}

/*=================================================*
 *                                                 *
 *             IOStream input-output               *
 *                                                 *
 *=================================================*/
std::ostream& operator << (std::ostream& _output_stream, const BigInt& _number) {
	_output_stream << _number.to_string();

	return _output_stream;
}

std::istream& operator >> (std::istream& _input_stream, BigInt& _number) {
	std::string _temp_string;
	_input_stream >> _temp_string;

	_number.__init_with_string(_temp_string);

	return _input_stream;
}
#endif //_BIGINT_H_

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BigInt a;
    BigInt::uint64 b;

    cin >> a >> b;

    cout << a / b << endl;

    return 0;
}
