// // Check AB
// Problem statement
// Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

// a. The string begins with an 'a'
// b. Each 'a' is followed by nothing or an 'a' or "bb"
// c. Each "bb" is followed by nothing or an 'a'
// If all the rules are followed by the given string, return true otherwise return false.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// abb
// Sample Output 1 :
// true
// Sample Input 2 :
// abababa
// Sample Output 2 :
// false
// Explanation for Sample Input 2
// In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.

bool checkABHelper(char input[], int index){
	if(input[index] == NULL){
		return true;
	}

	if(input[index] == 'a'){
		// if next charactor is also a then start that recursion from next a
		if(input[index+1] != NULL && input[index+1] == 'a'){
			return checkABHelper(input, index+1);
		}
		// input two charactors are 'bb' then start the recursion after 'bb'
		else if(input[index+1] != NULL && input[index+2] != NULL && input[index+1] == 'b' && input[index+2] == 'b'){
			return checkABHelper(input, index+3);
		}
		else if(input[index+1] == NULL){
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

bool checkAB(char input[]) {
	int index = 0;
	return checkABHelper(input, index);
}



