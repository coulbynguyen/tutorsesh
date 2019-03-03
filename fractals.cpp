#include <iostream>

using namespace std;


//this was hard to do, because the problem statement wasn't very clear
//therefore the answer was on cplusplus reference page
//I took what they had and made it my own

int pattern(int n, int i){

   	//this statement stops the recursion as there should be no more asterisks printed if the n = 0
	if(n == 0){
		return 0;
	}
	else{

		//this creates the fractal for the top half
		pattern(n/2, i);

		//this creates the fractal for the current line of code
		//this is determined by the number of spaces that have been passed to it
		//then the number of asterisks required for that line
		for(int k = 0; k < i; k++){
			cout << "  ";
		}
		for(int k = 0; k < n; k++){
			cout << "* ";
		}
		cout << endl;

		//this creates the bottom half of the fractal
		pattern(n/2, i + n/2);
	}
	return 0;
}

int main(){
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	int result = pattern(n, 0);
	return 0;
}
