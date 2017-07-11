/*
Given an array of strings, find all anagram pairs in the given array.
Input: arr[] =  {"geeksquiz", "geeksforgeeks", "abcd",
                 "forgeeksgeeks", "zuiqkeegs"};
Output: (geeksforgeeks, forgeeksgeeks), (geeksquiz, zuiqkeegs)
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// utility function for printing
// anagram list
void printAnagram(unordered_map<string,vector<string> > &store){
    unordered_map<string,vector<string> > :: iterator it;
    for(it = store.begin(); it != store.end(); it++){
        vector<string> temp_vec(it->second);
        int size = temp_vec.size();
        if(size > 1){
            for(int i=0 ;i<size; i++){
                cout << temp_vec[i]<<" ";
            }
            cout << "\n";
        }
    }
}

// utility function for storing the vector of strings
// into HashMap
void storeInMap(vector<string> &vec){
    unordered_map<string,vector<string> > store;
    for(int i=0; i<vec.size(); i++){
        string tempString(vec[i]);
        sort(tempString.begin(),tempString.end());

        //check for sorted string if it already exists
        if(store.find(tempString) == store.end()){
            vector <string> temp_vec;
            temp_vec.push_back(vec[i]);
            store.insert(make_pair(tempString,temp_vec));
        }else{
            //push new string to already existing key
            vector<string> temp_vec(store[tempString]);
            temp_vec.push_back(vec[i]);
            store[tempString] = temp_vec;
        }
    }
    // print utility function for printing
    // all the anagrams
    printAnagram(store);
}

int main(){
    // initialize vector of strings
    vector <string> arr;
    arr.push_back("geeksquiz");
    arr.push_back("geeksforgeeks");
    arr.push_back("abcd");
    arr.push_back("forgeeksgeeks");
    arr.push_back("zuiqkeegs");
    arr.push_back("cat");
    arr.push_back("act");
    arr.push_back("tca");

    // utility function for storing strings into hashmap
    storeInMap(arr);
    return 0;
}
