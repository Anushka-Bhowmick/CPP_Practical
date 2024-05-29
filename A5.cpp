#include<iostream>
using namespace std;
class HEIGHT{
    private:
        int feet;
        int inches;
    public:
        HEIGHT(int f=0, int i=0){
            feet = f;
            inches = i;
        }
        double into_cm(){
            return (feet*30.48) + (inches*2.54);
        }
        HEIGHT operator-(const HEIGHT &h){
            int f = feet - h.feet;
            int i = inches - h.inches;
            if(i < 0){
                f--;
                i += 12;
            }
            return HEIGHT(f, i);
        }
        bool operator>(const HEIGHT &h){
            if(feet > h.feet){
                return true;
            }
            else if(feet == h.feet && inches > h.inches){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator<(const HEIGHT &h){
            if(feet < h.feet){
                return true;
            }
            else if(feet == h.feet && inches < h.inches){
                return true;
            }
            else{
                return false;
            }
        }
        void display(){
            cout<<"Feet: "<<feet<<" Inches: "<<inches<<endl;
        }
};
int main(){
    int f1, f2, i1, i2;
    cout<<"Enter the height of the first person in feet and inches: ";
    cin>>f1>>i1;
    cout<<"Enter the height of the second person in feet and inches: ";
    cin>>f2>>i2;
    HEIGHT h1(f1, i1), h2(f2, i2), h3;
    h3 = h1 - h2;
    cout<<"The difference of the two heights is: "<<    h3.into_cm();
    cout<<" cm"<<endl;
    h3.display();
    if(h1 > h2){
        cout<<"The first person is taller than the second person"<<endl;
    }
    else if(h1 < h2){
        cout<<"The first person is shorter than the second person"<<endl;
    }
    else{
        cout<<"Both the persons are of the same height"<<endl;
    }
    cout<<"The height of the first person in cm is: "<<h1.into_cm()<<endl;
    cout<<"The height of the second person in cm is: "<<h2.into_cm()<<endl;
    return 0;

}