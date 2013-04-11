philo: philo-harness.o philo-sync.o philo-cs.o producer.o utility.o
	gcc -o philo *.o -lpthread

philo-harness.o: philo-sync.h

philo-cs.o: philo-cs.h philo.h philo-sync.h

philo-sync.o: philo-sync.h philo.h

producer.o: philo-cs.h philo-sync.h philo.h utility.h

utility.o: utility.h

clean:
	rm philo *.o
