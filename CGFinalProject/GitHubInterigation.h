#pragma once
#include <vector>
#include <string>
using namespace std;
typedef struct {
	int firstYMD,contributions[7];
} WeekContribution;
vector<WeekContribution> getContribution(string name,string apiKey);