#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template <class T>
T max_num(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <class T>
T abs_num(T a)
{
    return (a < 0) ? -a : a;
}

template <class item>
item array_max(item data[], int n)
{
    int i;
    item answer;
    assert(n > 0);
    answer = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] > answer)
        {
            answer = data[i];
        }
    }
    return answer;
}

int main()
{
    string s1, s2, ans;
    int n;
    int answer = 0;
    cout << "Enter a string:" << endl;
    getline(cin, s1);
    cout << "Enter another string:" << endl;
    getline(cin, s2);
    ans = max_num(s1, s2);
    cout << ans << " is the greater string" << endl;
    cout << "Enter a number:" << endl;
    cin >> n;
    answer = abs_num(n);
    cout << answer << endl;
    int maxval;
    int arr[] = {1, 3, 5, 4, 7, 9, 7};
    maxval = array_max(arr, 7);
    cout << "Max value:" << maxval << endl;

    return 0;
}
