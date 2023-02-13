#include<iostream>
using namespace std;

class Rect{
    int length,breadth;

    public:
    Rect(){
        length = 0;
        breadth = 0;
    }
    Rect(int l, int b){
        length = l;
        breadth = b;
    }

    Rect operator+(Rect rec){
        Rect R;
        R.length = length + rec.length;
        R.breadth = breadth + rec.breadth;
        return R;
    }

    void display(Rect rec){
        cout << "length: " << rec.length << endl;
        cout << "breadth: " << rec.breadth << endl;
    }

};

int main(){
    Rect r;
    Rect rec1(10,20);
    Rect rec2(10,20);
    Rect rec3=rec1+rec2;

    r.display(rec3);
}