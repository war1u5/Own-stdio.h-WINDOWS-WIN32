CC = cl

CFLAGS = /nologo /EHsc /MD /DDLL_EXPORTS

build: so_stdio.dll

so_stdio.dll: so_stdio.obj
	link /nologo /dll /out:so_stdio.dll /implib:so_stdio.lib $**

so_stdio.obj: so_stdio.c
	$(CC) $(CFLAGS) /Foso_stdio.obj /c $**


.PHONY:
clean:
	del *.obj *.dll

