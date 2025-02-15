#include <string>

//Encryption
std::string encrypt(std::string input, std::string key){
    std::string::iterator it{input.begin()};   
    std::string::iterator it2{key.begin()};
    std::string result{};

    for (it ; it != input.end() ; ++it){
        if(*it!=' '){
        *it= 33 + (*it + *it2)%94;
        }
        result+=*it;
        ++it2;
        if(it2==key.end()) {it2=key.begin();}
    }
    return result;
}

//Decryption
std::string decrypt(std::string input, std::string key){
    std::string::iterator it{input.begin()};   
    std::string::iterator it2{key.begin()};
    std::string result{};

    for (it = input.begin() ; it != input.end() ; ++it){
        if(*it!=' '){
        *it=*it - 33 + 94 - *it2;                                 //for ascii sums that travels once
        if (*it<33 && *it>=(-61)) {*it = *it+94;}                 //for ascii sums that travels twice
        if (*it>126 || *it<(-61)) {*it=*it-94;}                   //for ascii sums that travels 0 times
        }
        result+=*it;
        ++it2;
        if(it2==key.end()) {it2=key.begin();}
    }
    return result;
}
//ASCII value needs to stay between 33 to 126 to be valid charcaters
//Found on internet 33 + rand() % 92--I'll chose 94 - Border set of ASCII with hashing 