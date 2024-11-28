typedef struct E {
    int value;
} E;

typedef struct list {
    int maxSize;
    int size;
    int curr;
    E* array;
} List;

List* create_list(int size) {
    List* l = (List*)malloc(sizeof(List));
    l->maxSize = size;
    l->size = l->curr = 0;
    l->array = (E*)malloc(sizeof(E));
    return l;
}

void clear(List* l) { // Não limpa de verdade, os elementos continuam lá
    l->size = l->curr = 0;
}

void insert(List* l, E it) {
    int i = l->size;
    while (i > l->curr) {
        l->array[i] = l->array[i-1];
        i--;
    }
    l->array[l->curr] = it;
    l->size++;
}

void append(List* l, E it) {
    l->array[l->size] = it;
    l->size++;
}

E remove(List* l) {
    E it = l->array[l->curr];
    for (int i = l->curr; i < l->size; i++) {
        l->array[i] = l->array[i+1];
    }
    l->size--;
    return it;
}

void moveToStart(List* l) { l->curr = 0; }

void moveToEnd(List* l) { l->curr = l->size; }

void prev(List* l) {
    if (l->curr != 0) {
        l->curr--;
    }
}

void next(List* l) {
    if (l->curr < l->size) {
        l->curr++;
    }
}

int legth(List* l) { return l->size; }

int currPos(List* l) { return l->curr; }

void moveToPos(List* l, int pos) { l->curr = pos; }

E getValue(List* l) { return l->array[l->curr]; }
