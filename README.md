mulmat
======

Framewrok of Multiply Matrices

# Build
```
$ make
```

# Test run
- 100 X 100
```
$ ./test100.sh
```

- 2000 X 2000
```
$ ./test2000.sh
```

 
# add your mulmat function
- write your function to `mulmat.c` and `mulmat.h`
```c
 void mulMat_YOURNAME(const int matsize, const double *mata, const double *matb, double *matc);
```
- call your function from `benchmul_main.c`
```c
printf("YOUR NAME:\t");
checkMulMatFunc(mulMat_YOURNAME, matsize, mata, matb, matc);
```
