
#include<bits/stdc++.h>
using namespace std;
int  bal=0,run1 =0,

wicket =0,wi=0,ov=0,extras=0;
int  total_run=0,Total_Run=0,
ie=0,IE=0,w1=0,W2=0;

class cricket1
{
public:
    vector<int > bowl;
    cricket1(int  t)
    {
        bowl.push_back(t);
    }
    int  d, s = 0;
    cricket1(int  w, int  d1)
    {
        wi = w, d = d1;
    }
    vector<string> Name;
    cricket1(string t)
    {
        Name.push_back(t);
    }
    cricket1(int  p1, int  run2, int  wicket1,int ex)
    {
        bal= p1;
        run1 = run2;
        wicket = wicket1;
        extras=ex;
    }
    void display()
    {
        for (auto r : bowl)
        {
            bal++;
             cout<<ov<<" over "<<bal<<"bowl  :";
                if (r==-1)
                {

                cout<<"\n\n Wicket! Wicket! Wicket!!\n"<<endl;
                wicket++;

                }
                else if(r==6){

                cout<<" \nSIX! SIX! SIX!"<<endl;
                run1+=r;
                  }
                else if(r==4)
                {
                    cout<<"\nFOUR!!"<<endl;
                     run1+=r;
                }
                else if(r>=7 && r<=11){
                    run1+=r;
                    if(r==11){
                        cout<<"\nWIDE Four!!"<<endl;
                      run1+=(r-6);
                      extras+=(r-6);
                      bal--;
                    }
                    else cout<<" WIDE\n "<<r-6;
                }
                else if(r<0 &&r>=-7){
                        run1+=abs(r);
                        extras+=abs(r);
                    cout<<"NO Bowl \n";
                    if(abs(r)==7) cout<<" SIX!..............\n";
                     else if(abs(r)==5)cout<<"FOUR!..................\n";
                     bal--;
                }
                else if(r>0 && r<4){
                        cout<<r<<"runs"<<endl;
                        run1+=r;
                }
                else {
                        cout<<0<<endl;
                run1+=0;}

                if(bal==6){
                    ov++;
                    bal=0;

                    cout << "\nEnd of Over"<<endl<<"Run:" << run1 <<endl,
                    cout<< " Extras:"<<extras<<endl<<" Wicket:" << wicket <<endl,
                    cout<< " Over:" << ov<<"."<<bal<<endl<<endl ;
                }
            }
        }
};
class team
{
public:

    char teamname[20];
    void setteamname()
    {
        cin>>teamname;
    }
    void getteamname()
    {
        cout<<teamname;
    }
};
int main()
{
    team t1,t2;
    cout<<"Enter Team Names:";
    t1.setteamname();
    t2.setteamname();
     cout<<"overs:...."<<endl;
    int over;
    cin>>over;
    cout<<"Waiting for Toss!!"<<"\n";
    if(rand()%2==0){
        cout<<t1.teamname<<" win the toss....!"<<endl<<endl;
        }
        else {
            t2.getteamname(),cout<<" win the toss....\n\n";
        }

    cout << "\n\nRun(0<=x<=6),no_ball runs(-1to-7),wide runs(7to 11) and witcket(-1)\n";
    for (int  i = 1; i <= 6 * over; i++)
    {
        int  x;
        cin >> x;
        cricket1 b(x);
        b.display();
        while (x < 0)
        {
            cout << "Wrong bowl, again bowl plz.\n\n" ;
            cin >> x;
            cricket1 b(x);
            b.display();
        }
        if (wicket == (wi - 1))
            {
                cout << "all wicket fall";
                break;
            }
    }
   cout << "End of "<<t1.teamname<<" innings !!\n";
    total_run = run1, w1 = wicket;
    cout<<t1.teamname<<" Total run.. "<<total_run<<endl,
    cout<<"Innings Extras:"<<ie<<endl,
    cout<<"Over:"<<ov<<"."<<bal<<endl<<"Wickets:"<<w1<<endl<<endl;
    cout<<"SECOND INNINGS......!!\n";
    cout<<t2.teamname<<" need "<<total_run +1 << " in "<<over*6 <<" bowls.\n";
    cout << "Run(1to6),No(-1to-7),wide(7to 11) and witcket(420)\n";
    cricket1 k(0, 0, 0,0);
   for (int  i = 1; i <= 6 * over; i++)
    {
        int  x;
        cin >> x;
        cricket1 b(x);
        b.display();
        while (x < 0)
        {
            cin >> x;
            cricket1 b(x);
            b.display();
        }
        if (wicket == (wi - 1))
            {
                cout << "All OUT";
                break;
            }
    }
    Total_Run = run1, W2 = wicket,IE=extras;
    cout<<t2.teamname,
    cout<<" Total run "<<total_run<<endl<<"Innings Extras:"<<IE<<endl,
    cout<<"Over:"<<ov<<"."<<bal<<endl<<"Wickets:"<<W2 <<endl;
    if (total_run > Total_Run)
        {
            cout<<t2.teamname<<" won by "<<total_run - Total_Run<<" runs.";
        }
   else  if(total_run < Total_Run)
       {
            cout<<t2.teamname<<" won by "<<Total_Run - total_run<<" runs.";
       }
    else cout<<" DRAW\n";
    return 0;
}
