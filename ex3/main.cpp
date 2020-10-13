/* i didn t get 100% what i m supposed to do exactly so i`ve decided to use in implementation a stack in which i ll have the input data(coordinate),
a vector of points in which i`ll store the coordinates and use quicksort to make it easier to eliminate the closest rooms with respect to entrace (0,0)
*/

//Update: this quick sorts after x coord so if i have as wanted room CJ105 the input will be (5,1)
#include <iostream>
#define NMAX 5
#include "queue.h"
using namespace std;
//ofstream f("out.c");
template <typename T>
class Point{
    private:
        T coordX, coordY;

    public:

        Point(){}
        Point(T x, T y)
        {
            this->coordX=x;
            this->coordY=y;
        }
        ~Point(){}

        void reset(){
            coordX = coordY = 0;
        }

        void moveX(T x){
            if(coordX + x > NMAX){
                coordX = 0;
                return;
            }
            coordX += x;
        }

        void moveY(T y){
            if(coordY + y > NMAX){
                coordY = 0;
                return;
            }
            coordY += y;
        }

        void moveXY(T x, T y){
            if(coordX + x > NMAX || coordY + y > NMAX){
                reset();
                return;
            }
            moveX(x);
            moveY(y);
        }

        void print(){
            cout << coordX << " ";
            cout << coordY << endl;
        }
        void standardization()
        {
            if(coordX<10)
                cout<<"AN"<<coordY<<"0"<<coordX<<endl;
            else
                cout<<"AN"<<coordY<<coordX<<endl;
        }
        //getters
        int getX()
        {
            return coordX;
        }
        int getY()
        {
            return coordY;
        }

        //setters
        void setX(T x)
        {
            this->coordX=x;
        }
        void setY(T y)
        {
            this->coordY=y;
        }
        bool operator<=(Point x)
        {
            if(this->coordX<=x.coordX)// && this->coordY<=x.coordY)
            return true;
            else
                return false;
        }
         bool operator>(Point x)
        {
            if(this->coordX>x.coordX )// && this->coordY>x.coordY)
            return true;
            else
                return false;
        }

};
template <typename T>
void intersch(T &a, T &b)
{
    T aux=a;
    a=b;
    b=aux;
}
template <typename T, typename U>
 void quick(U v[],T st, T d)
 {
     U pivot;
     T i,j;

     if(st>=d)
        return ;


     pivot=v[st];
     i=st+1;
     j=d;

      while(i<=j)
      {
          while(i<=j&&v[i]<=pivot)
            i++;
            while(i<=j&&v[j]>pivot)
                j--;
            if(i<=j)
            {
                intersch(v[i],v[j]);
                i++;
                j--;
            }
      }
      i--;
      intersch(v[i],v[st]);
      quick(v,st,i-1);
      quick(v,i+1,d);




 }

int main()
{
  Stack<int> s;
  Point <int> p[5];
  s.push(0);
  s.push(0);
  //entrance inserted
  int n;
  cout<<"read the number of rooms: ";
  cin>>n;
  int x;
  cout<<"read x*2 coord: "<<endl;
  for(int i=1;i<=n*2;i++)
  {
      cin>>x;
      s.push(x);

  }
  /*
  int i=0;
        while(!s.isEmpty())
        {   i++;
            if(i%2==1)
            {
                cout<<"("<<s.peek()<<",";
            }
            else
            {
                 cout<<s.peek()<<") ";
            }
            s.pop();
        }
    */
  cout<<endl;
  cout<<"setting the coordinates for the points: ";
  cout<<endl;
  int ii=1;
  while(!s.isEmpty())
  {
      p[ii].setX(s.peek());
      s.pop();
      p[ii].setY(s.peek());
      s.pop();
    ii++;
  }
cout<<endl;
   for(int i=1;i<=n+1;i++)
  {
      p[i].print();

  }
  cout<<endl;

    quick(p,1,n+1);

    cout<<"as conclusion: the following numbers will be in order (how are supposed to be eliminated): "<<endl;
     for(int i=1;i<=n+1;i++)
  {
      p[i].print();

  }

  cout<<endl;
  cout<<"the next function is like an action to decode from codding language to real life elements(from what`s displayed above to the meaning of it: "<<endl;
    for(int i=1;i<=n+1;i++)
  {
      p[i].standardization();

  }


    return 0;
}
