PROJECT_NAME := dynamic_array

CC := gcc
CFLAGS := -Wall

all:	lib demo
	@echo "Building ${PROJECT_NAME}.."

lib:	lib.o lib.a
	@echo "Building static library.."

lib.o:	dynamic_array.c dynamic_array.h
	@echo "Building lib${PROJECT_NAME}.."
	${CC} ${CFLAGS} -O -c dynamic_array.c

lib.a:	${PROJECT_NAME}.o
	@echo "Building lib${PROJECT_NAME} static library.."
	ar -rc ${PROJECT_NAME}.a *.o


demo:	demo.c
	@echo "Building ${PROJECT_NAME}_demo.."
	${CC} ${CFLAGS} -o ${PROJECT_NAME}_demo demo.c ${PROJECT_NAME}.a

run:	all
	./${PROJECT_NAME}_demo

clean:
	@echo "Cleaning up.."
	@rm -f *.o
	@rm -f *.a
	@rm -f *_demo
