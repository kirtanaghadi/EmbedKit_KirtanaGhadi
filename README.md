# EmbedKit_KirtanaGhadi

**Author:** Kirtana Balkrishna Ghadi

## Project Description

This project implements an 8-byte circular buffer in C using the C99 standard. It supports storing and retrieving data in FIFO (First In, First Out) order.

## Modules

- **Ring Buffer (`ringbuf.c`):** Implements an 8-byte circular buffer with FIFO read/write operations and full and empty buffer checks.

## How It Works

- **Write Operation:** Stores a byte at the position indicated by `head` and increments the count.
- **Read Operation:** Retrieves a byte from the position indicated by `tail` and decrements the count.
- **Full Buffer:** Writing is rejected when the buffer contains 8 bytes.
- **Empty Buffer:** Reading is rejected when the buffer contains no bytes.
- **Index Wraparound:** Bitwise AND (`&`) is used to return the index to zero after it reaches the end of the buffer. For a buffer size of 8, `(index + 1) & (SIZE - 1)` keeps the index between 0 and 7. This method works when the buffer size is a power of 2.

## Requirements

- GCC compiler
- C99 support

## Build Instructions

Compile the program using:

```bash
gcc -Wall -std=c99 ringbuf.c -o ringbuf
```

## Run the Program

**Windows:**

```bash
ringbuf.exe
```

## Testing

The program demonstrates the following operations:

1. Write eight bytes (`0x41`–`0x48`) and verify that the buffer is full.
2. Attempt to write `0x99` when the buffer is full.
3. Read three bytes (`0x41`, `0x42`, `0x43`) in FIFO order.
4. Write three additional bytes (`0x49`, `0x4A`, `0x4B`).
5. Read all remaining bytes in FIFO order.
6. Attempt to read from the empty buffer.

## Expected Result

The program displays each read and write operation, the current number of bytes in the buffer, and appropriate messages when the buffer is full or empty.
