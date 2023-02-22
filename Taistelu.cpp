#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

// Portaalin koodi
//#include "Portal.cpp"

// Tässä on taistelun koodi (Pommittaja)
int Taistelu1(){

    int n = 0; // normaali liike
    int x = 0; // erikoisliike
    int e = 0; //elintaso
    int isku; // liike valinta
    int kysy; // kysymys uudelleen pelaamista varten
    int hahmo; // hahmo valinta


    int p = 0; // Botin liike valinta
    int m = 0; // kakkos liike BOTTI


    int q = 0; // normaali liike BOTTI
    int w = 0; // erikoisliike BOTTI

    system("cls");
    std::cout << "Taistelu alkaa!\n" << "\n";
    Sleep (1500);

    int pelaaja1 = 100; // Pommittajan HP
    int pelaaja2 = 100; // Alkoholistin HP

    std::cout << "Pommittaja Aloittaa!\n" << "\n";

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
            Sleep (3000);
        }

        // Jos pelaajien HP on yli 100 niin se on 100
        // MAX = 100
        if (pelaaja1 > 100){pelaaja1 = 100;}

        if (pelaaja2 > 100){pelaaja2 = 100;}


        // Jos pelaajien HP on alle 0 niin peli loppuu
        if (pelaaja2 <= 0) {
            system("cls");
            std::cout << "Pommittaja voitti!\n";
            Sleep (1000);
            std::cout << "Onneksi olkoon!\n";
            Sleep (2000);
            system ("cls");
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                Sleep (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                Sleep (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                Sleep (1000);
                exit(0);
            }
        }

        if (pelaaja1 <= 0) {
            system("cls");
            std::cout << "Alkoholisti voitti!\n" << "\n";
            Sleep (1000);
            std::cout << "Onnea seuraavalle kerralle!\n";
            Sleep (2000);
            system ("cls");
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                Sleep (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                Sleep (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                Sleep (1000);
                exit(0);
            }
        }

        system("cls");
        // Näyttää pelaajien HP
        std::cout << "Pommittajan HP: " << pelaaja1 << "\n";
        std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";

        // Aloitus teksti
        std::cout << "Liikkeiden käyttö määrä\n" "Normaali liikkeet: " << n << "\n" "Erikoisliikkeet: " << x << "\n";
        std::cout << "Valitse liike minkä käytäy\n" << "\n";
        std::cout << "1. Nyrkki (10dmg)\n";
        std::cout << "2. Kotitekoinen pommi (35dmg) (2N)\n";
        std::cout << "3. (Ultimate) Ydinpommi (75dmg) (2N ja 1E)\n";
        std::cout << "4. Erikoisliike: Adrenaliini piikki (+35hp) (2N)\n";
        std::cout << "Valitse liike: ";
        std::cin >> isku;

        // isku 1 koodi (Nyrkki)
        if (isku == 1){
            n++;
            system("cls");
            pelaaja2 = pelaaja2 - 10;
            std::cout << "\n" << "Pommittaja iski nyrkillä!\n";
            Sleep (1000);
            std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
            Sleep (1000);
            e++;
        }

        // isku 2 koodi (Kootitekoinen pommi)
        if (isku == 2 ) {

            // isku 2 koodi (Kootitekoinen pommi) (Ei tarpeeksi liikkeitä)
            if (isku == 2 && n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << n;
                Sleep (1500);
            }

            if (n == 2 ||n >= 2){
                n--;
                system("cls");
                pelaaja2 = pelaaja2 - 35;
                std::cout << "\n" << "Pommittaja iski kotitekoisella pommilla!\n";
                Sleep (1000);
                std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
                Sleep (1000);
                e++;
            }
        }

        // isku 3 koodi (Ydinpommi)
        if (isku == 3) {

            // isku 3 koodi (Ydinpommi) (Ei tarpeeksi liikkeitä)
            if (isku == 3 && n < 2 || isku == 3 && x < 1 || isku == 3 && n < 2 && x < 1 ) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << n << x;
                Sleep (1500);
            }

            // isku 3 koodi (Ydinpommi) (Tarpeeksi liikkeitä)
            if (n == 2 && x == 1|| isku == 3 && n >= 2 && x >= 1) {
                n--; n--; x--;
                system("cls");
                pelaaja2 = pelaaja2 - 75;
                std::cout << "\n" << "Pommittaja iski ydinpommilla!\n";
                Sleep (1000);
                std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
                Sleep (1000);
                e++;
            }
        }

        

        // isku 4 koodi (Adrenaliini piikki)
        if (isku == 4) {

            // isku 4 koodi (Adrenaliini piikki) (Ei tarpeeksi liikkeitä)
            if (n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << n << "\n";
                Sleep (1500);
            }

            // isku 4 koodi (Adrenaliini piikki) (Tarpeeksi liikkeitä)
            if (n == 2 || n >= 2 ) {
                x++; n--; n--;
                system("cls");
                std::cout << "Pommittaja käytti erikoisliikkeen!\n";
                Sleep (1000);
                pelaaja1 = pelaaja1 + 30;
                std::cout << "Pommittajan HP: " << pelaaja1 << "\n";
                Sleep (1000);
                e++;
            }

            // isku 4 koodi (Adrenaliini piikki) (Liian iso HP taso)
            //if (isku == 4 && pelaaja1 > 70) {
            //    std::cout << "Liian iso HP määrä!\n";
            //    std::cout << pelaaja1 << "\n";
            //    Sleep (1500);
            //}
        }   

        if (pelaaja2 <= 0) {
            system("cls");
            std::cout << "Pommittaja voitti!\n" << "\n";
            Sleep (1000);
            std::cout << "Onneksi olkoon!\n";
            Sleep (2000);
            system ("cls");
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                Sleep (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                Sleep (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                Sleep (1000);
                exit(0);
            }
        }

        // Alkoholistin vuoro
        std::cout << "Alkoholistin vuoro!\n" << "\n";
        Sleep (1500);




        // Alkoholistin liikkeet

        //Ultimate jos botilla on tarpeeksi liikkeitä
        if (q == 2 && w == 1) {
            q--; q--; w--;
            pelaaja1 = pelaaja1 - 50;
            std::cout << "Alkoholisti käyttää isän kättä!\n";
            Sleep (1000);
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n" << "\n";
            Sleep (1000);
            p++;
        }

        //Erikoisliike jos botilla ei ole tarpeeksi ultimateen
        if (w == 0 && q == 2) {
            w++; q--; q--;
            pelaaja2 = pelaaja2 + 30;
            std::cout << "Alkoholisti juo kaljaa!\n";
            Sleep (1000);
            std::cout << "Alkoholistin HP: " << pelaaja2 << "\n" << "\n";
            Sleep (1000);
            p++;
        }

        if (p == 0) {
            q++;
            pelaaja1 = pelaaja1 - 20;
            std::cout << "Alkoholisti iskee puukolla!\n";
            Sleep (1000);
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n" << "\n";
            Sleep (1000);
            m++;
        }

        // Pullon heitto
        if (m == 2) {
            m--; m--;
            pelaaja1 = pelaaja1 - 35;
            std::cout << "Alkoholisti heittää pullon!\n";
            Sleep (1000);
            std::cout << "Pommittajan HP: " << pelaaja1 << "\n" << "\n";
            Sleep (1000);
        }
    }
   return 0;
}












