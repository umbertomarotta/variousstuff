#include <iostream>
#include <cstdlib>
#include <cstring>
#include <gmpxx.h>

using namespace std;

void tempo(mpf_class tf){
	mpz_class t, sec, min, hrs, day, mon, yrs;
	t = tf;
	sec = operator%(t, 60);
	min = operator%(t/60, 60);
	hrs = operator%((t/60)/60, 24);
	day = operator%(((t/60)/60)/24, 30);
	mon = operator%((((t/60)/60)/24)/30, 12);
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
	else if (sec < 1 and min==0)
        cout << "meno di un secondo ";
}

mpf_class spacein(){
	mpf_class s, au, pc;
	au="149597871";
	pc="30856775999956";
	char unit[10];
	cin >> s;
	cin >> unit;
	if (strcmp(unit,"km")==0)
		return s;
	else if (strcmp(unit,"au")==0 or strcmp(unit,"AU")==0 or strcmp(unit,"ua")==0)
		return s*au;
	else if (strcmp(unit,"pc")==0)
		return s*pc;
}

void spaceout(mpf_class s){
    mpf_class val1, val2, pc, au;
    val1="154283879999";
    val2="9999999";
    pc="30856775999956.000";
    au="149597871.000";
	if (s>val1)
		cout << s/pc << " pc";
	else if (s>val2)
		cout << s/au << " au";
	else
		cout << s << " km";
}


int main(){
	mpf_class a, v0, v;
	mpf_class s, s1, s2;
	cout << "Distanza destinazione (km/au/pc): ";
	s = spacein();
	cout << "Che sono " << s << " km ("; spaceout(s); cout << ")" << endl;
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
		return 0;
	}
	else {
		mpf_class t1, t2, t3;
		t1 = ((2*s1)/(v+v0));
		t2 = ((s-s1-s2)/v);
		t3 = ((2*s2)/v);
		if (v>v0){
			cout << "la velocita' di crociera verra' raggiunta in ";
			tempo(t1);
			cout << endl;}
		cout << "Il viaggio durera' in totale ";
		tempo(t1+t2+t3);
		cout << endl;
		cout << "la decelerazione inizera' dopo ";
		tempo(t1+t2);
		cout << endl;
		cout << "Quando mancheranno ";
		spaceout(s2);
		cout << " all'arrivo" << endl;
		return 0;
	}
}
