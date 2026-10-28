# EmbedKit_KirtanaGhadi

## Author
Kirtana Balkrishna Ghadi

## Project: Circular Buffer (Ring Buffer) in C

### Description
This project implements an 8-byte circular buffer in standard C (C99). It supports writing and reading data in FIFO (First In, First Out) order and handles full and empty buffer conditions.

### Features
- Fixed buffer capacity of 8 bytes.
- Write data one byte at a time.
- Read data in FIFO order.
- Prevent writing when the buffer is full.
- Prevent reading when the buffer is empty.
- Track the number of bytes stored in the buffer.
- Optimize circular indexing using bitwise AND (`&`) instead of modulo (`%`).

### Optimization
Bitwise AND can be faster than modulo on microcontrollers without a hardware divider. This technique works correctly for circular buffer indexing only when the buffer size is a power of 2, such as 2, 4, 8, or 16.

### File Structure
- `ringbuf_optimized.c` — Contains the circular buffer implementation and test program.

### Requirements
- GCC compiler
- C99-compatible compiler

### How to Compile

Run the following command in the terminal:

```bash
gcc -Wall -std=c99 ringbuf.c -o ringbuf
```

### How to Run

**Windows:**
```bash
ringbuf.exe
```


### Test Sequence
1. Write bytes `0x41` through `0x48` and confirm the buffer is full.
2. Attempt to write `0x99` and confirm the operation fails.
3. Read three bytes: `0x41`, `0x42`, and `0x43`.
4. Write three more bytes: `0x49`, `0x4A`, and `0x4B`.
5. Read all remaining bytes in FIFO order.
6. Attempt to read from the empty buffer and confirm the operation fails.

### Expected Result
The program displays the result of each read and write operation, including the current byte count and messages for full-buffer and empty-buffer conditions.
