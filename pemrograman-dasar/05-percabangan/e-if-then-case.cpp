#include <iostream>
using namespace std;

int main() {
 int N;
 cin >> N;
 if(N >= 0 and N <= 9) cout << "satuan" << endl;
 if(N >= 10 and N <= 99) cout << "puluhan" << endl;
 if(N >= 100 and N <= 999) cout << "ratusan" << endl;
 if(N >= 1000 and N <= 9999) cout << "ribuan" << endl;
 if(N >= 10000 and N <= 99999) cout << "puluhribuan" << endl; 
}