///////////////////////////////////////////////////
//		C++ PreProcessing
//		Naughty Panda @ 2021
///////////////////////////////////////////////////

#include <iostream>
#include "mylib.h"

int main() {

	//////////////////////////////////////////////////////////
	//	7.1
	//////////////////////////////////////////////////////////

	auto fArr = Mylib::NewArray();
	auto StdArr = Mylib::NewStdArray();

	Mylib::FillArray(StdArr);
	Mylib::FillArray(fArr, ARR_SIZE);

	std::cout << "Empty STL Array:\n";
	Mylib::PrintArray(StdArr);
	std::cout << "\nEmpty C Array:\n";
	Mylib::PrintArray(fArr, ARR_SIZE);

	for (auto [i, f] = std::pair{0, -7.2f}; i < ARR_SIZE; i++, f += 1.1f) {
		i % 2 ? fArr[i] = f : fArr[i] = f * -1.0f;
		i % 2 ? StdArr->data[i] = f : StdArr->data[i] = f * -1.0f;
	}

	std::cout << "\nSTL Array:\n";
	Mylib::PrintArray(StdArr);
	std::cout << "\nC Array:\n";
	Mylib::PrintArray(fArr, ARR_SIZE);

	int nPosCount(0), nNegCount(0);
	std::cout << "\nBranch function results:\n";
	std::pair<int, int> PElemsCount = Mylib::CountElems(StdArr);
	std::cout << "STL Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;

	PElemsCount.second = Mylib::CountElems(fArr, ARR_SIZE);
	PElemsCount.first = ARR_SIZE - PElemsCount.second;
	std::cout << "C Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;

	std::cout << "\nBinary function results:\n";
	PElemsCount.second = Mylib::CountElemsBinary(StdArr);
	PElemsCount.first = ARR_SIZE - PElemsCount.second;
	std::cout << "STL Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;

	PElemsCount.second = Mylib::CountElemsBinary(fArr, ARR_SIZE);
	PElemsCount.first = ARR_SIZE - PElemsCount.second;
	std::cout << "C Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;

	//////////////////////////////////////////////////////////
	//	7.2
	//////////////////////////////////////////////////////////

	std::pair<int, int> PInput{ 0, 0 };
	std::cout << "\nPlease enter first integer: ";
	std::cin >> PInput.first;
	std::cout << "Please enter second integer: ";
	std::cin >> PInput.second;

	std::cout << "Testing if ";
	if (PInput.second >= 0)
		std::cout << "0 => " << PInput.first << " < " << PInput.second << ": " << BOOL_TO_STR(TEST_INPUT(PInput.first, PInput.second));
	else
		std::cout << PInput.second << " > " << PInput.first << " <= 0: " << BOOL_TO_STR(TEST_INPUT(PInput.first, PInput.second));

	//////////////////////////////////////////////////////////
	//	7.3
	//////////////////////////////////////////////////////////

	int userArr[ARR_SIZE]{ 1,-3,5,8,-7,3,3,2,-2,4 };
	// TODO user input
	std::cout << "\n\nSorting array:\n";
	Mylib::SortArray(userArr);
	std::cout << "Array sorted!\n";

	//////////////////////////////////////////////////////////
	//	7.4
	//////////////////////////////////////////////////////////

	Mylib::TEmployee* empl = new Mylib::TEmployee;
	empl->ID = 1;
	empl->salary = 12345.6f;
	std::cout << "\nSaving employee data to file:\n";
	empl->SaveToFile();
	std::cout << "Size of employee struct = " << empl->GetSize() << " bytes" << std::endl;

	delete[] fArr;
	delete StdArr;
	delete empl;

	return 0;
}
