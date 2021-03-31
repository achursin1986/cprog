all: linkedlist inotify
linkedlist: linkedlist.c
	gcc -Wall -Iinclude -O3 -march=native -ggdb -o linkedlist linkedlist.c
inotify: inotify.c
	gcc -Wall -Iinclude -O3 -march=native -ggdb -o inotify inotify.c
clean:
	rm inotify
	rm linkedlist       
