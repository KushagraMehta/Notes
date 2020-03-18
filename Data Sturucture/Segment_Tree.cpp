#include <iostream>
#include <cmath>
using namespace std;

template <class Type>
class Segment_Tree
{
private:
    bool min;
    size_t size;
    size_t tree_size;
    Type *segment;
    Type *lazy;

    size_t _tree_size(size_t value)
    {
        bool not_2_power = false;
        size_t targetlevel = 0;
        do
        {
            if (value % 2 && value != 1)
                not_2_power = true;
            ++targetlevel;
        } while (value >>= 1);
        return targetlevel - (not_2_power ? 0 : 1);
    }
    void _build()
    {
        for (size_t i = size - 1; i > 0; --i)
            segment[i] = segment[i << 1] + segment[i << 1 | 1];
    }

public:
    Segment_Tree(size_t size)
    {
        this->size = size;
        this->tree_size = _tree_size(size) * 2 - 1;
        this->segment = new Type[tree_size];
        this->lazy = new Type[tree_size];
    }
    void input()
    {
        for (int i = 0; i < size; ++i)
            cin >> segment[size + i];
        this->_build();
    }
    void answer(size_t low, size_t high);
    void modify(long long value, size_t index)
    {
        for (segment[index += n] = value; index > 1; index >>= 1)
            segment[index >> 1] = segment[index] + segment[index ^ 1];
    }
    void update(long long value, size_t low, size_t high)
    {
    }
};

int construct_tree(int *tree_arr, int low, int high, int position)
{
    if (high == low)
    {
        cin >> tree_arr[position];
        return tree_arr[position];
    }
    int mid = (low + high) / 2;
    tree_arr[position] = min(construct_tree(tree_arr, low, mid, 2 * position + 1), construct_tree(tree_arr, mid + 1, high, 2 * position + 2));
    return tree_arr[position];
}

int main(int argc, char const *argv[])
{
    int size, tree_size;
    printf("Enter the size of array: ");
    scanf("%intd", &size);

    tree_size = ceil(log2(size)) * 2 - 1;
    int segment_arr[tree_size] = {INT64_MAX};

    segment_arr[0] = construct_tree(segment_arr, 0, size, 0);
    return 0;
}
