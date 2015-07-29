#ifndef _BIGINT_H_
#define _BIGINT_H_
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cassert>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <vector>

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
	BigInt(const BigInt& _rhs);
	BigInt(const std::vector <uint32>& _digits);	
	BigInt(uint64 _number);
	BigInt(const std::string& _number);

	/* Assignment operators */
	BigInt& operator = (const BigInt& _rhs);
	BigInt& operator = (const std::vector <uint32>& _number);
	BigInt& operator = (uint64 _number);
	BigInt& operator = (const std::string& _number);

	/* Addition operators */
	friend BigInt operator + (BigInt _lhs, const BigInt& _rhs);
	friend BigInt operator + (BigInt _lhs, uint64 _number);

	friend BigInt& operator += (BigInt& _lhs, const BigInt& _rhs);
	friend BigInt& operator += (BigInt& _lhs, uint64 _number);

	/* Subtraction operators */
	friend BigInt operator - (BigInt _lhs, const BigInt& _rhs); // Not implemented
	friend BigInt operator - (BigInt _lhs, uint64 _number); // Not implemented

	friend BigInt& operator -= (BigInt& _lhs, const BigInt& _rhs); // Not implemented
	friend BigInt& operator -= (BigInt& _lhs, uint64 _number); // Not implemented

	/* Multiplication opertors */
	friend BigInt operator * (BigInt _lhs, const BigInt& _rhs;
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
	bool less(const BigInt& _other) const;
	friend bool operator < (BigInt _lhs, const BigInt& _rhs);
	friend bool operator > (BigInt _lhs, const BigInt& _rhs);
	friend bool operator <= (BigInt _lhs, const BigInt& _rhs);
	friend bool operator >= (BigInt _lhs, const BigInt& _rhs);
	friend bool operator == (BigInt _lhs, const BigInt& _rhs);
	friend bool operator != (BigInt _lhs, const BigInt& _rhs);

	/* Input-output streams */
	friend std::ostream& operator << (std::ostream& _output_stream, const BigInt& _number);
	friend std::istream& operator >> (std::istream& _input_stream, BigInt& _number); // Not implemented

	/* C-ctyle input-output */
	void scan() const;               // Uses scanf  // Not implemented
	void fscan(FILE* _input_file);   // Uses fscanf // Not implemented
	void sscan(char* _input_string); // Uses sscanf // Not implemented

	void print() const;                      // Uses printf // Not implemented
	void fprint(FILE* _output_file) const;   // Uses fprintf // Not implemented
	void sprint(char* _output_string) const; // Uses sprintf // Not implemented

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
	void __mul_this(const BigInt& _rhs);
	void __mod_this(uint64 _number);
	void __div_this(uint64 _number);
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

BigInt::BigInt(const BigInt& _rhs) : _digits(_rhs._digits) {
	__trim();
}

BigInt::BigInt(const std::vector <uint32>& _digits) { 
	__init_with_vector(_digits);
}

// object(_number)
BigInt::BigInt(uint64 _number) {
	__init_with_number(_number);   
}

BigInt::BigInt(const std::string& _number) {
	__init_with_string(_number);
}

/* Assignments */

// BigInt = BigInt
BigInt& BigInt::operator = (const BigInt& _rhs) {
	if (this != &_rhs) {
		_digits = _rhs._digits;
	}

	return *this;
}

// BigInt = BigInt
BigInt& BigInt::operator = (const BigInt& _rhs) {
	if (this != &_rhs) {
		__init_with_vector(_rhs._digits);
	}

	return *this;
}

// BigInt = vector
BigInt& BigInt::operator = (const std::vector <BigInt::uint32>& _number) {
	__init_with_vector(_number);
	__trim();
	return *this;
}

// BigInt = number
BigInt& BigInt::operator = (uint64 _number) {
	__init_with_number(_number);
	__trim();
	return *this;
}

BigInt& BigInt::operator = (const std::string& _number) {
	__init_with_string(_number);
	__trim();
	return *this;
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

BigInt operator + (BigInt _lhs, BigInt::uint64 _number) {
	_lhs.__sum_this(BigInt(_number));
	return _lhs;
}

BigInt& operator += (BigInt& _lhs, const BigInt& _rhs) {
	_lhs.__sum_this(_rhs);
	return _lhs;
}

BigInt& operator += (BigInt& _lhs, BigInt::uint64 _number) {
	_lhs.__sum_this(BigInt(_number));
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

BigInt operator * (BigInt::uint64 _number) const {
	if (_number < BigInt::BASE) {
		return __mul(*this, _number);
	}

	return __mul(*this, BigInt(_number));
}

// Multiplication of long number by short number
// Works with assumpltion that _number < BASE
BigInt BigInt::__mul(const BigInt& _lhs, uint64 _number) {
	BigInt::uint64 _carry = 0;
	BigInt _result_BigInt;
	std::vector <BigInt::uint32>& _result = _result_BigInt._digits;
	_result.clear();

	for (std::size_t i = 0; i < _lhs._digits.size(); i++) {
		_carry += _lhs._digits[i] * _number;
		_result.push_back(_carry % BigInt::BASE);
		_carry /= BigInt::BASE;
	}

	while (_carry > 0) {
		_result.push_back(_carry % BigInt::BASE);
		_carry /= BigInt::BASE;
	}

	_result_BigInt.__trim(); // If number was 0

	return _result_BigInt;
}


/* 
 * Uses O(n^2) algorithm for multiplication
 * Main idea: multiplication of i-th digit of first number  
 * and j-th digit of second number will be added to 
 * (i + j)-th digit of result.
 *
 * Proof: (a * (BASE ^ i)) is i-th digit of first number
 *        (b * (BASE ^ j)) is j-th digit of second number
 *        (a * (BASE ^ i)) * (b * (BASE ^ j)) = (a * b) * (BASE ^ (i + j
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

// Works with assumption that _number < BigInt::BASE
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
	
	__init_with_number(_number);
}

/*=================================================*
 *                                                 *
 *               Division operators                *
 *                                                 *
 *=================================================*/


void __div_this(BigInt::uint64 _number) {
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
bool BigInt::less(const BigInt& _other) const {
	const std::vector <BigInt::uint32>& _lhs = _digits;
	const std::vector <BigInt::uint32>& _rhs = _other._digits;

	if (_lhs.size() != _rhs.size()) {
		return _lhs.size() < _rhs.size();
	}

	int _length = (int)_lhs.size();
	for (int i = _length - 1; i >= 0; i--) {
		if (_lhs[i] != _rhs[i]) {
			return _lhs[i] < _rhs[i];
		}
	}

	return false;
}

bool BigInt::operator < (const BigInt& _rhs) const {
	return this->less(_rhs);
}

bool BigInt::operator > (const BigInt& _rhs) const {
	return _rhs.less(*this);
}

bool BigInt::operator <= (const BigInt& _rhs) const {
	return !(_rhs.less(*this));
}

bool BigInt::operator >= (const BigInt& _rhs) const {
	return !(this->less(_rhs));
}

bool BigInt::operator != (const BigInt& _rhs) const {
	return this->less(_rhs) || _rhs.less(*this);
}

bool BigInt::operator == (const BigInt& _rhs) const {
	return !(this->less(_rhs)) && !(_rhs.less(*this));
}

/*=================================================*
 *                                                 *
 *             IOStream input-output               *
 *                                                 *
 *=================================================*/
std::ostream& operator << (std::ostream& _output_stream, const BigInt& _number) {
	std::vector <BigInt::uint32>::const_reverse_iterator _digit;
	_digit = _number._digits.rbegin();

	_output_stream << *_digit;
	_digit++;

	for (; _digit != _number._digits.rend(); _digit++) {
		_output_stream << std::setw(BigInt::BASE_LENGTH) << std::setfill('0');
		_output_stream << *_digit;
	}

	return _output_stream;
}

/*=================================================*
 *                                                 *
 *             Other helper functions              *
 *                                                 *
 *=================================================*/

// Helper function
// Erases all leading zeroes
void BigInt::__trim() {
	while (!_digits.empty() && _digits.back() == 0)
		_digits.pop_back();

	if (_digits.empty()) {
		_digits.push_back(0u);
	}
}

#endif // _BIGINT_H_
