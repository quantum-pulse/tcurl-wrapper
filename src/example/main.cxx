
#include "curl_mgr.hxx"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <memory>

using namespace std;

void dump(const string & file_name,string & buffer){
    ofstream l_file(file_name.c_str());
    l_file<<buffer;
    l_file.close();
}

int main(int argc,char ** argv)
{
    if(argc==1){
        cout<<"missing argument"<<endl;
        exit(EXIT_FAILURE);
    }
    string l_url{argv[1]};
    string l_file_name="url.extract";
    unique_ptr<curl_mgr> l_mgr=nullptr;
    try{
        l_mgr=make_unique<curl_mgr>(l_url);    
        l_mgr->extract();
    }
    catch(runtime_error & er){
        cout<<er.what()<<endl;
    }    
        
    dump(l_file_name,(*l_mgr)()); 
        
    return 0;
}
