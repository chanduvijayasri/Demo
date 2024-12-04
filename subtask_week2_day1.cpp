#include<iostream>
#include<memory>
#include<vector>
#include<tuple>

using namespace std;

template<typename T1,typename T2>
class GenericContainers{
    public:
    T1 a;
    T2 b;
    vector<int> vec={1,7,8};
        GenericContainers(T1 a,T2 b):a(a),b(b){}
    void getadd()
    {
        cout<<a+b<<endl;
    }
    void getvalue()
    {
        for(auto it:vec)
        {
            cout<<it <<" ";
        }
    }
    void getsize()
    {
        cout<<vec.size();
    }
};
int main(){
    unique_ptr<GenericContainers<int,int>> obj=make_unique<GenericContainers<int,int>>(10,8);
    obj->getvalue();
    obj->getadd();
    obj->getsize();

}
