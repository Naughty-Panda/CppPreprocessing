#pragma once

#include <array>

#define ARR_SIZE 10
#define FLOAT_SIGN_POS 31

namespace Mylib {

	struct TArray {

		std::array<float, ARR_SIZE> data;
	};

#pragma pack(push, 1)
	struct TEmployee {

		char firstName[10];
		char lastName[10];
		int ID;
		float salary;

		int GetSize() { return sizeof(*this); }
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

	//////////////////////////////////////////////////////////
	//	Array operations
	//////////////////////////////////////////////////////////

	void FillArray(float*, const size_t&, const float& filler = 0.0f);
	void FillArray(TArray*, const float& filler = 0.0f);

	std::pair<int, int> CountElems(const TArray*);
	int CountElems(const float*, const size_t&);

	int CountElemsBinary(const float*, const size_t&);
	int CountElemsBinary(const TArray*);

}
