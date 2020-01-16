#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d,e,f;
    for(a=1;a<=6;a++)
    {
        for(b=1;b<=6;b++)
        {
            for(c=1;c<=6;c++)
            {
                for(d=1;d<=6;d++)
                {
                    for(e=1;e<=6;e++)
                    {
                        for(f=1;f<=6;f++)
                        {
                            if( a!=b && a!=c && a!=d && a!=e && a!=f
                                     && b!=c && b!=d && b!=e && b!=f
                                             && c!=d && c!=e && c!=f
                                                     && d!=e && d!=f
                                                             && e!=f)
                            {
                                if(a+b+c==a+d+e && c+e+f==a+b+c)
                                {


                                    printf("%d+%d+%d  ",a,b,c);
                                    printf("%d+%d+%d  ",a,d,e);
                                    printf("%d+%d+%d  \n",c,e,f);


                                }
                            }
                        }
                    }
                }
            }
        }
    }


    system("pause");
    return 0;
}