#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Karta {
public:
    int broj;
    string zog;
};

class Mac {
public:
    vector<Karta> karte;

    void napraviMac() {
        vector<string> zogovi = { "bastoni", "spade", "dinari", "kupe" };
        for (int i = 0; i < 4; i++) {
            for (int b = 1; b <= 10; b++) {
                Karta k;
                k.broj = b;
                k.zog = zogovi[i];
                karte.push_back(k);
            }
        }
    }

    void promijesaj() {
        srand(time(0)); 

        for (int i = 0; i < karte.size(); i++) {
            int j = rand() % karte.size();
            swap(karte[i], karte[j]);
        }
    }

    vector<Karta> podijeli10() {
        vector<Karta> ruka;
        for (int i = 0; i < 10; i++) {
            ruka.push_back(karte.back());
            karte.pop_back();
        }
        return ruka;
    }
};

class Igrac {
public:
    string ime;
    vector<Karta> ruka;
    int bodovi;

    void izracunajAkuzu() {
        bodovi = 0;

        vector<string> zogovi = { "bastoni", "spade", "denari", "coppe" };

        for (int i = 0; i < 4; i++) {
            bool ima1 = false, ima2 = false, ima3 = false;

            for (int j = 0; j < ruka.size(); j++) {
                if (ruka[j].zog == zogovi[i]) {
                    if (ruka[j].broj == 1) ima1 = true;
                    if (ruka[j].broj == 2) ima2 = true;
                    if (ruka[j].broj == 3) ima3 = true;
                }
            }

            if (ima1 && ima2 && ima3)
                bodovi += 3;
        }

        int brojaci[11] = { 0 };

        for (int i = 0; i < ruka.size(); i++) {
            if (ruka[i].broj <= 3)
                brojaci[ruka[i].broj]++;
        }

        for (int b = 1; b <= 3; b++) {
            if (brojaci[b] == 3) bodovi += 3;
            if (brojaci[b] == 4) bodovi += 4;
        }
    }
};

int main() {
    int n;
    cout << "Unesite broj igraca (2 ili 4): ";
    cin >> n;

    vector<Igrac> igraci(n);

    for (int i = 0; i < n; i++) {
        cout << "Ime igraca " << (i + 1) << ": ";
        cin >> igraci[i].ime;
    }

    Mac mac;
    mac.napraviMac();
    mac.promijesaj(); 

    for (int i = 0; i < n; i++) {
        igraci[i].ruka = mac.podijeli10();
        igraci[i].izracunajAkuzu();
    }

    cout << "\n AKUZA \n";
    for (int i = 0; i < n; i++) {
        cout << igraci[i].ime << " ima " << igraci[i].bodovi << " bodova\n";
    }

    return 0;
}
