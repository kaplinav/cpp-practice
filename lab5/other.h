
//Прототипы используемых в данном задании функций:
void Sort(char* pcFirst, int nNumber, int size, void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

// Вывод на экран элемента типа Double
void printDouble(void* e);

// Вывод на экран элемента типа Int
void printInt(void* e);

// Вызов указанной функции печати для каждого элемента
void showElements(char* pFirst, size_t n, size_t size, void(*printSpecific)(void*));

void SwapDouble(void* p1, void* p2);

int CmpDouble(void* p1, void* p2);