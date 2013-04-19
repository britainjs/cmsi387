address: addressTranslation.o addressTranslationTest.o
	gcc -o address *.o -lpthread

addressTranslation.o: addressTranslation.h

addressTranslationTest.o: addressTranslation.h

clean:
	rm address *.o
