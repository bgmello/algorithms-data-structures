#include <iostream>

using namespace std;

struct point{
int x,y;
point (int x,int y){this->x=x,this->y=y;}
point operator+(point a){   //soma
return point(x+a.x,y+a.y);
}
point operator-(point a){  //subtracao
return point(x-a.x,y-a.y);
}
int operator*(point a){  //produto escalar
return x*a.x+y*a.y;
}
point operator*(int a){ //multiplicacao por escalar
return point(a*x,a*y);
}
double operator!(){  //norma
return sqrt(x*x+y*y);
}
int operator%(point a){ // modulo do produto escalar
return x*a.y-y*a.x;
}
};

int main()
{
    point a=point(1,2),b=point(2,3);
    cout << (a+b).x << " " << (a+b).y << endl;
    cout << (a-b).x << " " << (a-b).y << endl;
    cout << a*b << endl;
    cout << (a*2).x << " " << (a*2).y << endl;
    cout << !a << endl;
    cout << a%b << endl;
    return 0;
}
