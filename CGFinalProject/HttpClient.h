#pragma once

#include <stdio.h>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

// HTTP(S)クライアント
class HttpClient
{
public:

	// コンストラクタ
	HttpClient() { this->_m_nStatusCode = 0; }

	// POST
	int post(const std::string& inUrl, const json::value& inData, json::value& outData);

	// GET
	int get(const std::string& inUrl, json::value& outData);

	// PUT
	int put(const std::string& inUrl, const json::value& inData, json::value& outData);

	// DELETE
	int del(const std::string& inUrl, json::value& outData);

private:

	pplx::task<int> _post(const std::string& inUrl, const json::value& inData);

	pplx::task<int> _get(const std::string& inUrl);

	pplx::task<int> _put(const std::string& inUrl, const json::value& inData);

	pplx::task<int> _del(const std::string& inUrl);

private:

	json::value _m_cResultValue;
	int _m_nStatusCode;
};