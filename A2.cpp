#include<iostream>
using namespace std;
class validDate{
    private:
        int day, month, year;
    public:
        void getData(){
            cout<<"Enter date in format dd/mm/yyyy: ";
            cin>>day>>month>>year;
        }
        bool isValid(){
            if((year%4==0) && (year%100!=0) || (year%400==0)){
                if(month==2){
                    if(day>=1 && day<=29){
                        return true;
                    }
                }
            }
            else{
                if(month==2){
                    if(day>=1 && day<=28){
                        return true;
                    }
                }
            }
            if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
                if(day>=1 && day<=31){
                    return true;
                }
            }
            if(month==4 || month==6 || month==9 || month==11){
                if(day>=1 && day<=30){
                    return true;
                }
            }
            return false;
        }
};
int main(){
    validDate d;
    d.getData();
    if(d.isValid()){
        cout<<"Date is valid."<<endl;
    }
    else{
        cout<<"Date is invalid."<<endl;
    }
    return 0;
}