// Taistelu2() on alkoholistin taistelu, jossa pelaaja1 on alkoholisti ja pelaaja2 on pommittaja



// Tässä on taistelun koodi (Alkoholisti)
int Taistelu2(){


    int n = 0; // normaali liike
    int x = 0; // erikoisliike
    int e = 0; //elintaso
    int isku; // liike valinta
    int kysy; // kysymys uudelleen pelaamista varten
    int hahmo; // hahmon valinta


    int p = 0; // Botin liike valinta

    int m = 0; // kakkos liike BOTTI


    int q = 0; // normaali liike BOTTI
    int w = 0; // erikoisliike BOTTI

    system("cls");
    std::cout << "Taistelu alkaa!\n" << "\n";
    Sleep (1500);

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
            Sleep (3000);
        }

        // Jos pelaajien HP on yli 100 niin se on 100
        // MAX = 100
        if (pelaaja1 > 100){pelaaja1 = 100;}

        if (pelaaja2 > 100){pelaaja2 = 100;}


        // Jos pelaajien HP on alle 0 niin peli loppuu
        if (pelaaja2 <= 0) {
            system("cls");
            std::cout << "Alkoholisti voitti!\n";
            Sleep (1000);
            std::cout << "Onneksi olkoon!\n";
            Sleep (2000);
            system ("cls");
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                Sleep (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                Sleep (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                Sleep (1000);
                exit(0);
            }
        }

        if (pelaaja1 <= 0) {
            system("cls");
            std::cout << "Pommittaja voitti!\n";
            Sleep (1000);
            std::cout << "Onnea seuraavalle kierrokselle!\n";
            Sleep (2000);
            system ("cls");
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                Sleep (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                Sleep (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                Sleep (1000);
                exit(0);
            }
        }

        system("cls");
        // Näyttää pelaajien HP
        std::cout << "Alkoholistin HP: " << pelaaja1 << "\n";
        std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";

        // Aloitus teksti
        std::cout << "Liikkeiden käyttö määrä\n" "Normaali liikkeet: " << n << "\n" "Erikoisliikkeet: " << x << "\n";
        std::cout << "Valitse liike minkä käytäy\n" << "\n";
        std::cout << "1. Puukotus (20dmg)\n";
        std::cout << "2. Pullon heitto (35dmg) (2N) \n";
        std::cout << "3. (Ultimate) Isän käsi (50dmg) (2N ja 1E)\n";
        std::cout << "4. Erikois liike. Kalja\n";
        std::cout << "Valitse liike: ";
        std::cin >> isku;



        // isku 1 koodi (Puukotus)
        if (isku == 1){
            n++;
            system("cls");
            pelaaja2 = pelaaja2 - 10;
            std::cout << "\n" << "Alkoholisti iski puukolla!\n";
            Sleep (1000);
            std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
            Sleep (1000);
            e++;
        }

        // isku 2 koodi (Pullon heitto)
        if (isku == 2 ) {

            // isku 2 koodi (Pullon heitto) (Ei tarpeeksi liikkeitä)
            if (isku == 2 && n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << n;
                Sleep (1500);
            }

            if (n == 2 ||n >= 2){
                n--;
                system("cls");
                pelaaja2 = pelaaja2 - 35;
                std::cout << "\n" << "Alkoholisti heittää pullon!\n";
                Sleep (1000);
                std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
                Sleep (1000);
                e++;
            }
        }

        // isku 3 koodi (Ydinpommi)
        if (isku == 3) {

            // isku 3 koodi (Ydinpommi) (Ei tarpeeksi liikkeitä)
            if (isku == 3 && n < 2 || isku == 3 && x < 1 || isku == 3 && n < 2 && x < 1 ) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << n << x;
                Sleep (1500);
            }

            // isku 3 koodi (Ydinpommi) (Tarpeeksi liikkeitä)
            if (n == 2 && x == 1|| isku == 3 && n >= 2 && x >= 1) {
                n--; n--; x--;
                system("cls");
                pelaaja2 = pelaaja2 - 50;
                std::cout << "\n" << "Alkoholisti käyttää isän kättä!\n";
                Sleep (1000);
                std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
                Sleep (1000);
                e++;
            }
        }

        // isku 4 koodi (Kalja)
        if (isku == 4) {

            // isku 4 koodi (Kalja) (Ei tarpeeksi liikkeitä)
            if (n < 2) {
                std::cout << "Ei tarpeeksi Liikepisteitä!\n";
                std::cout << n << "\n";
                Sleep (1500);
            }

            // isku 4 koodi (Kalja) (Tarpeeksi liikkeitä)
            if (n == 2 || n >= 2 ) {
                x++; n--; n--;
                system("cls");
                std::cout << "Alkoholisti juo kaljaa!\n";
                Sleep (1000);
                pelaaja1 = pelaaja1 + 30;
                std::cout << "Alkoholistin HP: " << pelaaja1 << "\n";
                Sleep (1000);
                e++;
            }
        }

        if (pelaaja2 <= 0) {
            system("cls");
            std::cout << "Alkoholisti voitti!\n";
            Sleep (1000);
            std::cout << "Onneksi olkoon!\n";
            Sleep (2000);
            system ("cls");
            std::cout << "Haluatko pelata uudelleen? (Y/N) : ";
            std::cin >> kysy;

            if (kysy == 'Y' || kysy == 'y') {
                std::cout << "\n";
                std::cout << "Valitse hahmosi uudelleen...\n";
                Sleep (1000);
                std::cout << "1. Pommittaja  |  2. Alkoholisti\n";
                Sleep (1000);
                std::cout << "Valitse hahmosi: ";
                std::cin >> hahmo;

                if  (hahmo == 1) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu1();
                }

                if (hahmo == 2) {
                    std::cout << "\n";
                    std::cout << "Peli alkaa uudelleen...\n";
                    Sleep (1000);
                    Taistelu2();
                }
            }

            if (kysy == 'N' || kysy == 'n') {
                std::cout << "\n";
                std::cout << "Peli suljetaan...\n";
                Sleep (1000);
                exit(0);
            }
        }

        // Pommittajan vuoro
        std::cout << "Pommittajan vuoro!\n" << "\n";
        Sleep (1500);




        // Pommittajan liikkeet

        //Ultimate jos botilla on tarpeeksi liikkeitä
        if (q == 2 && w == 1) {
            q--; q--; w--;
            pelaaja1 = pelaaja1 - 75;
            std::cout << "Pommittaja iskee ydinpommilla!\n";
            Sleep (1000);
            std::cout << "Alkoholistin HP: " << pelaaja1 << "\n" << "\n";
            Sleep (1000);
            p++;
        }

        //Erikoisliike jos botilla ei ole tarpeeksi ultimateen
        if (w == 0 && q == 2) {
            w++; q--; q--;
            pelaaja2 = pelaaja2 + 30;
            std::cout << "Pommittaja vetää adrenaliinipiikin!\n";
            Sleep (1000);
            std::cout << "Pommittajan HP: " << pelaaja2 << "\n" << "\n";
            Sleep (1000);
            p++;
        }

        if (p == 0) {
            q++;
            pelaaja1 = pelaaja1 - 10;
            std::cout << "Pommittaja lyö nyrkillä!\n";
            Sleep (1000);
            std::cout << "Alkoholistim HP: " << pelaaja1 << "\n" << "\n";
            Sleep (1000);
            m++;
        }

        // Pullon heitto
        if (m == 2) {
            m--; m--;
            pelaaja1 = pelaaja1 - 35;
            std::cout << "Pommittaja heittää kotitekoisen pommin!\n";
            Sleep (1000);
            std::cout << "Alkoholistin HP: " << pelaaja1 << "\n" << "\n";
            Sleep (1000);
        }
    }

    return 0;
}