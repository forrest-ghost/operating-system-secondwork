hdrs = ipc.h
opts = -g -c
c_src = glue.c ipc.c
c_obj = glue.o ipc.o
d_src = paper.c ipc.c
d_obj = paper.o ipc.o
e_src = tobacco.c ipc.c
e_obj = tobacco.o ipc.o
f_src = provider.c ipc.c
f_obj = provider.o ipc.o
all:   glue paper tobacco provider
glue:   $(c_obj)
	gcc $(c_obj) -o glue
glue.o: $(c_src) $(hdrs)
	gcc $(opts) $(c_src)
paper: $(d_obj)
	gcc $(d_obj) -o paper
paper.o:    $(p_src) $(hdrs)
	gcc $(opts) $(d_src)
tobacco:    $(e_obj)
	gcc $(e_obj) -o tobacco
tobacco.o:      $(e_src) $(hdrs)
	gcc $(opts) $(e_src)
provider: $(f_obj)
	gcc $(f_obj) -o provider
provider.o:  $(f_src) $(hdrs)
	gcc $(opts) $(f_src)
clean:
	rm glue provider paper tobacco *.o 
