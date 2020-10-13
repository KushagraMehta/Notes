```cpp
#include <iostream>
using namespace std;

template <class Type>
class Sparse_tree
{
private:
	int min;
	size_t k;
	size_t size;
	Type *arr;
	Type **recomputation;

	size_t int_log(size_t value)
	{
		size_t targetlevel = 0;
		while (value >>= 1)
			++targetlevel;
		return targetlevel;
	}
	Type compare(Type a, Type b)
	{
		return (this->min ? std::min(a, b) : std::max(a, b));
	}

	void preprocess()
	{
		for (size_t i = 0; i < size; i++)
			recomputation[i][0] = arr[i];

		for (size_t j = 1; j <= k; j++)
			for (size_t i = 0; i + (1 << j) <= size; i++)
			{
				if (min == -1)
					recomputation[i][j] = recomputation[i][j - 1] + recomputation[i + (1 << (j - 1))][j - 1];
				else
					recomputation[i][j] = compare(recomputation[i][j - 1], recomputation[i + (1 << (j - 1))][j - 1]);
			}
	}

public:
	Sparse_tree(size_t size, int min = 1)
	{
		this->size = size;
		this->arr = new Type[size];
		this->min = min;
		recomputation = new Type *[size];

		for (size_t i = 0; i < size; i++)
			recomputation[i] = new Type[int_log(size) + 1];
		this->k = int_log(size);
	}
	void input()
	{
		for (size_t i = 0; i < size; i++)
			std::cin >> arr[i];
		this->preprocess();
	}
	Type answer(size_t low, size_t high)
	{
		size_t length = high - low + 1;
		size_t j = int_log(length);

		if (min == -1)
		{
			Type sum = 0;
			for (long long i = k; i >= 0; i--)
				if ((1 << i) <= (high - low + 1))
				{
					sum += recomputation[low][i];
					low += 1 << i;
				}
			return sum;
		}
		else
			return compare(recomputation[low][j], recomputation[low + (length - (1 << j))][j]);
	}
};

int main()
{
	// Enter The Code
	return 0;
}
```cpp