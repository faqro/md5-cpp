#include <iostream>
#include <vector>
#include "md5.cpp"

using namespace std;
 
int main(int argc, char *argv[])
{
    int hashTotal=0;
    vector<string> listOfHash;
    string hashOutConcat="";

    cout<<"Number of hashes: ";
    cin>>hashTotal;
    listOfHash.resize(0);

    for(int i = 0; i < hashTotal; i++) {
        string tempRead;
        cout<<i<<": ";
        cin>>tempRead;
        listOfHash.push_back(tempRead);
    }

    for(int i=0; i<hashTotal; i++) {
        bool cracked=false;
        for(int i2=0; i2<=999 & !cracked; i2++) {
            string testValue = to_string(i2);

            while(testValue.length()<3) testValue="0"+testValue;

            if(md5(testValue)==listOfHash[i]) {
                hashOutConcat=hashOutConcat+testValue;
                cracked=true;
            }
        }
    }

    cout<<endl<<endl<<"Output: '"<<hashOutConcat<<"'";

    int ign;
    cin>>ign;
    return 0;
}