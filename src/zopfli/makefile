make:
	gcc *.c -O2 -W -Wall -Wextra -ansi -pedantic -lm -o zopfli

debug:
	gcc *.c -g3 -lm -o zopfli


CFLAGS = /nologo /MT /GL /O2 /W2

all: libzopfli.lib

clean:
	-del /q libzopfli.lib blocksplitter.obj cache.obj deflate.obj gzip_container.obj hash.obj katajainen.obj lz77.obj squeeze.obj tree.obj util.obj zlib_container.obj

libzopfli.lib: blocksplitter.obj cache.obj deflate.obj gzip_container.obj hash.obj katajainen.obj lz77.obj squeeze.obj tree.obj util.obj zlib_container.obj
	lib /nologo /ltcg /out:$*.lib $?
