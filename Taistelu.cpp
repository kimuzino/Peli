#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>

// Portaalin koodi
//#include "Portal.cpp"

#include "WindowsLinux.h"

#include "Toiminnot.cpp"

void Taistelu1();
void Taistelu2();

// Tässä on taistelun koodi (Pommittaja)
void Taistelu1(){

    int n = 0; // normaali liike
    int x = 0; // erikoisliike
    int e = 0; //elintaso
    int isku; // liike valinta
    char kysy; // kysymys uudelleen pelaamista varten
    int hahmo; // hahmo valinta


    int p = 0; // Botin liike valinta
    int m = 0; // kakkos liike BOTTI


    int q = 0; // normaali liike BOTTI
    int w = 0; // erikoisliike BOTTI

    clear_screen();
    std::cout << "Taistelu alkaa!\n" << "\n";
    sleep_ms (1500);

    int pelaaja1 = 100; // Pommittajan HP
    int pelaaja2 = 100; // Alkoholistin HP

    std::cout << "Pommittaja Aloittaa!\n" << "\n";
    sleep_ms (1000);

    while (true){

        p = 0;
        
        // Varmuuden vuoksi
        if (n < 0) {n = 0;}
        if (x < 0) {x = 0;}


        // lisää elintasoa kun kaksi peliä pelattu
        if (e == 3) {
            std::cout << "\n";
            pelaaja1 = pelaaja1 + 15;
            pelaaja2 = pelaaja2 + 15;
            std::cout << "pelaajia parannettiin +15hp\n";
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n";
            std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
            e = 0;
            sleep_ms (3000);
        }

        // Jos pelaajien HP on yli 100 niin se on 100
        // MAX = 100
        if (pelaaja1 > 100){pelaaja1 = 100;}

        if (pelaaja2 > 100){pelaaja2 = 100;}


        // Jos pelaajien HP on alle 0 niin peli loppuu
        if (pelaaja2 <= 0) {
            clear_screen();
            std::cout << "Pommittaja voitti!\n";
            sleep_ms (1000);
            std::cout << "Onneksi olkoon!\n";
            sleep_ms (2000);
            clear_screen();
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                sleep_ms (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                sleep_ms (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu1();
                    break;
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu2();
                    break;
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }

            else {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }
        }

        if (pelaaja1 <= 0) {
            clear_screen();
            std::cout << "Alkoholisti voitti!\n" << "\n";
            sleep_ms (1000);
            std::cout << "Onnea seuraavalle kerralle!\n";
            sleep_ms (2000);
            clear_screen();
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                sleep_ms (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                sleep_ms (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu1();
                    break;
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu2();
                    break;
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }

            else {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }
        }

        clear_screen();
        // Näyttää pelaajien HP
        std::cout << "Pommittajan HP: " << pelaaja1 << "\n";
        std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";


        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Aloitus teksti
        std::cout << "Liikkeiden käyttö määrä\n" "Normaali liikkeet: " << n << "\n" "Erikoisliikkeet: " << x << "\n";
        std::cout << "Valitse liike minkä käytäy\n" << "\n";
        std::cout << "1. Nyrkki (10dmg)\n";
        std::cout << "2. Kotitekoinen pommi (35dmg) (2N)\n";
        std::cout << "3. (Ultimate) Ydinpommi (75dmg) (2N ja 1E)\n";
        std::cout << "4. Erikoisliike: Adrenaliini piikki (+35hp) (2N)\n";
        std::cout << "Valitse liike: ";
        std::cin >> isku;

        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Valitse liike 1-4 väliltä!\n";
            sleep_ms (1000);
            std::cout << "Valitse liike: ";
            std::cin >> isku;
            
        }

        // isku 1 koodi (Nyrkki)
        if (isku == 1){
            n++;
            clear_screen();
            pelaaja2 = pelaaja2 - 10;
            std::cout << "\n" << "Pommittaja iski nyrkillä!\n";
            sleep_ms (1000);
            std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
            sleep_ms (1000);
            e++;
        }

        // isku 2 koodi (Kootitekoinen pommi)
        if (isku == 2 ) {

            // isku 2 koodi (Kootitekoinen pommi) (Ei tarpeeksi liikkeitä)
            if (isku == 2 && n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << "Normaalit pisteet : " << n << "\n";
                sleep_ms (1500);
            }

            if (n == 2 ||n >= 2){
                n--;
                clear_screen();
                pelaaja2 = pelaaja2 - 35;
                std::cout << "\n" << "Pommittaja iski kotitekoisella pommilla!\n";
                sleep_ms (1000);
                std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
                sleep_ms (1000);
                e++;
            }
        }

        // isku 3 koodi (Ydinpommi)
        if (isku == 3) {

            // isku 3 koodi (Ydinpommi) (Ei tarpeeksi liikkeitä)
            if (isku == 3 && n < 2 || isku == 3 && x < 1 || isku == 3 && n < 2 && x < 1 ) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << "Normaali ja erikois pisteet : " << n << ", "<< x << "\n";
                sleep_ms (1500);
            }

            // isku 3 koodi (Ydinpommi) (Tarpeeksi liikkeitä)
            if (n == 2 && x == 1|| isku == 3 && n >= 2 && x >= 1) {
                n--; n--; x--;
                clear_screen();
                pelaaja2 = pelaaja2 - 75;
                std::cout << "\n" << "Pommittaja iski ydinpommilla!\n";
                sleep_ms (1000);
                std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
                sleep_ms (1000);
                e++;
            }
        }

        

        // isku 4 koodi (Adrenaliini piikki)
        if (isku == 4) {

            // isku 4 koodi (Adrenaliini piikki) (Ei tarpeeksi liikkeitä)
            if (n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << "Normaalit pisteet" << n << "\n";
                sleep_ms (1500);
            }

            // isku 4 koodi (Adrenaliini piikki) (Tarpeeksi liikkeitä)
            if (n == 2 || n >= 2 ) {
                x++; n--; n--;
                clear_screen();
                std::cout << "Pommittaja käytti erikoisliikkeen!\n";
                sleep_ms (1000);
                pelaaja1 = pelaaja1 + 30;
                std::cout << "Pommittajan HP: " << pelaaja1 << "\n";
                sleep_ms (1000);
                e++;
            }

            // isku 4 koodi (Adrenaliini piikki) (Liian iso HP taso)
            //if (isku == 4 && pelaaja1 > 70) {
            //    std::cout << "Liian iso HP määrä!\n";
            //    std::cout << pelaaja1 << "\n";
            //    sleep_ms (1500);
            //}
        }  

        if (pelaaja2 <= 0) {
            clear_screen();
            std::cout << "Pommittaja voitti!\n" << "\n";
            sleep_ms (1000);
            std::cout << "Onneksi olkoon!\n";
            sleep_ms (2000);
            clear_screen();
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                sleep_ms (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                sleep_ms (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu1();
                    break;
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu2();
                    break;
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }

            else {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }
        }

        // Alkoholistin vuoro
        std::cout << "Alkoholistin vuoro!\n" << "\n";
        sleep_ms (1500);




        // Alkoholistin liikkeet

        //Ultimate jos botilla on tarpeeksi liikkeitä
        if (q == 2 && w == 1) {
            q--; q--; w--;
            pelaaja1 = pelaaja1 - 50;
            std::cout << "Alkoholisti käyttää isän kättä!\n";
            sleep_ms (1000);
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n" << "\n";
            sleep_ms (1000);
            continue;
        }

        //Erikoisliike jos botilla ei ole tarpeeksi ultimateen
        if (w == 0 && q == 2) {
            w++; q--; q--;
            pelaaja2 = pelaaja2 + 30;
            std::cout << "Alkoholisti juo kaljaa!\n";
            sleep_ms (1000);
            std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
            sleep_ms (1000);
            continue;
        }


        // Pullon heitto
        if (m == 2) {
            m--; m--;
            pelaaja1 = pelaaja1 - 35;
            std::cout << "Alkoholisti heittää pullon!\n";
            sleep_ms (1000);
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n" << "\n";
            sleep_ms (1000);
            continue;
        }

        // puukko isku
        if (p == 0) {
            q++;
            pelaaja1 = pelaaja1 - 20;
            std::cout << "Alkoholisti iskee puukolla!\n";
            sleep_ms (1000);
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n" << "\n";
            sleep_ms (1000);
            m++;
            continue;
        }

        
    }
}












// Taistelu2() on alkoholistin taistelu, jossa pelaaja1 on alkoholisti ja pelaaja2 on pommittaja



// Tässä on taistelun koodi (Alkoholisti)
void Taistelu2(){


    int n = 0; // normaali liike
    int x = 0; // erikoisliike
    int e = 0; //elintaso
    int isku; // liike valinta
    char kysy; // kysymys uudelleen pelaamista varten
    int hahmo; // hahmon valinta


    int p = 0; // Botin liike valinta

    int m = 0; // kakkos liike BOTTI


    int q = 0; // normaali liike BOTTI
    int w = 0; // erikoisliike BOTTI

    clear_screen();
    std::cout << "Taistelu alkaa!\n" << "\n";
    sleep_ms (1500);

    int pelaaja1 = 100; // Pommittajan HP
    int pelaaja2 = 100; // Alkoholistin HP

    std::cout << "Alkoholisti Aloittaa!\n" << "\n";

    while (true){

        // Varmuuden vuoksi
        if (n < 0) {n = 0;}
        if (x < 0) {x = 0;}


        // lisää elintasoa kun kaksi peliä pelattu
        if (e == 3) {
            std::cout << "\n";
            pelaaja1 = pelaaja1 + 15;
            pelaaja2 = pelaaja2 + 15;
            std::cout << "pelaajia parannettiin +15hp\n";
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n";
            std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
            e = 0;
            sleep_ms (3000);
        }

        // Jos pelaajien HP on yli 100 niin se on 100
        // MAX = 100
        if (pelaaja1 > 100){pelaaja1 = 100;}

        if (pelaaja2 > 100){pelaaja2 = 100;}


        // Jos pelaajien HP on alle 0 niin peli loppuu
        if (pelaaja2 <= 0) {
            clear_screen();
            std::cout << "Alkoholisti voitti!\n";
            sleep_ms (1000);
            std::cout << "Onneksi olkoon!\n";
            sleep_ms (2000);
            clear_screen();
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                sleep_ms (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                sleep_ms (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu1();
                    break;
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu2();
                    break;
                }

            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }

            else {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }

        }

        if (pelaaja1 <= 0) {
            clear_screen();
            std::cout << "Pommittaja voitti!\n";
            sleep_ms (1000);
            std::cout << "Onnea seuraavalle kierrokselle!\n";
            sleep_ms (2000);
            clear_screen();
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                sleep_ms (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                sleep_ms (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }

            else {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }
        }

        clear_screen();
        // Näyttää pelaajien HP
        std::cout << "Alkoholistin HP: " << pelaaja1 << "\n";
        std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";

        // Aloitus teksti
        std::cout << "Liikkeiden käyttö määrä\n" "Normaali liikkeet: " << n << "\n" "Erikoisliikkeet: " << x << "\n";
        std::cout << "Valitse liike minkä käytäy\n" << "\n";
        std::cout << "1. Puukotus (20dmg)\n";
        std::cout << "2. Pullon heitto (35dmg) (2N) \n";
        std::cout << "3. (Ultimate) Isän käsi (50dmg) (2N ja 1E)\n";
        std::cout << "4. Erikois liike. Kalja (+30hp) (2n)\n";
        std::cout << "Valitse liike: ";
        std::cin >> isku;


        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Valitse liike 1-4 väliltä!\n";
            sleep_ms (1000);
            std::cout << "Valitse liike: ";
            std::cin >> isku;
        }



        // isku 1 koodi (Puukotus)
        if (isku == 1){
            n++;
            clear_screen();
            pelaaja2 = pelaaja2 - 20;
            std::cout << "\n" << "Alkoholisti iski puukolla!\n";
            sleep_ms (1000);
            std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
            sleep_ms (1000);
            e++;
        }

        // isku 2 koodi (Pullon heitto)
        if (isku == 2 ) {

            // isku 2 koodi (Pullon heitto) (Ei tarpeeksi liikkeitä)
            if (isku == 2 && n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << "Normaalit pisteet : " << n << "\n";
                sleep_ms (1500);
            }

            if (n == 2 ||n >= 2){
                n--;
                clear_screen();
                pelaaja2 = pelaaja2 - 35;
                std::cout << "\n" << "Alkoholisti heittää pullon!\n";
                sleep_ms (1000);
                std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
                sleep_ms (1000);
                e++;
            }
        }

        // isku 3 koodi (Ydinpommi)
        if (isku == 3) {

            // isku 3 koodi (Ydinpommi) (Ei tarpeeksi liikkeitä)
            if (isku == 3 && n < 2 || isku == 3 && x < 1 || isku == 3 && n < 2 && x < 1 ) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << "Normaali ja erikois pisteet : " << n << ", "<< x << "\n" << "\n";
                sleep_ms (1500);
            }

            // isku 3 koodi (Ydinpommi) (Tarpeeksi liikkeitä)
            if (n == 2 && x == 1|| isku == 3 && n >= 2 && x >= 1) {
                n--; n--; x--;
                clear_screen();
                pelaaja2 = pelaaja2 - 50;
                std::cout << "\n" << "Alkoholisti käyttää isän kättä!\n";
                sleep_ms (1000);
                std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
                sleep_ms (1000);
                e++;
            }
        }

        // isku 4 koodi (Kalja)
        if (isku == 4) {

            // isku 4 koodi (Kalja) (Ei tarpeeksi liikkeitä)
            if (n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << "Normaalit pisteet : " << n << "\n";
                sleep_ms (1500);
            }

            // isku 4 koodi (Kalja) (Tarpeeksi liikkeitä)
            if (n == 2 || n >= 2 ) {
                x++; n--; n--;
                clear_screen();
                std::cout << "Alkoholisti juo kaljaa!\n";
                sleep_ms (1000);
                pelaaja1 = pelaaja1 + 30;
                std::cout << "Alkoholistin HP: " << pelaaja1 << "\n";
                sleep_ms (1000);
                e++;
            }
        }

        if (pelaaja2 <= 0) {
            clear_screen();
            std::cout << "Alkoholisti voitti!\n";
            sleep_ms (1000);
            std::cout << "Onneksi olkoon!\n";
            sleep_ms (2000);
            clear_screen();
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                sleep_ms (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                sleep_ms (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    sleep_ms (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }

            else {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                sleep_ms (1000);
                exit(0);
            }
        }

        // Pommittajan vuoro
        std::cout << "Pommittajan vuoro!\n" << "\n";
        sleep_ms (1500);




        // Pommittajan liikkeet

        //Ultimate jos botilla on tarpeeksi liikkeitä
        if (q == 2 && w == 1) {
            q--; q--; w--;
            pelaaja1 = pelaaja1 - 75;
            std::cout << "Pommittaja iskee ydinpommilla!\n";
            sleep_ms (1000);
            std::cout << "Alkoholistin HP: " << pelaaja1 << "\n" << "\n";
            sleep_ms (1000);
            continue;
        }

        //Erikoisliike jos botilla ei ole tarpeeksi ultimateen
        if (w == 0 && q == 2) {
            w++; q--; q--;
            pelaaja2 = pelaaja2 + 30;
            std::cout << "Pommittaja vetää adrenaliinipiikin!\n";
            sleep_ms (1000);
            std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
            sleep_ms (1000);
            continue;
        }
        
        // Pullon heitto
        if (m == 2) {
            m--; m--;
            pelaaja1 = pelaaja1 - 35;
            std::cout << "Pommittaja heittää kotitekoisen pommin!\n";
            sleep_ms (1000);
            std::cout << "Alkoholistin HP: " << pelaaja1 << "\n" << "\n";
            sleep_ms (1000);
            continue;
        }

        // Nyrkin lyönti
        if (p == 0) {
            q++;
            pelaaja1 = pelaaja1 - 10;
            std::cout << "Pommittaja lyö nyrkillä!\n";
            sleep_ms (1000);
            std::cout << "Alkoholistim HP: " << pelaaja1 << "\n" << "\n";
            sleep_ms (1000);
            m++;
            continue;
        }

        
    }
}