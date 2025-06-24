#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr_max[3] = {0,0,0};
    int arr_least[3] = {0,0,0};

    int num, n1, n2, n3, ans1, ans2, ans3;
    scanf("%d", &num);
    for(int i =0; i<num; i++)
    {
        scanf("%d %d %d", &n1, &n2, &n3);
        ans1 = *max_element(arr_max, arr_max+2);
        ans2 = *max_element(arr_max, arr_max+3);
        ans3 = *max_element(arr_max+1, arr_max+3);

        arr_max[0] = ans1+n1;
        arr_max[1] = ans2+n2;
        arr_max[2] = ans3+n3;

        ans1 = *min_element(arr_least, arr_least+2);
        ans2 = *min_element(arr_least, arr_least+3);
        ans3 = *min_element(arr_least+1, arr_least+3);

        arr_least[0] = ans1+n1;
        arr_least[1] = ans2+n2;
        arr_least[2] = ans3+n3;

        //printf("%d %d %d\n", arr_max[0], arr_max[1], arr_max[2]);

    }
    ans1 = 0;
    ans2 = 1000000;
    
    for(int i =0; i<3; i++)
    {
        if(ans1<arr_max[i])
            ans1 = arr_max[i];
        if(ans2>arr_least[i])
            ans2=arr_least[i];
    }

    printf("%d %d\n", ans1, ans2);

    return 0;
}