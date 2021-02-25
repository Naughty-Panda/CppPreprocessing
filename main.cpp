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

	std::cout << "Empty STD Array:\n";
	Mylib::PrintArray(StdArr);
	std::cout << "\nEmpty C Array:\n";
	Mylib::PrintArray(fArr, ARR_SIZE);

	float f = -7.2;
	for (size_t i = 0; i < ARR_SIZE; i++, f += 1.1f) {
		i % 2 ? fArr[i] = f : fArr[i] = f * -1.0f;
		i % 2 ? StdArr->data[i] = f : StdArr->data[i] = f * -1.0f;
	}

	std::cout << "\nSTD Array:\n";
	Mylib::PrintArray(StdArr);
	std::cout << "\nC Array:\n";
	Mylib::PrintArray(fArr, ARR_SIZE);

	int nPosCount(0), nNegCount(0);
	std::cout << "\nBranch function results:\n";
	std::pair<int, int> PElemsCount = Mylib::CountElems(StdArr);
	std::cout << "STD Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;

	PElemsCount.second = Mylib::CountElems(fArr, ARR_SIZE);
	PElemsCount.first = ARR_SIZE - PElemsCount.second;
	std::cout << "C Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;

	std::cout << "\nBinary function results:\n";
	PElemsCount.second = Mylib::CountElemsBinary(StdArr);
	PElemsCount.first = ARR_SIZE - PElemsCount.second;
	std::cout << "STD Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;


	PElemsCount.second = Mylib::CountElemsBinary(fArr, ARR_SIZE);
	PElemsCount.first = ARR_SIZE - PElemsCount.second;
	std::cout << "C Array:\tpositive elements: " << PElemsCount.first << "; negative elements: " << PElemsCount.second << std::endl;

	//////////////////////////////////////////////////////////
	//	7.4
	//////////////////////////////////////////////////////////

	Mylib::TEmployee* empl = new Mylib::TEmployee;
	empl->ID = 1;
	empl->salary = 12345.6f;
	std::cout << "\nSaving employee data to file:\n";
	empl->SaveToFile();
	std::cout << "Size of employee struct = " << empl->GetSize() << std::endl;

	delete[] fArr;
	delete StdArr;
	delete empl;

	return 0;
}
