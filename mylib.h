#pragma once

#include <array>
#include <string>

//////////////////////////////////////////////////////////
//	Macro
//////////////////////////////////////////////////////////

#define TEST_INPUT(a, b) (((b) >= 0) ? ((a) >= 0 && (a) < (b) ? true : false) : ((a) <= 0 && (a) > (b) ? true : false))
#define BOOL_TO_STR(a) ((a) ? "true" : "false")
#define SWAP_INT(a, b) (a) = (a)^(b); (b) = (b)^(a); (a) = (a)^(b)
#define PRINT_ARRAY() std::cout << "[ "; for (size_t i = 0; i < ARR_SIZE; i++) {std::cout << arr[i] << " ";} std::cout << "]\n"

#define ARR_SIZE 10
#define FLOAT_SIGN_POS 31


namespace Mylib {

	//////////////////////////////////////////////////////////
	//	Structs
	//////////////////////////////////////////////////////////

	struct TArray {

		std::array<float, ARR_SIZE> data;
	};

#pragma pack(push, 1)
	struct TEmployee {

		std::string firstName = "temporary";
		std::string lastName = "placeholder";
		int ID = 0;
		float salary = 0.0f;

		int GetSize() { return sizeof(*this); }
		bool SaveToFile();
	};
#pragma pack(pop)

	//////////////////////////////////////////////////////////
	//	Array initialization
	//////////////////////////////////////////////////////////

	float* NewArray();

	TArray* NewStdArray();

	//////////////////////////////////////////////////////////
	//	Array printing
	//////////////////////////////////////////////////////////

	void PrintArray(const float*, const size_t&);
	void PrintArray(const TArray*);
	void PrintArray(const int*);

	//////////////////////////////////////////////////////////
	//	Array operations
	//////////////////////////////////////////////////////////

	void FillArray(float*, const size_t&, const float& filler = 0.0f);
	void FillArray(TArray*, const float& filler = 0.0f);

	std::pair<int, int> CountElems(const TArray*);
	int CountElems(const float*, const size_t&);

	int CountElemsBinary(const float*, const size_t&);
	int CountElemsBinary(const TArray*);

	bool _sorted(int*);
	void SortArray(int*);

	void GetInput(int*);
}
