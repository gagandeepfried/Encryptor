#include <fstream>
#include <iostream>

using namespace std;

struct Data{
    int index{0};
    string data;
    Data* next;
};
Data *head{NULL};
//Insert function to load data from file to Data structure 
void insert(int index, string text){ 
    Data *temp=new Data();
    temp->index=index;
    temp->data=text;
    temp->next=NULL;
    if(head==NULL){head=temp; head->next=NULL;}
    else{
        Data *temp2 = head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}
//Inserting new data after encrypting to DS from program
void insertNew(int index, string text, string key){
    Data *temp=new Data();
    temp->index=index;
    temp->data=encrypt(text,key);
    temp->next=NULL;
    if(head==NULL){head=temp; head->next=NULL;}
    else{
        Data *temp2 = head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}
//Load data from encrypted file and call insert function
void loadData(){
    fstream fin;
    int count{0};
    string text{};
    system("copy dataNew.txt dataOld.txt");
    fin.open("dataNew.txt", ios::in);
    while(getline(fin, text)){
        count++;
        insert(count,text);
    }
    fin.close();
}
//print data from DS after decrypting
void printData(string key){
    Data *temp=head;
    while(temp!=NULL){
        cout<<temp->index<<". "<<decrypt(temp->data , key)<<std::endl;
        temp=temp->next;
    }
}
//save data from DS to the file, data already encrypted
void saveData(){
    Data *temp = head;
    fstream fout;
    fout.open("dataNew.txt",ios::out);
    while(temp!=NULL){
        fout<<temp->data<<endl;
        temp=temp->next;
    }
    fout.close();
}
//update data in file
void update(int index, string text,string key){
    Data *temp=head;
    while(temp->index!=index){
        temp=temp->next;
    }
    if(temp!=NULL){
        temp->data=encrypt(text,key);
    }
}

void remove(int pos){
    Data *temp=head;
    if(temp->index==pos){
        head=temp->next;
        delete temp;
    }else{
    Data *prev=temp;
    while(temp->next->index!=pos && temp->next!=NULL){
        temp=temp->next;
    }
    temp=temp->next;
    prev->next=temp->next;
    delete temp;
    }
}