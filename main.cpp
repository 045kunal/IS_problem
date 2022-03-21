#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void addMembers(vector<string> &mem_name, vector<ll> &mem_contact)
{
    cout << "\nPlease enter the number of members you want to add: \n";
    ll num_members, i = 1;
    cin >> num_members;
    if (num_members > 0)
        cout << "\nPlease enter the details of all members that you want to add:\n";
    while (num_members--)
    {
        cout << "\nEnter name of member " << i << endl;
        string member;
        cin.ignore();
        getline(cin, member);
        mem_name.push_back(member);
        cout << "\nEnter contact number of member " << i << endl;
        ll contact;
        cin >> contact;
        mem_contact.push_back(contact);
        i++;
    }
}

void setTransactionLimit(ll &trns_limit)
{
    ll x = trns_limit;
    while (x >= trns_limit)
    {
        cout << "\n Please enter your new max transaction limit less than "<<trns_limit<<"rs.\n";
        cin >> x;
    }
    trns_limit = x;
    cout << "\n<-------------------------New transation limit is set for " << trns_limit << "rs.------------------------->\n";
}

void showAllMembers(vector<string> &mem_name, vector<ll> &mem_contact)
{
    if(mem_name.size()==1)
    {
        cout<<"\nThere are no members are added in this card other than owner!!!!!\n";
        return ;
    }
    cout
        << left
        << setw(15)
        << "Name"
        << left
        << setw(10)
        << "Contact No."
        << endl;
    
    for(ll i=0;i<mem_name.size();i++)
    {
        cout
            << left
            << setw(15)
            << mem_name[i]
            << left
            << setw(10)
            << mem_contact[i]
            << endl;
    }
}

void makeTransaction(ll &trns_limit, vector<string> &mem_name)
{
    cout<<"\nPlease enter your name:\n";
    string name;
    cin.ignore();
    getline(cin,name);
    vector<string>::iterator it;
    it = find(mem_name.begin(),mem_name.end(),name);
    if(it == mem_name.end()){
        cout<<"\nBecause you are not added as a member of this card, so you cannot make any transaction!!!\n";
        return ;
    }
    else{
        cout<<"\nEnter the amount you want to pay:\n";
        ll amt;
        cin>>amt;
        while(amt>trns_limit){
            cout<<"\nPlease enter your amount less than one time transaction limit:\n";
            cin>>amt;
        }
        cout<<"\nYour transaction has been successfully completed....\n";
    }
}

ll main()
{
    cout << "<----------------------------------------DECA Pays------------------------------------------>" << endl
         << "\n";
    cout << "Do you want to issue our WiFi credit/debit card?('1' for yes or '0' for no)" << endl;
    ll response;
    cin >> response;
    if (response == 1)
    {
        cout << "\n <---------------------------Thanks for choosing us!!!----------------------------> \n";
        string name;
        vector<string> mem_name;
        vector<ll> mem_contact;
        cout << "\n Please enter your name:"
             << "\n";
        cin.ignore();
        getline(cin, name);
        cout << "\n Please enter your phone number: \n";
        ll ph_no;
        cin >> ph_no;
        mem_name.push_back(name);
        mem_contact.push_back(ph_no);
        cout << "Do you want to add some other peoples to make transaction with your card?('1' for yes or '0' for no) \n";
        ll res_adding;
        cin >> res_adding;
        if (res_adding == 1)
        {
            addMembers(mem_name, mem_contact);
        }
        ll trns_limit = 2000;
        cout << "\nDefault transaction limit is set for 2000rs for one time transaction. Do you want to reduce it?('1' for Yes or '0' for No) \n";
        ll res;
        cin >> res;
        if (res == 1)
        {
            setTransactionLimit(trns_limit);
        }
        cout << "\n<---------------------All Set!!!! You're ready to make any trasaction with limit " << trns_limit << "rs------------------->\n\n";
        bool flag=true;
        while(flag)
        {
            cout << "\n1.Show all member's details\n2.Initiate any transaction\n3.Change transaction Limit\n4.Add new Member\n5.Exit\n\nEnter your choice:\n";
            ll choice;
            cin>>choice;
            switch (choice)
            {
                case 1:
                    showAllMembers(mem_name,mem_contact);
                    break;
                case 2:
                    makeTransaction(trns_limit,mem_name);
                    break;
                case 3:
                    setTransactionLimit(trns_limit);
                    break;
                case 4:
                    addMembers(mem_name,mem_contact);
                    break;
                case 5:
                    cout<<"\n<----------------------We are always there for your secure and reliable transactions------------------->\n";
                    flag=false;
                    break;
                default:
                    cout<<"\nChoose right option\n\n";
            }
        }
    }
    else
    {
        cout << "\n<----------------------We are always there for your secure and reliable transactions------------------->\n\n";
    }
}