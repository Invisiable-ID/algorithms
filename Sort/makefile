target = selectsort.out insertsort.out shellsort.out mergesort.out quicksort.out
program : $(target)
	touch target.txt
	./$(target)>>target.txt
	make clean
selectsort.out : selectsort.c
	gcc selectsort.c -o selectsort.out
insertsort.out : insertsort.c
	gcc insertsort.c -o insertsort.out
shellsort.out : shellsort.c
	gcc shellsort.c -o shellsort.out
mergesort.out : mergesort.c
	gcc mergesort.c -o mergesort.out
quicksort.out : quicksort.c
	gcc quicksort.c -o quicksort.out
target.txt : 
	touch target.txt
clean : 
	rm $(target)
	rm target.txt
