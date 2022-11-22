SRC:=			lsp_libc_error.c \
	    		lsp_syscall_error.c\
			lsp_pthread_error.c
OBJ:=			lsp_libc_error.o \
			lsp_syscall_error.o\
			lsp_pthread_error.o
LIBNAME_RELEASE:=	liblsp.so
LIBNAME_DEBUG:=		liblspdbg.so
INCLUDE_PATH:=		/usr/include/lsp
LIB_PATH:=		/usr/lib
LINK_LIB:=		-lc -lcrypt -lacl -lrt -lpthread -ldl

all:
	make release
	make debug

release:
	gcc -c -fPIC $(SRC)
	gcc -shared -o $(LIBNAME_RELEASE) $(OBJ) $(LINK_LIB)
debug:
	gcc -DDEBUG -c -fPIC $(SRC)
	gcc -shared -o $(LIBNAME_DEBUG) $(OBJ) $(LINK_LIB)
install:
	rm $(INCLUDE_PATH)/*.h
	rm $(LIB_PATH)/$(LIBNAME_RELEASE) $(LIB_PATH)/$(LIBNAME_DEBUG)
	cp *.h $(INCLUDE_PATH)
	cp *.so $(LIB_PATH)
clean:
	rm *.o *.so
oclean:
	rm *.o
