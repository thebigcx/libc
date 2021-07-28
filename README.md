# libc
A portable C library designed for my operating system (though it can be used for yours if you port it).

## Building
Run ```make``` in the root directory, this should generate three files:
- ```libc.a```
- ```libc.so```
- ```crt0.o```

Link against either the static or shared library, and the crt0.o file (you may need to override the default linker settings).
#### Example with ld
```ld -o test test.o crt0.o -l:libc.a -nostdlib ```
