#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> priority_chart;

bool func(int a, int b)
{
    if(priority_chart[a].size() < priority_chart[b].size())
        return false;

    else if(priority_chart[a].size() > priority_chart[b].size())
        return true;

    for(int i = priority_chart[a].size()-1; i>=0; i--)
    {
        if(priority_chart[a][i]<priority_chart[b][i])
            return false;

        else if(priority_chart[a][i]>priority_chart[b][i])
            return true;

    }

    if(a<b)
        return true;

    else if(a>b)
        return false;

    return false;


}

int main()
{
    int n;
    cin >> n;
    string input;
    vector<vector<int>> int_save;
    stack<int> s;
    
    for(int i =0; i<n; i++) //save word in form integer
    {
        cin >> input;
        for(int j=0; j<input.size(); j++)
        {
            if(input[j]>='0' && input[j]<='9')
                s.push((int)input[j]-48);

            else
                s.push((int)input[j]-55);
        }

        vector<int> a;
        while(s.size()!=0)
        {
            a.push_back(s.top());
            s.pop();
        }

        int_save.push_back(a);
    }


    for(int i =0; i<36; i++) //get each letter's priority
    {
        vector<int> a;

        for(int j =0; j<n; j++)
        {
            for(int k=0; k<int_save[j].size(); k++)
            {
                if(int_save[j][k]==i)
                {
                    if(a.size()>=k+1)
                        a[k]+=35-i;
                    else
                        a.push_back(35-i);
                }

                else
                {
                    if(a.size()<k+1)
                        a.push_back(0);
                }
            }
        }

        int end=a.size()-1;

        while(end>0 && a[end]==0)//delete the simultaneous zeros
            end--;

        vector<int> real_a;

        for(int l=0; l<=end; l++)
            real_a.push_back(a[l]);

        int arrange = real_a.size()-1;//change each digit in 36 form

        for(int j=0; j<arrange; j++)
        {
            real_a[j+1]+=real_a[j]/36;
            real_a[j]%=36;
        }

        while(real_a[arrange]>=36)
        {
            real_a.push_back(real_a[arrange]/36);
            real_a[arrange]%=36;
            arrange++;
        }

        priority_chart.push_back(real_a);
        
    }

    vector<int> chart;
    for(int i=0; i<36; i++)
        chart.push_back(i);

    sort(chart.begin(), chart.end(), func);

    int num_of_change;
    cin >> num_of_change;

    vector<int> ans;

    for(int i =0; i<n; i++)//add up all letter
    {
        for(int j =0; j<int_save[i].size(); j++)
        {
            if(ans.size()>=j+1)
                ans[j]+=int_save[i][j];

            else
                ans.push_back(int_save[i][j]);
        }
    }

    for(int i =0; i<num_of_change; i++)
    {
        int temp = chart[i];
        vector<int> &t = priority_chart[temp];

        for(int j=0; j<t.size(); j++)
        {
            if(ans.size()>=j+1)
                ans[j]+=t[j];

            else
                ans.push_back(t[j]);
        }
    }

    int cur = ans.size()-1;
    
    for(int i =0; i<cur; i++)
    {
        ans[i+1]+=ans[i]/36;
        ans[i]%=36;
    }

    while(ans[cur]>=36)
    {
        ans.push_back(ans[cur]/36);
        ans[cur]%=36;
        cur++;
    }

    string answer;
    
    for(int i =ans.size()-1; i>=0; i--)
    {
        if(ans[i]>=0 && ans[i]<=9)
            answer+=(char)ans[i]+48;

        else
            answer+=(char)ans[i]+55;
    }

    cout << answer << endl;

    return 0;

}



