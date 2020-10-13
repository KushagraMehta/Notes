```cpp
#include <iostream>
using namespace std;

template <class Type>
class Segment_Tree
{
private:
    int _min;
    Type _max;
    size_t size;
    size_t tree_size;
    Type *arr;
    Type *segment_arr;

    Type _mid(Type low, Type high) { return low + (high - low) / 2; }

    void compare(Type a, Type b)
    {
        if (_min == 1)
            return min(a, b);
        else if (_min - 1)
            return (a + b);
        else
            return max(a, b);
    }
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
    void build(size_t low, size_t high, size_t position)
    {
        if (high == low)
        {
            segment_arr[position] = arr[low];
            return segment_arr[position];
        }
        size_t mid = _mid(low, high);
        segment_arr[position] = compare(this->build(low, mid, 2 * position + 1), this->build(mid + 1, high, 2 * position + 2));
        return segment_arr[position];
    }
    Type _query(size_t position, size_t child_left, size_t child_right, size_t left, size_t right)
    {
        if (left > right)
            return (_min ? _max : 0);

        if (left == child_left && right == child_right)
            return segment_arr[position];

        size_t mid = _mid(child_left, child_right);
        return compare(_query(position * 2 + 1, child_left, mid, left, min(right, mid)),
                       _query(position * 2 + 2, mid + 1, tr, max(left, mid + 1), right));
    }

public:
    Segment_Tree(size_t size, int min = 1, Type max = 2147483647)
    {
        this->_min = min;
        this->_max = max;
        this->size = size;
        this->tree_size = _tree_size(size) * 2 - 1;
        this->arr = new Type[size];
        this->segment_arr = new Type[tree_size];
        memset(segment_arr, (min ? max : 0), tree_size);
    }
    void input()
    {
        for (size_t i = 0; i < size; i++)
            cin >> arr[i];
        this->build(0, size - 1, 0);
    }
    Type query(size_t left, size_t right) { return _query(0, 0, tree_size - 1, left, right); }

    void update(Type value, size_t low, size_t high = 0)
    {
        if (low != high && low > high)
            high = low;
        // work 2 do
    }
};

int main(int argc, char const *argv[])
{
    // '''' //
    return 0;
}
```
