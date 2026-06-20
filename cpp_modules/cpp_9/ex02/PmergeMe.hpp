#pragma once

#include <iostream>
#include <list>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class PmergeMe{
	public:
		PmergeMe(char **av);


	private:
		void mergeSort(int left, int right);
		void merge(int left, int mid, int right);
		std::list<int> arr;
		std::stack<int> sort;

		void sortList(std::list<int>& list);
		std::list<std::string> split(std::string s, const std::string& c);
		bool isPositiveNumber(const std::string& str) const;

};		
