#include <iostream>
#include <string>

//ASCII value needs to stay between 33 to 126 to be valid charcaters

//Found on internet 33 + rand() % 92--I'll chose 94 - Border set of ASCII with hashing 
int main(){
    
    std::cout<<"Please enter your Text, no spaces:\n";   
    std::string input {};
    std::cin >> input;
    int input_size=input.length();

    std::cout<<"Please enter your Key, no spaces:\n";
    std::string key{};
    std::cin >> key;
    int key_size=key.size();

    std::cout << "1. Encrypt\n2. Decrypt\nType your choice\n";
    int choice{0};
    std::cin >> choice;
    
    std::string::iterator it;
    std::string::iterator it2;
    it2=key.begin();
    
    switch (choice){
        case 1:
        {            
            std::cout<<std::endl;

            for (it = input.begin() ; it != input.end() ; ++it){
                *it= 33 + (*it + *it2)%94;

                std::cout << *it;

                ++it2;
                if(it2==key.end()) {it2=key.begin();}
            }
            
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
        break;

        case 2:
        {
            std::cout<<std::endl;

            for (it = input.begin() ; it != input.end() ; ++it){
                *it=*it - 33 + 94 - *it2;//for ascii sums that travel once
                
                if (*it<33 && *it>=(-61)) {*it = *it+94;}   //for ascii sums that travels twice
                
                if (*it>126 || *it<(-61)) {*it=*it-94;}  //for ascii sums that travel none times
                
                std::cout << *it;
                
                ++it2;
                if(it2==key.end()) {it2=key.begin();}
            }

            std::cout<<std::endl;
            std::cout<<std::endl;
        }
        break;

        default:
        std::cout << "Dumbass, enter either 1 or 2\n";
    }
    
    std::cout << "Done\n";

    return 0;
}
