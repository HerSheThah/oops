#include<iostream>
#include<queue>
using namespace std;
void display(priority_queue <int> pq)
{
	priority_queue <int> pri = pq;
	while (!pri.empty()){
		cout<<pri.top()<<endl;
		pri.pop();
	}
}
void showpq(
    priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>,greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
int main()
{
	priority_queue <int> pq;
	priority_queue<int, vector<int>, greater<int> > g;
	pq.push(12);
	pq.push(1);
	pq.push(34);
	pq.push(3);
	pq.push(5);
	display(pq);
	g.push(12);
	g.push(1);
	g.push(34);
	g.push(3);
	g.push(5);
	showpq(g);
	
}
