#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char a[100][100];
int c[100][100];
int ip, jp, is, js;
int n;
int doo[25];
int di[] = { -1, 0, 1, 0 }, dj[] = { 0, 1, 0, -1 };
char sep[]={'.'};
char cuv[100];
void Read()
{

        ifstream fin("date.in");
        int n;
        scanf("%d", &n);
        scanf("%*c");  // citeste newline si ignora-l


        fgets(cuv,100, stdin);

        // probabil ai newline la finalul lui cuvant
        if (cuv[strlen(cuv) - 1]== '\n')
        cuv[strlen(cuv) - 1] = '\0';

        fin.close();
}

bool OK(int i,int j)
{
        if (a[i][j] != 0 && a[i][j]!=101)
            return false; // verify if exists an obstacle
        if (i < 0 || j < 0 || i >= n || j >= n )
                return false; // outside the matrix
        return true;  // everything is ok
}

void Lee()
{
    c[ip][jp] = 0; // starting point is 0
    bool modif;
    int pas = 0; // the cost is 0
    do
    {
        modif = false;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(c[i][j]==pas) //verifyng the cost of the pred and star searching for the neighb
            for(int d=0;d<4;++d)
            {
// computing the cost from c[ip][jp] until the wanted c[is][js].
                int iv=i+di[d];
                int jv=j+dj[d];
                if(OK(iv,jv) && c[iv][jv] > pas+1)
                {
                        c[iv][jv]=pas+1;
                        modif=true;
                        if( iv==is && jv==js ) // the condition to stop the searching
                                return;
                }
            }
            pas++;
    } while(modif);
}

void Write()
{

    for(int i=0;i<n;i++)
    {
        cout<<cuv[i]<<" ";
    }
    //the cost matrix is displayed
    //adding in the stack
}

int main()
{
        Read();
        Lee();
        Write();

        return 0;
}
