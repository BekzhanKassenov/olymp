#ifndef _FILE_H_
#define _FiLE_H_

#include <vector>
#include <string>
#include <fstream>

class File {
public:
	void read(const string& filename) {
		ifstream _input(filename.c_str());

		string temp;
		while (getline(_input, temp)) {
			lines.push_back(temp);
		}

		size_t row = 0, col = 0;
		char cc;

		while ((cc = get_next_nonspace(row, col) != EOF) {
			nospace.append(1, cc);
		}
	}

	bool equals_without_spaces(const File& file) {
		return nospace == file.nospace;
	}

	char get_next_nonspace(size_t& row, size_t& col) {
		if (invalid_pos(row, col)) {
			return EOF;
		}		

		while (isspace(lines[row][col])) {
			col++;

			if (invalid_pos(row, col)) {
				row++;
				col = 0;

				if (invalid_pos(row, col)) {
					return EOF;
				}
			}
		}

		return lines[row][col];
	}

	char get_next_char(size_t& row, size_t& col) {
		if (invalid_pos(row, col)) {
			return EOF;
		}		

		char result = lines[row][col];

		col++;
		if (invalid_pos(row, col)) {
			col = 0;
			row++;
		}
		
		return result;
	}

private:
	bool invalid_pos(size_t row, size_t col) {
		return lines.empty() || row >= lines.size() || col >= lines[row].size();
	}

private:
	vector <string> lines;
	string nospace;
};

#endif _FILE_H_