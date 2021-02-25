#include <iostream>
#include <array>
#include <bit>
#include <filesystem>
#include <fstream>

#include "mylib.h"


namespace Mylib {

	//////////////////////////////////////////////////////////
	//	Array initialization
	//////////////////////////////////////////////////////////

	float* NewArray() {

		return new float[ARR_SIZE];
	}

	TArray* NewStdArray() {

		return new TArray;
	}

	//////////////////////////////////////////////////////////
	//	Array printing
	//////////////////////////////////////////////////////////

	void PrintArray(const float* arr, const size_t& size) {
		
		if (!arr) return;

		std::cout << "[ ";

		for (size_t i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "]\n";
	}

	void PrintArray(const TArray* arr) {

		if (!arr) return;

		std::cout << "[ ";
		for (auto i : arr->data)
			std::cout << i << " ";
		std::cout << "]\n";
	}

	void PrintArray(const int* arr) {

		if (!arr) return;

		std::cout << "[ ";

		for (size_t i = 0; i < ARR_SIZE; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "]\n";
	}

	//////////////////////////////////////////////////////////
	//	Array operations
	//////////////////////////////////////////////////////////

	void FillArray(float* arr, const size_t& size, const float& filler) {

		if (!arr) return;

		for (size_t i = 0; i < size; i++)
			arr[i] = filler;
	}

	void FillArray(TArray* arr, const float& filler) {
		
		if (!arr) return;

		for (auto i : arr->data)
			arr->data.fill(filler);
	}

	std::pair<int, int> CountElems(const TArray* arr) {

		if (!arr) return {};

		int nPositive(0), nNegative(0);
		for (auto i : arr->data)
			i < 0.0f ? ++nNegative : ++nPositive;

		return { nPositive, nNegative };
	}

	int CountElems(const float* arr, const size_t& size) {

		if (!arr) return -1;

		int nNegativeCount(0);

		for (size_t i = 0; i < size; i++)
			if (arr[i] < 0.0f) ++nNegativeCount;

		return nNegativeCount;
	}

	//	These methods are working up to 21% faster on my PC (release builds)
	int CountElemsBinary(const float* arr, const size_t& size) {

		if (!arr) return -1;

		int nNegativeCount(0);

		for (size_t i = 0; i < size; i++)
			nNegativeCount -= (std::bit_cast<int>(arr[i]) >> FLOAT_SIGN_POS);

		return nNegativeCount;
	}

	int CountElemsBinary(const TArray* arr) {

		if (!arr) return -1;

		int nNegativeCount(0);

		for (float i : arr->data)
			nNegativeCount -= (std::bit_cast<int>(i) >> FLOAT_SIGN_POS);

		return nNegativeCount;
	}

	// TODO FIXES!
	bool _sorted(int* arr) {

		bool bSorted(false);
		for (size_t curr = 0; curr < ARR_SIZE; curr++) {
			for (size_t next = 1; next < ARR_SIZE - 1; next++) {
				if (arr[curr] < arr[next]) bSorted = true;
			}
			bSorted = false;
		}

		return bSorted;
	}

	// TODO OPTIMIZATION!!!
	void SortArray(int* arr) {

		if (!arr) return;

		bool bChanged(false);
		do {
			for (size_t curr = 0; curr < ARR_SIZE; curr++) {
				for (size_t next = curr + 1; next < ARR_SIZE; next++) {
					if (arr[curr] > arr[next]) {
						SWAP_INT(arr[curr], arr[next]);
						bChanged = true;
					}
				}
				PrintArray(arr);
			}
			PrintArray(arr);
			bChanged = false;

		} while (bChanged);
	}

	//////////////////////////////////////////////////////////
	//	Struct functions
	//////////////////////////////////////////////////////////

	bool TEmployee::SaveToFile()
	{
		std::string sFilename("employee.txt");

		if (std::filesystem::exists(sFilename)) {
			std::filesystem::remove(sFilename);
			std::cout << sFilename << " was removed.\n";
		}

		std::string sContent("");
		sContent += "ID: " + std::to_string(this->ID);
		sContent += "\nFirst name: " + this->firstName;
		sContent += "\nLast name: " + this->lastName;
		sContent += "\nSalary: " + std::to_string(this->salary);
		sContent += "\n";

		std::ofstream fout(sFilename);
		std::cout << sFilename << " was successfully created.\n";
		fout << sContent;
		fout.close();

		return true;
	}
}
