//-----Include required headers here-----
#include<string>
using namespace std;
//-----End of headers-----


//-----Add new functions here(if any)-----
//  helper function to xor two characters
char xor_cnew(char a, char b)
{
	if (a == b)     return '0';
	else            return '1';
}

//  helper function to flip the bit
char flip_new(char c)
{
	if (c == '0')   return '1';
	else            return '0';
}
//-----New functions end here-----

/* Question : Function to convert a given binary string to
gray code string as explained in the problem description. */
string binarytoGray(string binary) {
	// Write your code below this line.
	string res = "";
	res += binary[0];

	for (int i = 1; i < binary.length(); i++)
	{
		res += xor_cnew(binary[i - 1], binary[i]);
	}
	return res;
	//return "-1";
}

/* Question : Function to convert a gray code string to
binary string as explained in the problem description. */
string graytoBinary(string gray) {
	// Write your code below this line.
	string res = "";
	res += gray[0];

	for (int i = 1; i < gray.length(); i++)
	{
		if (gray[i] == '0')
			res += res[i - 1];
		else
			res += flip_new(res[i - 1]);
	}
	return res;
	//return "-1";
}