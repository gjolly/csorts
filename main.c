#include "sorting.h"
#include "utils.h"

int main() {
	int a[] = { 3, 43 , 32, 14, 65, 9, 8 };
	
	insertion((void**)a, sizeof(a), (int (*)(void*, void*))compInt);
}
