OBJECTS := 1_node.o student.o 1_main.o menu.o
HEADS :=student.h menu.h 1_node.h
1_main: $(OBJECTS)
	gcc  $(OBJECTS) -o 1_main
1_node.o:1_node.c 1_node.h
	gcc -c $<
student.o:student.c student.h
	gcc -c $<
menu.o:menu.c menu.h
	gcc -c $<
1_main.o:1_main.c $(HEADS)
	gcc -c $<
clean: $(OBJECTS)
	rm *.o -rf

