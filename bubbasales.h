#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


//This value holds the sales people, Can be changed easily and used all throughout the program.
//IF more users are added this value can be changed here to the number of employees and the program
//will still function correctly
int salespeople = 12;

//function prototypes
void welcome();
void loadData(vector<vector<string>> &content);
void reportInfo();
void reportOne(vector<vector<string>> content);
void reportTwo(vector<vector<string>> content);