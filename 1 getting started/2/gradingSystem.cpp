#include<iostream>
using namespace std;

int
main ()
{
  int marks;
  cin >> marks;
  if (marks > 90)
    {
      cout << "excellent" << endl;
    }
  else if (marks > 80 and marks <= 90)
    {
      cout << "good" << endl;
    }
  else if (marks > 70 and marks <= 80)
    {
      cout << "fair" << endl;
    }
  else if (marks > 60 and marks <= 70)
    {
      cout << "meets expectations" << endl;
    }
  else
    {
    cout << "below par"<<endl;
    }
  return 0;
}
