/*
	 * License
	 
	 * Copyright 2015 DevWurm
	
	 * This file is part of error_library.

	 *  error_library is free software: you can redistribute it and/or modify
	    it under the terms of the GNU General Public License as published by
	    the Free Software Foundation, either version 3 of the License, or
	    (at your option) any later version.
	
	    error_library is distributed in the hope that it will be useful,
	    but WITHOUT ANY WARRANTY; without even the implied warranty of
	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	    GNU General Public License for more details.
	
	    You should have received a copy of the GNU General Public License
	    along with error_library.  If not, see <http://www.gnu.org/licenses/>.
	
	    Diese Datei ist Teil von error_library.
	
	    error_library ist Freie Software: Sie können es unter den Bedingungen
	    der GNU General Public License, wie von der Free Software Foundation,
	    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
	    veröffentlichten Version, weiterverbreiten und/oder modifizieren.
	
	    error_library wird in der Hoffnung, dass es nützlich sein wird, aber
	    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
	    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
	    Siehe die GNU General Public License für weitere Details.
	
	    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
	    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

#include "../Headers/error.h"
#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

namespace err {

error::error(int c, string d):code(c), description(d), line(0), file("") {};

error::error(int c, string d, int l):code(c), description(d), line(l), file("") {};

error::error(int c, string d, int l, string f):code(c), description(d), line(l), file(f) {};

int error::get_code() const {
	return code;
};

string error::get_description() const {
	return description;
};

int error::get_line() const {
	return line;
};

string error::get_file() const {
	return file;
};

string error::get_message() const {
	stringstream text;
	text << "Error (";
	text << code;
	text << "): ";
	text << description;
	if (line != 0) {
		text << " at line " << line;
	}
	if (file != "") {
		text << " in " << file;
	}
	text << '\n';
	return text.str();
}

void error::output_error() const {
	stringstream text;
	text << "Error (";
	text << code;
	text << "): ";
	text << description;
	if (line != 0) {
		text << " at line " << line;
	}
	if (file != "") {
		text << " in " << file;
	}
	text << '\n';
	cout << text.str();
}

void error::output_error(ostream& output) {
	stringstream text;
	text << "Error (";
	text << code;
	text << "): ";
	text << description;
	if (line != 0) {
		text << " at line " << line;
	}
	if (file != "") {
		text << " in " << file;
	}
	text << '\n';
	output << text.str();
}

ostream& operator<< (ostream& output, error& err_obj) {
	stringstream text;
	text << "Error (";
	text << err_obj.code;
	text << "): ";
	text << err_obj.description;
	if (err_obj.line != 0) {
		text << " at line " << err_obj.line;
	}
	if (err_obj.file != "") {
		text << " in " << err_obj.file;
	}
	text << '\n';
	output << text.str();
	return output;
}

}

