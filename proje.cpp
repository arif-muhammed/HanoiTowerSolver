#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <iomanip>
using namespace std;

void printTowers(vector<vector<int>>& towers) {
    int n = 0;
    for (const auto& tower : towers) {
        if (tower.size() > n) {
            n = tower.size();
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            if (i < towers[j].size() && towers[j][i] != 0) {
                cout << setw(3) << towers[j][i];
            }
            else {
                cout << " | ";
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << "---\t---\t---" << endl;
    cout << " A \t B \t C \n" << endl;
}

void moveDisk(vector<vector<int>>& towers, char from, char to, int& steps) {
    int fromPeg = from - 'A';
    int toPeg = to - 'A';
    int disk = towers[fromPeg].back();
    towers[fromPeg].pop_back();
    towers[toPeg].push_back(disk);
    steps++;
    printTowers(towers);
}

void recursiveHanoi(int n, char kaynak, char ara, char hedef, vector<vector<int>>& towers, int& steps) {
    if (n == 1) {
        cout << n << ".Diski " << kaynak << " dan " << hedef << " ye tasi." << endl;
        moveDisk(towers, kaynak, hedef, steps);
        return;
    }
    else {
        recursiveHanoi(n - 1, kaynak, hedef, ara, towers, steps);
        cout << n << ".Diski " << kaynak << " dan " << hedef << " ye tasi." << endl;
        moveDisk(towers, kaynak, hedef, steps);
        recursiveHanoi(n - 1, ara, kaynak, hedef, towers, steps);
    }
}

void iterativeHanoi(int n, char kaynak, char ara, char hedef, vector<vector<int>>& towers, int& steps) {
    stack<pair<int, pair<char, char>>> s;
    s.push(make_pair(n, make_pair(kaynak, hedef)));

    while (!s.empty()) {
        auto p = s.top();
        s.pop();
        int disk = p.first;
        char from = p.second.first;
        char to = p.second.second;

        if (disk == 1) {
            cout << disk << ".Diski " << from << " dan " << to << " ye tasi." << endl;
            moveDisk(towers, from, to, steps);
        }
        else {
            char other = 'A' + 'B' + 'C' - from - to;
            s.push(make_pair(disk - 1, make_pair(other, to)));
            s.push(make_pair(1, make_pair(from, to)));
            s.push(make_pair(disk - 1, make_pair(from, other)));
        }
    }
}

void solveHanoi(int diskSayisi, bool isRecursive) {
    vector<vector<int>> towers(3);
    for (int i = diskSayisi; i >= 1; --i) {
        towers[0].push_back(i);
    }

    printTowers(towers);
    int steps = 0;
    clock_t start = clock();
    if (isRecursive) {
        recursiveHanoi(diskSayisi, 'A', 'B', 'C', towers, steps);
    }
    else {
        iterativeHanoi(diskSayisi, 'A', 'B', 'C', towers, steps);
    }
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Hanoi Kuleleri " << diskSayisi << " disk icin " << time_taken << " saniye surdu." << endl;
    cout << "Toplam adim sayisi: " << steps << endl;
    cout << "Hesaplanan adim sayisi (2^" << diskSayisi << " - 1): " << (1 << diskSayisi) - 1 << endl;
}

int main() {
    int diskSayisi;
    int secim;
    bool firstOperation = true;

    while (true) {
        cout << "1. Klasik Hanoi Kuleleri Problemi\n";
        cout << "2. Ileri Duzey Hanoi Kuleleri Problemi\n";
        cout << "3. Rekursif Cozum\n";
        cout << "4. Iteratif Cozum\n";
        if (!firstOperation) {
            cout << "5. Cikis\n";
        }
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 5 && !firstOperation) {
            cout << "Cikis yapiliyor..." << endl;
            break;
        }

        switch (secim) {
        case 1:
            cout << "Disk Sayisi (4 veya daha az): ";
            cin >> diskSayisi;
            if (diskSayisi > 4) {
                cout << "Disk sayisi 4 veya daha az olmali!" << endl;
                break;
            }
            cout << diskSayisi << " diskli Klasik Hanoi Kuleleri Problemi" << endl;
            solveHanoi(diskSayisi, true);
            break;
        case 2:
            cout << "Disk Sayisi (5 veya daha fazla): ";
            cin >> diskSayisi;
            if (diskSayisi < 5) {
                cout << "Disk sayisi 5 veya daha fazla olmali!" << endl;
                break;
            }
            cout << diskSayisi << " diskli Ileri Duzey Hanoi Kuleleri Problemi" << endl;
            solveHanoi(diskSayisi, true);
            break;
        case 3:
            cout << "Disk Sayisi: ";
            cin >> diskSayisi;
            solveHanoi(diskSayisi, true);
            break;
        case 4:
            cout << "Disk Sayisi: ";
            cin >> diskSayisi;
            solveHanoi(diskSayisi, false);
            break;
        default:
            cout << "Gecersiz secim!" << endl;
            break;
        }

        firstOperation = false;
    }

    return 0;
}
