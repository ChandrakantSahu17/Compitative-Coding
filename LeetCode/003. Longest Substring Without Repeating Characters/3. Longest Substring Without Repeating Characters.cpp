

#include<bits/stdc++.h>
using namespace std;
 
#define RUN 1000000
 
int main()
{
    
    freopen("input.txt","w",stdout);
 
    // For random values every time
    srand(time(NULL));

    long i = 0;
    while( i++ < RUN ){
        int  r = (rand() % 9) + 1;
        printf("%c", '0' + r);
    }
    
    fclose(stdout);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    fclose(stdin);
    fclose(stdout);

    return(0);
}