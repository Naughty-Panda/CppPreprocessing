#pragma once

#include <array>
#include <string>

#define TEST_INPUT(a, b) (((b) >= 0) ? ((a) >= 0 && (a) < (b) ? true : false) : ((a) <= 0 && (a) > (b) ? true : false))
#define BOOL_TO_STR(a) ((a) ? "true" : "false")

#define ARR_SIZE 10
#define FLOAT_SIGN_POS 31

namespace Mylib {

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
