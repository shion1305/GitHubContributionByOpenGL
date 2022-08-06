#include "HttpClient.h"

int HttpClient::post(const std::string& inUrl, const json::value& inData, json::value& outData)
{
	try {
		this->_post(inUrl, inData).wait();
		outData = this->_m_cResultValue;
	} catch (const std::exception& e) {
		::printf("<!> %s. %s \n", inUrl.c_str(), e.what());
		if (this->_m_nStatusCode == 0) return 1;
		else return this->_m_nStatusCode;
	}

	if (this->_m_nStatusCode == 200) return 0;
	else if (this->_m_nStatusCode == 0) return 1;
	else return this->_m_nStatusCode;
}

int HttpClient::get(const std::string& inUrl, json::value& outData)
{
	try {
		this->_get(inUrl).wait();
		outData = this->_m_cResultValue;
	} catch (const std::exception& e) {
		::printf("<!> %s. %s \n", inUrl.c_str(), e.what());
		if (this->_m_nStatusCode == 0) return 1;
		else return this->_m_nStatusCode;
	}

	if (this->_m_nStatusCode == 200) return 0;
	else if (this->_m_nStatusCode == 0) return 1;
	else return this->_m_nStatusCode;
}

int HttpClient::put(const std::string& inUrl, const json::value& inData, json::value& outData)
{
	try {
		this->_put(inUrl, inData).wait();
		outData = this->_m_cResultValue;
	} catch (const std::exception& e) {
		::printf("<!> %s. %s \n", inUrl.c_str(), e.what());
		if (this->_m_nStatusCode == 0) return 1;
		else return this->_m_nStatusCode;
	}

	if (this->_m_nStatusCode == 200) return 0;
	else if (this->_m_nStatusCode == 0) return 1;
	else return this->_m_nStatusCode;

	return 0;
}

int HttpClient::del(const std::string& inUrl, json::value& outData)
{
	try {
		this->_del(inUrl).wait();
		outData = this->_m_cResultValue;
	} catch (const std::exception& e) {
		::printf("<!> %s. %s \n", inUrl.c_str(), e.what());
		if (this->_m_nStatusCode == 0) return 1;
		else return this->_m_nStatusCode;
	}

	if (this->_m_nStatusCode == 200) return 0;
	else if (this->_m_nStatusCode == 0) return 1;
	else return this->_m_nStatusCode;

	return 0;
}

pplx::task<int> HttpClient::_post(const std::string& inUrl, const json::value& inData)
{
	const std::string sUrl = inUrl;
	const json::value cValue = inData;

	// 実行タスク生成
	return pplx::create_task([sUrl, cValue]
	{
		utility::string_t sUtf16 = utility::conversions::utf8_to_utf16(sUrl);
		http_client cClient(sUtf16);
		http_request cRequest(methods::POST);
		cRequest.set_body(cValue.serialize(), L"application/json");
		return cClient.request(cRequest);
	}).then([this, sUrl](http_response cResponse)
	{
		if (cResponse.status_code() == status_codes::OK) {
			::printf("[POST] %s success. \n", sUrl.c_str());
		} else {
			::printf("<!> [POST] %s failed. status=%d \n", sUrl.c_str(), cResponse.status_code());
		}
		this->_m_nStatusCode = cResponse.status_code();
		return cResponse.extract_json(true);
	}).then([this](json::value cJson)
	{
		this->_m_cResultValue = cJson;
		return 0;
	});
}

pplx::task<int> HttpClient::_get(const std::string& inUrl)
{
	const std::string sUrl = inUrl;

	// 実行タスク生成
	return pplx::create_task([sUrl]
	{
		utility::string_t sUtf16 = utility::conversions::utf8_to_utf16(sUrl);
		sUtf16 = uri::encode_uri(sUtf16, uri::components::component::query);
		http_client cClient(sUtf16);
		http_request cRequest(methods::GET);
		return cClient.request(cRequest);
	}).then([this, sUrl](http_response cResponse)
	{
		if (cResponse.status_code() == status_codes::OK) {
			::printf("[GET] %s success. \n", sUrl.c_str());
			http_headers cHeader = cResponse.headers();
		} else {
			::printf("<!> [GET] %s failed. status=%d \n", sUrl.c_str(), cResponse.status_code());
		}
		this->_m_nStatusCode = cResponse.status_code();
		return cResponse.extract_json(true);
	}).then([this](json::value cJson)
	{
		this->_m_cResultValue = cJson;
		return 0;
	});
}

pplx::task<int> HttpClient::_put(const std::string& inUrl, const json::value& inData)
{
	const std::string sUrl = inUrl;
	const json::value cValue = inData;

	// 実行タスク生成
	return pplx::create_task([sUrl, cValue]
	{
		utility::string_t sUtf16 = utility::conversions::utf8_to_utf16(sUrl);
		http_client cClient(sUtf16);
		http_request cRequest(methods::POST);
		cRequest.set_body(cValue.serialize(), L"application/json");
		return cClient.request(cRequest);
	}).then([this, sUrl](http_response cResponse)
	{
		if (cResponse.status_code() == status_codes::OK) {
			::printf("[PUT] %s success. \n", sUrl.c_str());
		} else {
			::printf("<!> [PUT] %s failed. status=%d \n", sUrl.c_str(), cResponse.status_code());
		}
		this->_m_nStatusCode = cResponse.status_code();
		return cResponse.extract_json(true);
	}).then([this](json::value cJson)
	{
		this->_m_cResultValue = cJson;
		return 0;
	});
}

pplx::task<int> HttpClient::_del(const std::string& inUrl)
{
	const std::string sUrl = inUrl;

	// 実行タスク生成
	return pplx::create_task([sUrl]
	{
		utility::string_t sUtf16 = utility::conversions::utf8_to_utf16(sUrl);
		sUtf16 = uri::encode_uri(sUtf16, uri::components::component::query);
		http_client cClient(sUtf16);
		http_request cRequest(methods::GET);
		return cClient.request(cRequest);
	}).then([this, sUrl](http_response cResponse)
	{
		if (cResponse.status_code() == status_codes::OK) {
			::printf("[DELETE] %s success. \n", sUrl.c_str());
			http_headers cHeader = cResponse.headers();
		} else {
			::printf("<!> [DELETE] %s failed. status=%d \n", sUrl.c_str(), cResponse.status_code());
		}
		this->_m_nStatusCode = cResponse.status_code();
		return cResponse.extract_json(true);
	}).then([this](json::value cJson)
	{
		this->_m_cResultValue = cJson;
		return 0;
	});
}