#include <iostream>
#include <stdio.h>
#include <cstring>
#include <gmp.h>
#include <gmpxx.h>
#include <expr.h>
using namespace std;

void tempo(unsigned long int t){
	unsigned long int sec, min, hrs, day, mon, yrs;
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

void spacein(mpf_t result){
        mpf_t s, au, pc;
        mpf_init (s);
        mpf_init_set_str (au, "149597871", 10);
        mpf_init_set_str (au, "30856775999956", 10);
        char unit[10];
        mpf_inp_str(s,stdin,0);
        cin >> unit;
        if (strcmp(unit,"km")==0)
                mpf_set (result,s);
        else if (strcmp(unit,"au")==0 or strcmp(unit,"AU")==0 or strcmp(unit,"ua")==0)
                mpf_mul (result, s, au);
        else if (strcmp(unit,"pc")==0)
                mpf_mul (result, s, pc);
}

void spaceout(mpf_t input){
        mpf_t s, a, b, c, d;
        mpf_init_set (s,input);
        mpf_init_set_str (a, "154283879999", 10);
        mpf_init_set_str (b, "30856775999956.000", 10);
        mpf_init_set_str (c, "999999", 10);
        mpf_init_set_str (d, "149597871.000", 10);
        if (mpf_cmp (s,a)>0){
                mpf_div (s,s,b);
                mpf_out_str (stdout,10,0,s);
                cout << " pc";
        }
        else if (mpf_cmp (s,c)>0){
                mpf_div (s,s,d);
                mpf_out_str (stdout,10,0,s);
                cout << " au";
        }
        else{
                mpf_out_str (stdout,10,0,s);
                cout << " km";
        }
}


int main(){
    char o[3] = "si";
    while(strcmp(o,"si") == 0){
        unsigned long int t1i, t2i, t3i;
        mpf_t s, s1, s2, sm, a, v0, v;
        mpf_init (s); mpf_init (s); mpf_init (sm);
        mpf_init (s1); mpf_init (v0);
        mpf_init (s2); mpf_init (v);
        mpf_div_ui  (sm,s,2);
        cout << "Distanza destinazione (km/au/pc): ";
        spacein(s);
        cout << "Che sono ";
        mpf_out_str (stdout,10,0,s);
        cout << " km" << endl;
        cout << "Velocita' crociera (km/s): ";
        cin >> v;
        cout << "Accelerazione (km/s): ";
        cin >> a;
        cout << "Velocita' di partenza (km/s): ";
        cin >> v0;
        cout << endl;
        mpf_expr (s1, 10, "((a*a)-(b*b))/(2*c)", v, v0, a, NULL); //s1 = (((v*v)-(v0*v0))/(2*a));
        mpf_expr (s2, 10, "((a*a)/(2*b)", v, a, NULL); //s2 = ((v*v)/(2*a));
        if (mpf_cmp (s1,sm)>0){
            cout << "Impossibile raggiungere la velocita' di crociera in tempo" << endl;
        }
        else {
            mpf_t t1, t2, t3;
            mpf_init (t1); mpf_init (t2); mpf_init (t3);
            mpf_expr (t1, 10, "(2*a)/(b+c)", s1, v, v0, NULL); //t1 = ((2*s1)/(v+v0));
            mpf_expr (t2, 10, "(a-b-c)/d", s, s1, s2, v, NULL); //t2 = ((s-s1-s2)/v);
            mpf_expr (t1, 10, "(2*a)/v", s2, v, NULL); //t3 = ((2*s2)/v);
            t1i = mpf_get_ui (t1);
            t2i = mpf_get_ui (t2);
            t3i = mpf_get_ui (t3);
            if (v>v0){
                cout << "la velocita' di crociera verra' raggiunta in circa ";
                tempo(t1i);
                cout << endl;}
            cout << "Il viaggio durera' in totale circa ";
            tempo(t1i+t2i+t3i);
            cout << endl;
            cout << "la decelerazione inizera' dopo circa ";
            tempo(t1i+t2i);
            cout << endl;
            cout << "Quando mancheranno ";
            spaceout(s2);
            cout << " all'arrivo" << endl << endl << "continuare?" << endl;
            cin >> o; cout << endl;
        }
    }
	return 0;
}
