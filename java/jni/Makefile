Hello:
	javac Hello.java
	javah -jni Hello
	g++ -x c -I/System/Library/Frameworks/JavaVM.framework/Headers/ -c Hello.cpp
	g++ -dynamiclib -o libHello.jnilib Hello.o
clean:
	rm *.o *.class *.jnilib
