#include <iostream>
#include <curl/curl.h>

// Hàm ghi dữ liệu tải về
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* outString) {
    size_t totalSize = size * nmemb;
    outString->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string htmlContent;

    // Khởi tạo CURL
    curl = curl_easy_init();
    if(curl) {
        // URL của trang web
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.facebook.com/");

        // Gán hàm ghi dữ liệu
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlContent);

        // Thực hiện tải trang
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            std::cout << "Tải thành công!" << std::endl;
            std::cout << htmlContent << std::endl; // In nội dung HTML
        } else {
            std::cerr << "Lỗi: " << curl_easy_strerror(res) << std::endl;
        }

        // Dọn dẹp
        curl_easy_cleanup(curl);
    }

    return 0;
}
