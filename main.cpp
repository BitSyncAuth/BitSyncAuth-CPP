#include <iostream>
#include <Windows.h>
#include <string>
#include <unordered_map>
#include <cstring>
#pragma comment(lib, "User32.lib")
#include "includes/BitSync.h"
#include "includes/skCrypter.h"

/*This project contains code licensed to bitsync.cc, Please purchase a valid subscription before implementing this code

discord: https://discord.gg/DDrRr6jhG6 */

std::string license_invalid = skCrypt("Invalid license!").decrypt(); //change error messages if callbacks enabled!
std::string hwid_invalid = skCrypt("Invalid hwid!").decrypt();
std::string subscription_expired = skCrypt("Subscription expired!").decrypt();


int main() {

    if (BitSync::init_ctx()) {

        std::cout << skCrypt("\n   Enter key -> ").decrypt();

        std::string key;
        std::cin >> key;

        auto resp = BitSync::license_ctx(key.c_str());

        BitSync::values ctx = BitSync::UNKNOWN;
        std::unordered_map<std::string, BitSync::values> Login = {
            {BitSync::get_response_invalid(), BitSync::INVALID},
            {BitSync::get_response_expired(), BitSync::EXPIRED},
            {BitSync::get_response_hwid(), BitSync::HWID},
            {BitSync::get_response_success(), BitSync::SUCCESS}
        };

        auto msg = Login.find(resp);
        if (msg != Login.end())
        {
            ctx = msg->second;
        }

        switch (ctx) { //error and login handling

        case BitSync::INVALID:
            BitSync::callback(license_invalid);
            break;
        case BitSync::EXPIRED:
            BitSync::callback(subscription_expired);
            break;
        case BitSync::HWID:
            BitSync::callback(hwid_invalid);
            break;
        case BitSync::SUCCESS:
            // do something smart
            break;
        default:
            break;
        }
    }
}