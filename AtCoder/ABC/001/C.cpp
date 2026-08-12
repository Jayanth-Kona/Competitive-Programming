#include<bits/stdc++.h>
using namespace std;

int main(){
    int Deg , Dis ; cin >> Deg >> Dis;

    double deg = Deg / 10.0;
    double wind_speed = Dis / 60.0;
    double rounded_speed = round(wind_speed * 10) / 10.0;

    int W;
    if(rounded_speed <= 0.2){
        W = 0;
    }
    else if(rounded_speed <= 1.5){
        W = 1;
    }
    else if(rounded_speed <= 3.3){
        W = 2;
    }
    else if(rounded_speed <= 5.4){
        W = 3;
    }
    else if(rounded_speed <= 7.9){
        W = 4;
    }
    else if(rounded_speed <= 10.7){
        W = 5;
    }
    else if(rounded_speed <= 13.8){
        W = 6;
    }
    else if(rounded_speed <= 17.1){
        W = 7;
    }
    else if(rounded_speed <= 20.7){
        W = 8;
    }
    else if(rounded_speed <= 24.4){
        W = 9;
    }
    else if(rounded_speed <= 28.4){
        W = 10;
    }
    else if(rounded_speed <= 32.6){
        W = 11;
    } else {
        W = 12;
    }

    string Dir;
    if(W == 0){
        Dir = "C";
    }
    else{
        if(deg >= 348.75 || deg < 11.25){
            Dir = "N";
        }
        else if(deg >= 11.25 && deg < 33.75){
            Dir = "NNE";
        }
        else if(deg >= 33.75 && deg < 56.25){
            Dir = "NE";
        }
        else if(deg >= 56.25 && deg < 78.75){
            Dir = "ENE";
        }
        else if(deg >= 78.75 && deg < 101.25){
            Dir = "E";
        }
        else if(deg >= 101.25 && deg < 123.75){
            Dir = "ESE";
        }
        else if(deg >= 123.75 && deg < 146.25){
            Dir = "SE";
        }
        else if(deg >= 146.25 && deg < 168.75){
            Dir = "SSE";
        }
        else if(deg >= 168.75 && deg < 191.25){
            Dir = "S";
        }
        else if(deg >= 191.25 && deg < 213.75){
            Dir = "SSW";
        }
        else if(deg >= 213.75 && deg < 236.25){
            Dir = "SW";
        }
        else if(deg >= 236.25 && deg < 258.75){
            Dir = "WSW";
        }
        else if(deg >= 258.75 && deg < 281.25){
            Dir = "W";
        }
        else if(deg >= 281.25 && deg < 303.75){
            Dir = "WNW";
        }
        else if(deg >= 303.75 && deg < 326.25){
            Dir = "NW";
        }
        else if(deg >= 326.25 && deg < 348.75){
            Dir = "NNW";
        }
    }

    cout << Dir << " " << W << endl;

    return 0;
}