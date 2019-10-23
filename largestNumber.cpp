class Solution {
public:
string largestNumber(vector<int>& nums)
{
	auto f_sort = [](const string &a, const string &b)
	{
		string r_a = a + b;
		string r_b = b + a;
		int i = 0;
		do
		{
			if (r_a[i] == r_b[i]) continue;
			return (r_a[i] - '0' < r_b[i] - '0');
		} while (++i < r_a.size());
		return (r_a[0] - '0' < r_b[0] - '0');
	};

	vector<string> str;
	for (auto &n : nums)
	{
		str.push_back(to_string(n));
	}
	sort(str.rbegin(), str.rend(), f_sort);

	string ans;
	bool bZeroFlag = true;
	for (auto &s : str)
	{
		if (bZeroFlag)
		{
			if (s == "0") continue;
			bZeroFlag = false;
		}
		ans.append(s);
	}
	return ans.empty() ? "0" : ans;
}
};
