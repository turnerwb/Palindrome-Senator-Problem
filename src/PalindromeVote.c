/*
 * PalindromeVote.c
 * Allows you to specify the number of "Senators" and
 * prints the ways that a body of that size could vote
 * in a palindrome along with the number of absences
 * or abstentions that could cause that vote.
 *  Created on: Jan 26, 2018
 *      Author: turnerwb
 */
#include <stdio.h>
#include <string.h>

int PalindromeChecker();
int GetPalindrome();
int FirstReturn = 1;

int main(){
	printf("test");
	int Number_Senators;
	printf( "Enter Number of Senators \n" );
	fflush(stdout);
	scanf("%d", &Number_Senators);
	printf("%d", PalindromeChecker(Number_Senators, 0, 0, 0));
	//Extra arguments are for commented out function
}

/*The commented out version of PalindromeChecker will only return one of the
 * ways the body could vote that is a palindrome with the fewest number of
 * absences
 */
//int PalindromeChecker(int Number_Senators, int i, int max, int maxi){
//	if(i <= Number_Senators / 2){
////		printf("%d", Number_Senators - i);
//		int Palindrome = GetPalindrome(Number_Senators - i);
////		printf("%d", Palindrome);
////		printf("\n");
//		int sum = Number_Senators - i + Palindrome;
//		if(sum <= Number_Senators && sum >= max){
//			max = sum;
//			maxi = i;
//			}
//		max = PalindromeChecker(Number_Senators, i + 1, max, maxi);
//	}
//	if(FirstReturn == 1){
//		printf("%d", Number_Senators - maxi);
//		printf(" - %d", max - Number_Senators + maxi);
//		printf("\n");
//		FirstReturn = 0;
//	}
//	return max;
//}
//
int GetPalindrome(int Value){
	int Palindrome = 0;
	while(Value > 0){
		Palindrome = Palindrome * 10;
		Palindrome = Palindrome + Value % 10;
		Value = Value / 10;
	}
	return Palindrome;
}

int PalindromeChecker(int Number_Senators, int i, int max, int maxi){
	if(i <= Number_Senators / 2){
		int Palindrome = GetPalindrome(Number_Senators - i);
		int sum = Number_Senators - i + Palindrome;
		if(sum <= Number_Senators){
			printf("%d", Number_Senators - i);
			printf(" - %d", Palindrome);
			printf("\n");
			printf("%d", Number_Senators- sum);
			printf("\n");
			}
		max = PalindromeChecker(Number_Senators, i + 1, max, maxi);
	}
	return 0;
}
