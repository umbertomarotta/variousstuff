#include <iostream>
#include <cstring>
using namespace std;

void tempo(unsigned long long t){
	unsigned long long sec, min, hrs, day, mon, yrs;
	sec = t%60;
	min = (t/60)%60;
	hrs = ((t/60)/60)%24;
	day = (((t/60)/60)/24)%30;
	mon = ((((t/60)/60)/24)/30)%12;
	yrs = ((((t/60)/60)/24)/30)/12;
	if (yrs != 0){
		if (yrs == 1)
			cout << "1 anno, ";
		else
			cout << yrs << " anni, ";
	}
	if (mon != 0){
		if (mon == 1)
			cout << "1 mese, ";
		else
			cout << mon << " mesi, ";
	}
	if (day != 0){
		if (day == 1)
			cout << "1 giorno, ";
		else
			cout << day << " giorni, ";
	}
	if (hrs != 0){
		if (hrs == 1)
			cout << "1 ora, ";
		else
			cout << hrs << " ore, ";
	}
	if (min != 0){
		if (min == 1)
			cout << "1 minuto, ";
		else
			cout << min << " minuti, ";
	}
	if (sec != 0){
		if (sec == 1)
			cout << "1 secondo ";
		else
			cout << sec << " secondi ";
	}
}

unsigned long long spacein(){
        long double s;
        char unit[10];
        cin >> s;
        cin >> unit;
        if (strcmp(unit,"km")==0)
                return s;
        else if (strcmp(unit,"au")==0 or strcmp(unit,"AU")==0 or strcmp(unit,"ua")==0)
                return s*149597871;
        else if (strcmp(unit,"pc")==0){
                return s*30856775999956ULL;}
}

void spaceout(unsigned long long s){
        if (s>154283879999ULL)
                cout << s/30856775999956.000 << " pc";
        else if (s>9999999)
                cout << s/149597871.000 << " au";
        else
                cout << s << " km";
}


int main(){
    char o[3] = "si";
    while(true){
    //while(strcmp(o,"si") == 0){
        long double a, v0, v;
        unsigned long long s, s1, s2;
        cout << "Distanza destinazione (km/au/pc): ";
        s = spacein();
        cout << "Che sono " << s << " km" << endl;
        cout << "Velocita' crociera (km/s): ";
        cin >> v;
        cout << "Accelerazione (km/s): ";
        cin >> a;
        cout << "Velocita' di partenza (km/s): ";
        cin >> v0;
        cout << endl;
        s1 = (((v*v)-(v0*v0))/(2*a));
        s2 = ((v*v)/(2*a));
        if (s1 > (s/2)){
            cout << "Impossibile raggiungere la velocita' di crociera in tempo" << endl;
        }
        else {
            long double t1, t2, t3;
            t1 = ((2*s1)/(v+v0));
            t2 = ((s-s1-s2)/v);
            t3 = ((2*s2)/v);
            if (v>v0){
                cout << "la velocita' di crociera verra' raggiunta in circa ";
                tempo(t1);
                cout << endl;}
            cout << "Il viaggio durera' in totale circa ";
            tempo(t1+t2+t3);
            cout << endl;
            cout << "la decelerazione inizera' dopo circa ";
            tempo(t1+t2);
            cout << endl;
            cout << "Quando mancheranno ";
            spaceout(s2);
            cout << " all'arrivo" << endl; //<< endl << "continuare?" << endl;
            //cin >> o;
            cout << endl;
        }
    }
	return 0;
}
