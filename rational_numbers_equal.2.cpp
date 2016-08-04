//-----Include required headers here-----

//-----End of headers-----

//-----Don't change/delete structs-----
struct rational {
	int numerator;
	int denominator;
};
//-----Structs end here


/*Question: Reduce the number 'inputrational' to its lowest form and store it in 'outputrational'
struct rational *inputrational  : Actual rational number to be reduced
struct rational *outputrational : Variable to store the rational number in its lowest form */
void reduce(struct rational *inputrational, struct rational *outputrational) {
	//Write your solution code below this line
	for (int i = inputrational->denominator;i>0;i--)
	{
		if ((inputrational->numerator%i == 0) && (inputrational->denominator%i == 0))
		{
			outputrational->numerator = inputrational->numerator / i;
			outputrational->denominator = inputrational->denominator / i;
			break;
		}
	}

}

/* Question: Check whether both the rational numbers obtained in the lowest form are equal or not.
Retrun true or false accordingly
*/
bool isEqual(struct rational num1, struct rational num2) {
	//Write your solution code below this line
	struct rational out1, out2;
	//out1 = (struct rational )malloc(sizeof(struct rational));
	reduce(&num1, &out1);
	//out2 = (struct rational )malloc(sizeof(struct rational));
	reduce(&num2, &out2);
	if ((out1.numerator == out2.numerator) && (out1.denominator == out2.denominator))
		return true;
	else
		return false;

}