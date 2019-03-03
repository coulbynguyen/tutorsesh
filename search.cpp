#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>


//Make sure to create functions that help split the code so that it is less than 15-20 lines per section
//for this code i'd recommend creating a function that grabs the data and stores it
//then a seperate funciton that does the searching

using namespace std;

int main(){


   	//im pretty sure that you are able to do this
	//but just in case you should rewrite it as char* my_string = new char[INT_MAX] 
	//this way it could hold a lot more characters
	char* my_string = new char[10000];
	int index = 0;
	
	//this vector needs to be a dynamically allocated array
	//best way you could do this should be == string* search_words = new string[INT_MAX];
	//and instead of using push back use an integer idx that keeps track of where to store the new search word
	vector<string> search_words;	

	//you might have to get rid of this frequency vector as well if you aren't allowed to use vectors
	vector<int> frequency;
	int count = 0;
	
	cout << "enter string" << endl;
	cin.getline(my_string, 10000);
	
	while(my_string[index]){
	   	char c;
		c = my_string[index];
		my_string[index] = tolower(c);
		index++;
	}
	cout << "enter words to search" << endl;
	do{
		string new_search_word;
		if(cin >> new_search_word){
			for(int z = 0; z < new_search_word.length(); z++){
				char c;
				c = new_search_word[z];
				new_search_word[z] = tolower(c);

			}

			//the new code for using dynamic arrays would by search_words[idx] = new_search_word;
			//idx++;
		   	search_words.push_back(new_search_word);
			
		}
	}while(cin && cin.peek() != '\n');

	

	//For understanding what i did here, is that for each search word, i used strstr -- this is the c-string search mechanic -- which returns a character address of the word if it is found
	//therefore if the word exists it won't be NULL, therefore the while loop will continue untill there are no matches.
	//But that only works if search index is also moved
	//For example if you kept searching the string BURGER BURGER BOYS BURGER for the key word BURGER you would have an infintite looop as it would always return the idx of the first burger
	//But in this code it keeps searching for J+1 index string therefore after the first BURGER BURGER BURGER BOYS BURGER it would search URGER BURGER BOYS BURGER then it would retun the address of the full burger
	for(int i = 0; i < search_words.size(); i++){
	   	count = 0;
		char* j = strstr(my_string, search_words[i].c_str());
		while(j != NULL){
		   	count++;
	     		j = strstr(j+1, search_words[i].c_str());		
		}
		//this would need to be changed in order to account for vectors
		frequency.push_back(count);
	}
	for(int i = 0; i < search_words.size(); i++){
		cout << "WORD:" << search_words[i] << " FREQ:" << frequency[i] << endl;
	}		   
	delete [] my_string;
	//since you are allocating new memory you need to delete it so this will work: delete [] search_words
	return 0;
}
