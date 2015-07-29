#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;
                    
const char          _full_stop = '.';
const char      _question_mark = '?';
const char   _exclamation_mark = '!';

bool _is_letter (char _test_char) {
	if (_test_char >= 'a' && _test_char <= 'z')
		return true;

	if (_test_char >= 'A' && _test_char <= 'Z')
		return true;

	return false;
}

bool _is_capital(char _test_char) {
	if (_test_char <= 'Z' && _test_char >= 'A')
		return true;

	return false;
}

bool _is_end_of_sentence(char _test_char) {
	return (_test_char == _full_stop || _test_char == _question_mark || _test_char == _exclamation_mark);
}

bool _is_mistake(char _test_char, bool _need_new_word, bool _need_new_sentence) {
	if (!_is_letter(_test_char))
		return false;

	if (_is_capital(_test_char)) {
		if (!_need_new_word && !_need_new_sentence)
			return true;

		return false;
	}

	if (_need_new_sentence)
		return true;

	return false;
}

int main() {	
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string _test_string;

	unsigned int _count_of_mistakes = 0;

	bool _need_new_word     = true;
	bool _need_new_sentence = true;

	while (getline(cin, _test_string)) {
		size_t _test_string_length = _test_string.length();
    	
    	_need_new_word     = true;

		for (size_t position = 0; position < _test_string_length; position++) {
			if (_is_mistake(_test_string[position], _need_new_word, _need_new_sentence)) {
				_count_of_mistakes++;
				//cerr << position << ' ' ;
			}

			if (!_is_letter(_test_string[position])) {
				_need_new_word = true;
				_need_new_sentence = (_is_end_of_sentence(_test_string[position])) ? true : _need_new_sentence;
			} else {
				_need_new_sentence = false;
				_need_new_word = false;
			}
	   	}
	}

	cout << _count_of_mistakes << endl;

	return EXIT_SUCCESS;
}
