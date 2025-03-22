#include <iostream>
#include <string>
using namespace std;

//Namespace
namespace Number{
    int num = 2;
};


class User{
    
    private:
        int perdiem = 20000;
    public: 
        string name = "Abebe";
        //I tried to use getter and setter methods for accessing private member
        void setPerdiem(int num){
             perdiem = num;
            
        };
        int getPerdiem(){
            return perdiem;
        };
    protected:
        bool isGood = true;

};

//How to access the protected one - by inheriting from the parent class

class User1 : public User {
    public:
    void displayStatus(){
        cout << "Is the user's behaviour good:  " << (isGood ? "Yes": "no") << endl;
    }
};

struct operation{


   
    int x = 4;
    
    int sum( int x, int y){

        return x + y;
    
    }
    
    int sum( double x, double y){
        return x +y;
    }
    int sum( int x ,int y , int z){
        return x + y + z;
    }


    template <typename A>
    A multiply(float a ,A b){
        return a * b;
    }

    
};

int x = 5; //global variable


int main (){
    

    operation Add;
    cout << Add.sum(1,2,2)<< endl;
    cout << Add.multiply(2,3)<< endl;
    cout << Add.multiply(1.0f, 5)<< endl;


    //return the local variable
    cout << Add.x<< endl;
    cout << x<< endl;// return the global variable

    // Returning the namespace value

    cout << Number::num<< endl;


    // printing the class
    User user;
    cout << user.name << endl;
    user.setPerdiem(25000);
    cout << user.getPerdiem()<< endl;


    //accesing the protected one
    User1 user1;
    user1.displayStatus();

    

    return 0;
};


