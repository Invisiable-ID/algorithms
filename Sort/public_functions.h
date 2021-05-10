#ifndef _PUBLIC_FUNCTIONS_
#define _PUBLIC_FUNCTIONS_

void exchange(int* key1, int* key2)
{
		*key1 ^= *key2;
		*key2 ^= *key1;
		*key1 ^= *key2;
}

#endif
