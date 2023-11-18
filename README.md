This repo contains speed-up test for three samples optimized by pluto with:

```
pluto --dumpscop --nointratileopt --nodiamond-tile --noprevector --smartfuse --nounrolljam --noparallel --notile --rar [file.c]
```

Run `make` to see the comparison.

Now the comparsion use `clang -O3` to compile codes and `diff` to compare their results. Make sure they are installed in your PATH. 
