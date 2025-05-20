// 내가 푼 버전

#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
// set으로 푸는 거 


int solution(vector<int> nums)
{
    int nums_size = nums.size();

    int pocket_size = (nums_size / 2);

    sort(nums.begin(), nums.end());

    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            count += 1;
        }
    }

    if (pocket_size < count) {
        return pocket_size;
    }
    else {
        return count;
    }
}


// set 사용하기

#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> unique_pocketmons(nums.begin(), nums.end());

    int pocket_size = nums.size() / 2;

    int unique_size = unique_pocketmons.size();

    return min(pocket_size, unique_size);

}