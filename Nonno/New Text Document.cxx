#include <iostream>
using namespace std;

int cifre(int num){
    int cont=1;
    while(num >= 1){
        num = num/10;
        cont = cont*10;
    }
    return cont;
}

int main(){
    while(true){
    int a, b, c, p1, p2, res;
    cout << "Dammi un numero: ";
    cin >> a;
    //cout << cifre(a) << endl;
    res = (a-2) + (2*cifre(a));
    cout << "Ti dico già che il risultato sarà " << res << endl;
    cout << "Dammi un altro numero: ";
    cin >> b;
    p1 = (cifre(a)-1)-b;
    cout << "Io invece ti do' questo: " << p1 << endl;
    cout << "Dammi il tuo ultimo numero: ";
    cin >> c;
    p2 = (cifre(a)-1)-c;
    cout << "Io invece ti do' questo: " << p2 << endl;
    if(a+b+c+p1+p2 == res){
        cout << "Se sommi " << a << " + " << b << " + " << p1 << " + ";
        cout << c << " + " << p2 << "..." << endl;
        cout << "Otterrai proprio " << res << "!! Sono un computer, ho controllato!" << endl;
        cout << "----------------------------------------" << endl;
    }}
    cout << "Ops... forse ho sbagliato qualcosa..." << endl;
    return 0;
}
