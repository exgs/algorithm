#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> set_temp;
	for (size_t i = 0; i < nums.size(); i++)
	{
		set_temp.insert(nums[i]);
	}
	if (set_temp.size() > nums.size() / 2)
		answer = nums.size() / 2;
	else
		answer = set_temp.size();
    return answer;
}
