

#include <deque>
#include "deque_functions.h"

using std::deque;

namespace par_merge_sort {

template<typename T>
deque<T> merge_sort_merge(deque<T>& list1, deque<T>& list2) { //list2 will always be the smaller list
	//if list2 is empty use list1 as return list
	if (list1.size() > 0 && list2.size()==0) {
		return list1;
	}
	else {
		deque<T> listret;

		//cycle trough lists and compare the first elements, move the smaller element into result list
		while (list1.size() > 0 && list2.size() >0) {
			if (list1.at(0)<list2.at(0)) {
				restack(list1, listret, 1);
			}
			else {
				restack(list2, listret, 1);
			}
		}
		// if on list is empty, move all remaining elements into result list
		if (list1.size()>0) {
			restack(list1, listret, list1.size());
		}
		else if (list2.size()>0) {
			restack(list2, listret, list2.size());
		}
		return listret;
	}

}

template<typename T>
void merge_sort(deque<T>& input, int basic_width = 1) {
	int input_size = input.size();

	//repeat the merging algorithm until input is sorted completely
	for (int list_width = basic_width; list_width < input_size; list_width *= 2) {
		deque<T> buffer;
		restack(input, buffer, input.size());

		//cycle through  the list and take list pairs with the size list_width
		while (buffer.size() > 0) {
			deque<T> list1;
			deque<T> list2;

			if (buffer.size() >= list_width) {
				restack(buffer, list1, list_width); //move list_width elements into list1
			}
			else {
				//if less then list_width elements are remaining, move all remaining elements into list1
				restack(buffer, list1, buffer.size());
			}
			if (buffer.size() >= list_width) {
				restack(buffer, list2, list_width); //move list_width elements into list2
			}
			else {
				//if less then list_width elements are remaining, move all remaining elements into list2
				restack(buffer, list2, buffer.size());
			}
			deque<T> return_buffer = merge_sort_merge(list1, list2); //merge the lists (list2 will always
																	 //be the smaller list)
			restack(return_buffer, input, return_buffer.size()); //move the result into result list
		}

	}
}

}
