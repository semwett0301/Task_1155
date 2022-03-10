#include <iostream>
#include <string>

using namespace std;

bool can_move(int a, int b) {
    return a > 0 && b > 0;
}

void move_nearby(int* a, int* b, string names) {
    *a -= 1;
    *b -= 1;
    cout << names << "-" << "\n";
}

void move_multiples(int* a, int* b, string first_edge, string second_edge, string tmp_edge) {
    *a -= 1;
    *b -= 1;
    cout << tmp_edge << "+" << "\n" << first_edge << "-" << "\n" << second_edge << "-" << "\n";
}

int main() {
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;

    // Проверяем два блока вершин, несовместных между собой
    if (e + d + b + g == a + h + f + c) {
        for (int i = 0; i < 100; i++) {
            // соседние вершины
            if (can_move(b, a)) {
                move_nearby(&b, &a, "BA");
            }

            if (can_move(b, c)) {
                move_nearby(&b, &c, "BC");
            }

            if (can_move(b, f)) {
                move_nearby(&b, &f, "BF");
            }

            if (can_move(d, a)) {
                move_nearby(&d, &a, "DA");
            }

            if (can_move(d, c)) {
                move_nearby(&d, &c, "DC");
            }

            if (can_move(d, h)) {
                move_nearby(&d, &h, "DH");
            }

            if (can_move(e, a)) {
                move_nearby(&e, &a, "EA");
            }

            if (can_move(e, f)) {
                move_nearby(&e, &f, "EF");
            }

            if (can_move(e, h)) {
                move_nearby(&e, &h, "EH");
            }

            if (can_move(g, h)) {
                move_nearby(&g, &h, "GH");
            }

            if (can_move(g, c)) {
                move_nearby(&g, &c, "GC");
            }

            if (can_move(g, f)) {
                move_nearby(&g, &f, "GF");
            }

            // вершины, через количество дуг, кратных 3
            if (can_move(b, h)) {
                move_multiples(&b, &h, "AB", "EH", "AE");
            }

            if (can_move(d,f)) {
                move_multiples(&d, &f, "DC", "FG", "CG");
            }

            if (can_move(e, c)) {
                move_multiples(&e, &c, "EF", "CB", "FB");
            }

            if (can_move(g, a)) {
                move_multiples(&g, &a, "GF", "BA", "FB");
            }
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
