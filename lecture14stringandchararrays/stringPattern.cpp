#includeS

string PatternChaser(string str) {
	string pattern, pattern2, result;
	int count,high, index,index2;
	index = high = 0;

	// Loop to analyze any patterns within the string
	do
	{
		for (int x = index; x < str.length(); x++)
		{
			pattern.push_back(str[x]); // begin analyzing the string to find a pattern to compare

			// Once we have a pattern ex. ab
			// Analyze the other values of the string to check if the pattern repeats
			if (pattern.length() > 1) 
			{
				index2 = x + 1;
				do
				{
					for (int y = index2; y < str.length(); y++)
					{
						pattern2.push_back(str[y]);

						if (pattern2 == pattern && pattern.length() > high)
						{
							high = pattern.length();
							result = pattern;
						}
						else if (pattern2.length() == pattern.length())
						{
							// reset back to analyze the other patterns and see if they match to the original
							pattern2.clear(); 
						}
					}
					pattern2.clear();
					index2++;
				} while (index2 < str.length());
			}
		}
		pattern.clear();
		index++;
	} while (index < str.length());
	
	if (high)
	{
		return "yes " + result;
	}
	else
	{
		return "no null";
	}
}

int main() {
	// keep this function call here
	cout << PatternChaser("da2kr32a2") << endl; // yes a2
	cout << PatternChaser("sskfssbbb9bbb") << endl; // yes bbb
	cout << PatternChaser("aabecaa") << endl; //  yes aa
	cout << PatternChaser("abbbaac") << endl; // no null
	cout << PatternChaser("aabejiabkfabed") << endl; // yes abe
	cout << PatternChaser("123224") << endl; // no null
	cout << PatternChaser("aa2bbbaacbbb") << endl; // yes bbb
	return 0;
}