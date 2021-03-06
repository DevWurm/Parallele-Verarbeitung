/*
	 * License

	 * Copyright 2015 DevWurm

	 * This file is part of merge_sort_lists.

	 *  merge_sort_lists is free software: you can redistribute it and/or modify
	    it under the terms of the GNU General Public License as published by
	    the Free Software Foundation, either version 3 of the License, or
	    (at your option) any later version.

	    merge_sort_lists is distributed in the hope that it will be useful,
	    but WITHOUT ANY WARRANTY; without even the implied warranty of
	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	    GNU General Public License for more details.

	    You should have received a copy of the GNU General Public License
	    along with merge_sort_lists.  If not, see <http://www.gnu.org/licenses/>.

	    Diese Datei ist Teil von merge_sort_lists.

	    merge_sort_lists ist Freie Software: Sie können es unter den Bedingungen
	    der GNU General Public License, wie von der Free Software Foundation,
	    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
	    veröffentlichten Version, weiterverbreiten und/oder modifizieren.

	    merge_sort_lists wird in der Hoffnung, dass es nützlich sein wird, aber
	    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
	    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
	    Siehe die GNU General Public License für weitere Details.

	    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
	    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

#include <random>
#include <deque>
#include "../headers/random_list.h"

using std::deque;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

template<typename T>
deque<T> generate_random_list (long long int length, T start, T end) { //create a deque of the length length filed with
	deque<T> return_list;											  //random number sin the range from start to end
	random_device seed;
	mt19937 engine (seed());
	uniform_real_distribution<double> values (start, end);
	for (long long int i = 0; i <= length-1; i++) {
		return_list.push_back(values(engine));
	}
	return return_list;
}
