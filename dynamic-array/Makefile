PROJECT_NAME := dynamic_array

CC := gcc
CFLAGS := -Wall

all:	lib test demo
	@echo "Building ${PROJECT_NAME}.."

lib:	lib.o lib.a
	@echo "Building static library.."

lib.o:	dynamic_array.c dynamic_array.h
	@echo "Building lib${PROJECT_NAME}.."
	${CC} ${CFLAGS} -O -c dynamic_array.c

lib.a:	${PROJECT_NAME}.o
	@echo "Building lib${PROJECT_NAME} static library.."
	ar -rc lib${PROJECT_NAME}.a *.o

test:	lib libunity.a test_dynamic_array.c
	${CC} ${CFLAGS} -o ${PROJECT_NAME}_test test_dynamic_array.c lib${PROJECT_NAME}.a libunity.a

demo:	demo.c
	@echo "Building ${PROJECT_NAME}_demo.."
	${CC} ${CFLAGS} -o ${PROJECT_NAME}_demo demo.c lib${PROJECT_NAME}.a

run:	all
	./${PROJECT_NAME}_demo

test_run:	all
	./${PROJECT_NAME}_test

clean:
	@echo "Cleaning up.."
	@rm -f *_array.o
	@rm -f *_array.a
	@rm -f *_demo
	@rm -f *_test
