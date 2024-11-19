#include <string>
#include <iostream>

using namespace std;

typedef struct list {
    int maxSize;
    int size;
    int curr;
    int* array;
} List;

List* create_list(int size) {
    List* l = (List*)malloc(sizeof(List));
    l->maxSize = size;
    l->size = l->curr = 0;
    l->array = (int*)malloc(sizeof(int));
    return l;
}

void append(List* l, int it) {
    l->array[l->size] = it;
    l->size++;
}

int remove(List* l) {
    int it = l->array[l->curr];
    for (int i = l->curr; i < l->size; i++) {
        l->array[i] = l->array[i+1];
    }
    l->size--;
    return it;
}

bool in(List* l, int it) {
    for (int i = 0; i < l->size; l++) {
        if (it == l->array[i]) {
            return true;
        }
    }
    return false;
}

void moveToStart(List* l) { l->curr = 0; }

int main() {
    List *l = create_list(2000000);
    string op;
    int id;
    int solved = 0;
    cin >> op;

    while (op != "end") {
        if (op == "add") {
            cin >> id;
            if (!in(l, id)) {
                append(l, id);
                }
            }

        if (op == "solve") {
            moveToStart(l);
            remove(l);
            solved++;
        }

        if (op == "print") {
            if (l->size > 0) {
                for (int i = 0; i < l->size; i++) {
                cout << l->array[i];
                    if (i < l->size - 1) {
                        cout << " ";
                    }
                }
            }
            else {
                cout << "x";
            }
            cout << endl;
        }

        if (op == "stats") {
            cout << solved << " " << l->size << endl;
        }
        cin >> op;
    }
}
