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

//How to access the protected one - by inheriting from the user class

class User1 : public User {
    public:
    void displayStatus(){
        cout << "Is the user's behaviour good:  " << (isGood ? "Yes": "no") << endl;
    }
};

struct operation{


   
    int x = 4;// local variable
    //Function Overloading
    int sum( int x, int y){

        return x + y;
    
    }
    
    int sum( double x, double y){
        return x +y;
    }
    int sum( int x ,int y , int z){
        return x + y + z;
    }

    // Template
    template <typename A>
    A multiply(float a ,A b){
        A result;
        result = a * b;
        return result;
        
    }

    
};

int x = 5; //global variable


int main (){
    

    operation Add;
    int i= 1, j= 2, k=2, l=3;
    double f = 1.0;
    cout << Add.sum(i,j)<< endl;
    cout << Add.sum(i,j,k)<< endl;
    cout << Add.multiply(j,l)<< endl;
    cout << Add.multiply(f,l)<< endl;


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


