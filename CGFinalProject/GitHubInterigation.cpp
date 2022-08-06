#pragma once
#include "GitHubInterigation.h"
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <vector>
#include <regex>

using namespace std;
using namespace utility;                    
using namespace web;                        
using namespace web::http;                  
using namespace web::http::client;          
using namespace concurrency::streams;


std::vector<WeekContribution> jsonToData(std::string data) {
    regex regex_firstDay("\"firstDay\":\"(\\d+)-(\\d+)-(\\d+)\"");
    regex regex_dayCount("\"contributionCount\":(\\d+)");
    vector<WeekContribution> out;
    smatch m, m1;
    auto index = data.cbegin();
    while (regex_search(index, data.cend(), m, regex_firstDay)) {
        WeekContribution wc;
        int year = stoi(m[1]);
        int month = stoi(m[2]);
        int day = stoi(m[3]);
        wc.firstYMD = 10000 * year + 100 * month + day;
        int count = 0;
        while (count++ < 7 && regex_search(index, data.cend(), m1, regex_dayCount)) {
            index = m1[0].second;
            wc.contributions[count - 1] = stoi(m1[1]);
        }
        out.push_back(wc);
    }

    //print all the data
    //for (auto& wc : out) {
    //    printf("data");
    //    cout << wc.firstYMD << " ";
    //    for (auto& c : wc.contributions) {
    //        cout << c << " ";
    //    }
    //    cout << endl;
    //}
    return out;
}



std::vector<WeekContribution> getContribution(string name,string apiKey) {
    http_client client(L"https://api.github.com/graphql");
    http_request request(methods::POST);
    request.headers().add(L"Content-Type", L"application/json");
    string apiHeader = "bearer ";
    apiHeader.append(apiKey);
    request.headers().add(L"Authorization", apiHeader.c_str());
    string query = "{ \"query\": \"query{user(login:\\\"";
    query.append(name);
    query.append("\\\"){login name url contributionsCollection {contributionCalendar{weeks{firstDay contributionDays{contributionCount}}}}}}\"}");
    
    request.set_body(query);
    wstring response = client.request(request).get().extract_string().get().c_str();
    string result = string(response.begin(), response.end());
    cout << result << endl;
    if (result.find("NOT_FOUND")!=-1) throw invalid_argument(result);
    return jsonToData(result);
}
