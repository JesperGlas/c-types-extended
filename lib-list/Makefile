PROJECT_NAME := lib_list

CC := gcc
CFLAGS := -Wall

all:	lib test demo
	@echo "Building library ${PROJECT_NAME}.."

lib:	${PROJECT_NAME}.c ${PROJECT_NAME}.h
	@echo "Building ${PROJECT_NAME} as a static library.."
	${CC} ${CFLAGS} -O -c ${PROJECT_NAME}.c
	ar -rc ${PROJECT_NAME}.a ${PROJECT_NAME}.o

libunity.a:	libunity
	cp libunity/* .

test:	lib libunity.a test_${PROJECT_NAME}.c
	${CC} ${CFLAGS} -o test_${PROJECT_NAME}.out test_${PROJECT_NAME}.c ${PROJECT_NAME}.a libunity.a

demo:	lib demo_${PROJECT_NAME}.c
	@echo "Building demo_${PROJECT_NAME}.."
	${CC} ${CFLAGS} -o demo_${PROJECT_NAME}.out demo_${PROJECT_NAME}.c ${PROJECT_NAME}.a

run_demo:	lib demo	
	./demo_${PROJECT_NAME}.out

run_tests:	lib test
	./test_${PROJECT_NAME}.out

clean:
	@echo "Cleaning up.."
	@rm -f *.o
	@rm -f *.a
	@rm -f *.out
